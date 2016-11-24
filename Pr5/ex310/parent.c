#define _POSIX_C_SOURCE 200809L
#define DEBUGGER 0
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "matrix.h"

void convertchild(char * nombrechild, char nombre){
nombrechild[0] = 'c';
nombrechild[1] = 'h';
nombrechild[2] = 'i';
nombrechild[3] = 'l';
nombrechild[4] = 'd';
nombrechild[5] = nombre;
nombrechild[6]='\0';
} 

int main(int argc, char *argv[]){
	pid_t llistapid[4];
	pid_t proces;
	char nombre;
	char nombrechild[7];
	int childstate;
	int i=0;
	int fd;
	void *addr;

	if(argc==4){

		fd=shm_open(FILESHM,O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);
		if(fd==-1) {
			fprintf(stderr,"CAN'T CREATE SM");
			exit(EXIT_FAILURE);
		}; //Si no podem crear regio de memoria compartida, sortim
		if(ftruncate(fd,3*SIZE) == -1) {
			fprintf(stderr,"CAN'T TRUNCATE");
			exit(EXIT_FAILURE);
		}
		addr=mmap(NULL,3*SIZE,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0); //Mapejem a memòria
		if(addr==MAP_FAILED) exit(EXIT_FAILURE);
		close(fd);

		matrix A = addr;
		matrix B = addr + SIZE;
		matrix R = addr + SIZE*2;
		
		//Carreguem les dues matrius a A i B respectivament
		load_matrix(argv[1],A);
		//print_matrix(A);
		load_matrix(argv[2],B);
			
		
		//const_matrix(R,0); //Fiquem a la zona de memòria la matriu inicialitzada a 0
		/*printf("MATRIX A:\n");
		print_matrix(A);
		printf("MATRIX B:\n");
		print_matrix(B);
		*/
		

		while(i++<4){
			if((proces=fork())<0){
				shm_unlink(FILESHM);
				exit(EXIT_FAILURE);
	    		}

	    		else if(proces!=0){ 
				llistapid[i] = proces; 
				wait(&childstate);
				if(!WIFEXITED(childstate)){ //Si entrem aqui, el programa no ha acabat correctament
					fprintf(stderr,"PROCESS WITH PID %d FAILED",proces);
					shm_unlink(FILESHM);
					exit(EXIT_FAILURE);
				}
			
				#if DEBUGGER
					printf("Sortida: %d\n",WEXITSTATUS(childstate));
				#endif
	    		}
	   		else{
				//printf("Soc el proces numero %d amb PID %d\n",i,getpid());
				sprintf(&nombre,"%d",i);
				convertchild(nombrechild,nombre);
				execlp("./child",nombrechild,FILESHM,&nombre,NULL);
	      			break;
	    		}
	  	}
	
		save_matrix(argv[3],R);
		printf("MATRIX SAVED TO %s\n",argv[3]);

		
		}

	else{
		printf("USAGE:\n./parent matA.dat matB.dat matR.dat\n");
	}
	
	shm_unlink(FILESHM); //Acabem la memòria compartida
	return 0;
}
