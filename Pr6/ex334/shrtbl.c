#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include "shrtbl.h"

static apuntador_llista addr;
static int fd;

void init_table(void){
printf("HOLA");
}

int add_party(const char id[]){
	for(int i=0;i<NPARTITS;i++){
		if(!strcmp(&addr->partits[i].id,id)){
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
				addr->partits[i].id = id;
				return OK;
		}

	}
}

void del_party(const char id[]){
	for(int i=0;i<NPARTITS;i++){
		if(!strcmp(&addr->partits[i].id,id)){
			addr->partits[i].enTaula = false;
			break;
		}
	}

}

void inc_votes(const char id[], int votes){
	bool trobat = false;
	for(int i=0;i<NPARTITS;i++){
		if((!strcmp(&addr->partits[i].id,id)) && addr->partits[i].enTaula){
			addr->partits[i].numvots+=votes;
			trobat = true;
			break;
		}
	}

	if(trobat){
		return OK;
	}
	else{
		return ERR;
	}

}

int get_votes(const char id[]){
	bool trobat = false;
	int valor;
	for(int i=0;i<NPARTITS;i++){
		if((!strcmp(&addr->partits[i].id,id)) && addr->partits[i].enTaula){
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
}


int get_nparties(void){
	int nombpartits=0;
	for(int i=0;i<NPARTITS;i++){
		if(addr->partits[i].enTaula){
			nombpartits++;
		}
	}
	return nombpartits;
}

void traverse(travapp *const f, void *const data){
	for(int i=0,i<NPARTITS;i++){
		f(addr->partits[i].id,addr->partits[i].numvots,data);
	}
}


int bind_shared_table(void){
	addr=mmap(NULL,sizeof(taula_partits),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0); //Mapejem a memòria
	if(addr==MAP_FAILED) return ERR;
	return OK;
}

int create_shared_table(void){
	fd=shm_open("memcompartida",O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);

	if(fd==-1) {
		fprintf(stderr,"CAN'T CREATE SM");
		return ERR;
	}

	if(ftruncate(fd,sizeof(taula_partits) == -1)) {
		fprintf(stderr,"CAN'T TRUNCATE");
		return ERR;
	}

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



int main(void){

	
	//Llista LlistaPartits;
	
	return 0;
}
