#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(void){
	pid_t proces;
	FILE * pipegnu = popen ("gnuplot","w");
	proces = fork();
	if(proces < 0){
		fflush(pipegnu);
		fprintf(pipegnu,"%s","exit");
		exit(EXIT_FAILURE);
	}

	else if (proces != 0){	
		//Som el pare
		fprintf(pipegnu,"%s\n","load 'ex31.gnu'");
		fflush(pipegnu);

		while(1){
			sleep(4);
			printf("Actualitzant...");
			fprintf(pipegnu,"%s\n","replot");
			fflush(pipegnu);

		}
		
	}
	return 0;
}

