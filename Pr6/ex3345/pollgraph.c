#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include "shrtbl.h"


void grafic_init(FILE * pipegnu){
fprintf(pipegnu,"%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n","clear","reset","unset key","set xtics rotate out","set style data histogram","set style fill solid border","set boxwidth 0.95 relative","set style histogram rowstacked","set offsets graph -0.1,-0.5,0,0","plot '-' using 2:xticlabel(1) lt rgb \"#66FF66\"","set xlabel \"partits\"","set ylabel \"Vots (percentatge)\"");
fflush(pipegnu);
}

int main(void){
	pid_t proces;
	FILE * pipegnu = popen ("gnuplot","w");
	proces = fork();
	if(proces < 0){
		fflush(pipegnu);
		fprintf(pipegnu,"%s","exit");
		exit(EXIT_FAILURE);
	}

	else if (proces != 0){ //Som el pare	
		if(create_shared_table() == ERR) //Iniciem la memoria compartida
			exit(EXIT_FAILURE);
		if(bind_shared_table() == ERR)
			remove_shared_table();
			exit(EXIT_FAILURE);
		init_table();
		grafic_init(pipegnu);
		while(1){
			sleep(4);
			fprintf(pipegnu,"%s\n","replot");
			fflush(pipegnu);
		}
		
	}
	return 0;
}

