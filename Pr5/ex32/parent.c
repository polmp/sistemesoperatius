#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>

int main(void){
  pid_t llistapid[4];
  pid_t proces;
  int i=0;
  while(i<4){
    //printf("Comenso amb 0 ? %d\n", i);
    if(i!=3){
      proces=fork();
    }
    else{
      proces=-1;
    }

    if(proces<0){ //Error
      fprintf(stderr,"Error en crear el fork\n");
      i--;
      while((i--)>=0){
        kill(llistapid[i],SIGTERM);
      }
      exit(-1);
    }

    else if(proces!=0){ //Soc el pare
      printf("Soc el papi amb PID %d i el meu fill es %d\n",getpid(),proces);
      llistapid[i] = proces; //Guardem el valor a la llista de PIDS
      printf("%d PID de la llista %d\n",i, llistapid[i]);
      wait(NULL);
    }
    else{ //Soc el FILL
      printf("Soc el proces numero %d amb PID %d\n",i,getpid());
      break;
    }
    i++;
  }


  return 0;
}
