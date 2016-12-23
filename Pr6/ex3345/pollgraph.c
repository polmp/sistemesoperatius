#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdbool.h>
#include <signal.h>
#include "shrtbl.h"


static volatile bool is_end = false;
static FILE * pipegnu;

void controlc(int sig){ 
	is_end = true;
}

void grafic_init(void){
fprintf(pipegnu,"%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n","clear","reset","unset key","set xtics rotate out","set style data histogram","set style fill solid border","set boxwidth 0.95 relative","set style histogram rowstacked","set offsets graph -0.1,-0.5,0,0","set xlabel \"partits\"","set ylabel \"Vots (percentatge)\"","plot '-' using 2:xticlabel(1) lt rgb \"#66FF66\"");
fflush(pipegnu);
}

void printagrafic(const char *const id, int votes, void *const data){
	fprintf(pipegnu,"%s %d\n",id,votes);
	fflush(pipegnu);
}



int main(void){
	pid_t proces;
	pipegnu = popen ("gnuplot","w");

	if(create_shared_table() == ERR){ //Iniciem la memoria compartida
		printf("RIP\n"); 
		exit(EXIT_FAILURE);
	}
	else{
		printf("Memory OK\n");
	}

	if(bind_shared_table() == ERR){
		printf("RIP BIND\n");
		remove_shared_table();
		exit(EXIT_FAILURE);
	}
	else{
		printf("BIND OK\n");
	}
	
	signal(SIGINT, controlc); 
	init_table();
	while(get_nparties() == 0) sleep(4);
	grafic_init();
	traverse(printagrafic,NULL);
  	fprintf(pipegnu,"e\n");
  	fflush(pipegnu);
	
	while(!is_end){
		sleep(4);
		fprintf(pipegnu,"%s\n","replot");
		fflush(pipegnu);
	}
	
	pclose(pipegnu);

		
	
	return 0;
}

