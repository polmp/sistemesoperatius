#define _POSIX_C_SOURCE 200809L
#include "shrtbl.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>
#include <fcntl.h>  /*Constants*/         
#include <sys/stat.h>

#define SEMAFOR addr->semafor

static apuntador_llista addr;
static int fd;

void init_table(void){
	SEMAFOR = sem_open("semafor", O_CREAT, S_IRUSR|S_IWUSR, 0);
	sem_wait(SEMAFOR);
	//Zona conflictiva
	for(int i=0;i<NPARTITS;i++){
		addr->partits[i].enTaula = false;
		addr->partits[i].numvots = 0;
	}
	sem_post(SEMAFOR);
	
}

int add_party(const char id[]){
	
	sem_wait(SEMAFOR);	
	for(int i=0;i<NPARTITS;i++){
		if(!strcmp(addr->partits[i].id,id)){
			if(addr->partits[i].enTaula){
				return ERR;
			}
			else{
				addr->partits[i].enTaula = true;
				return OK;
			}
		}
	}

	for(int i=0;i<NPARTITS;i++){
		if(!addr->partits[i].enTaula){
				addr->partits[i].enTaula = true;
				*(addr->partits[i].id)=id[0];
				return OK;
		}

	}
	sem_post(SEMAFOR);
	
	
}

void del_party(const char id[]){
	sem_wait(SEMAFOR);
	for(int i=0;i<NPARTITS;i++){
		if(!strcmp(addr->partits[i].id,id)){
			addr->partits[i].enTaula = false;
			break;
		}
	}
	sem_post(SEMAFOR);

}

void inc_votes(const char id[], int votes){
	sem_wait(SEMAFOR);
	for(int i=0;i<NPARTITS;i++){
		if((!strcmp(addr->partits[i].id,id)) && addr->partits[i].enTaula){
			addr->partits[i].numvots+=votes;
			break;
		}
	}
	sem_post(SEMAFOR);
}

int get_votes(const char id[]){
	sem_wait(SEMAFOR);
	bool trobat = false;
	int valor;
	for(int i=0;i<NPARTITS;i++){
		if((!strcmp(addr->partits[i].id,id)) && addr->partits[i].enTaula){
			trobat = true;
			valor = addr->partits[i].numvots;
			break;
		}
	}

	if(trobat){
		return valor;
	}
	else{
		return ERR;
	}
	sem_post(SEMAFOR);
}


int get_nparties(void){
	sem_wait(SEMAFOR);
	int nombpartits=0;
	for(int i=0;i<NPARTITS;i++){
		if(addr->partits[i].enTaula){
			nombpartits++;
		}
	}
	sem_post(SEMAFOR);
	return nombpartits;
}

void traverse(travapp *const f, void *const data){
	sem_wait(SEMAFOR);
	for(int i=0;i<NPARTITS;i++){
		f(addr->partits[i].id,addr->partits[i].numvots,data);
	}
	sem_post(SEMAFOR);
}


int bind_shared_table(void){
	fd=shm_open("memcompartida",O_RDWR,0);
	addr=mmap(NULL,sizeof(taula_partits),PROT_READ|PROT_WRITE,MAP_SHARED,fd,(off_t)0); //Mapejem a memòria
	if(addr==MAP_FAILED){
		remove_shared_table();
		return ERR;
	}
	printf("ADDR: %d\n",addr);
	close(fd);
	return OK;
}

int create_shared_table(void){
	fd=shm_open("memcompartida",O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);
	if(fd==-1) {
		fprintf(stderr,"CAN'T CREATE SM");
		return ERR;
	}

	if(ftruncate(fd,sizeof(taula_partits))==-1) {
		fprintf(stderr,"CAN'T TRUNCATE");
		remove_shared_table();
		return ERR;
	}
	printf("fd: %d\n",fd);
	close(fd);	
	return OK;
}

int remove_shared_table(void){
	if(shm_unlink("memcompartida") == -1){
		return ERR;
	}
	
	else{
		return OK;

	}
}

