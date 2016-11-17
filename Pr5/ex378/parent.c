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

int main(void){
	pid_t llistapid[4];
	pid_t proces;
	char nombre;
	char nombrechild[7];
	int childstate;
	int i=0;

	int fd;
	void *addr;

	fd=shm_open("fitxer",O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);
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


	while(i++<4){
		if((proces=fork())<0){
			shm_unlink("fitxer");
			exit(EXIT_FAILURE);
    		}

    		else if(proces!=0){ 
			llistapid[i] = proces; 
			wait(&childstate);
			if(!WIFEXITED(childstate)){ //Si entrem aqui, el programa no ha acabat correctament
				fprintf(stderr,"Proces amb PID %d ha fallat",proces);
				shm_unlink("fitxer");
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
			execlp("./child",nombrechild,"fitxer",&nombre,NULL);
      			break;
    		}
  	}
  
  return 0;
}
