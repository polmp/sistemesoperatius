#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(void){
  pid_t llistapid[4];
  pid_t proces;
  int i=0;
  while(i++<4){
    if((proces=fork())<0){ //Error
      perror("ERROR");
      exit(-1);
    }

    else if(proces!=0){ //Soc el pare
      //printf("Soc el papi amb PID %d i el meu fill es %d\n",getpid(),proces);
      llistapid[i] = proces; //Guardem el valor a la llista de PIDS
      wait(NULL);
    }
    else{ //Soc el FILL
      printf("Soc el proces numero %d amb PID %d\n",i,getpid());
      break;
    }
  }

  return 0;
}
