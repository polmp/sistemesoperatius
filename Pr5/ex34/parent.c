#define _POSIX_C_SOURCE 200809L
#define DEBUGGER 0
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

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
	while(i++<4){
		if((proces=fork())<0){
			exit(EXIT_FAILURE);
    		}

    		else if(proces!=0){ 
			llistapid[i] = proces; 
			wait(&childstate);
			if(!WIFEXITED(childstate)){ //Si entrem aqui, el programa no ha acabat correctament
				fprintf(stderr,"Proces amb PID %d ha fallat",proces);
				exit(EXIT_FAILURE);
			}
			#if DEBUGGER
				printf("Sortida: %d\n",WEXITSTATUS(childstate));
			#endif
    		}
   		else{
			printf("Soc el proces numero %d amb PID %d\n",i,getpid());
			sprintf(&nombre,"%d",i);
			convertchild(nombrechild,nombre);
			execlp("./child",nombrechild,"pole",&nombre,NULL);
      			break;
    		}
  	}

  return 0;
}
