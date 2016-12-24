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
	
	fprintf(pipegnu,"clear\n");
	fprintf(pipegnu,"reset\n");
	fprintf(pipegnu,"unset key\n");
	fflush(pipegnu);
	fprintf(pipegnu,"set xtics rotate out\n");
	fprintf(pipegnu,"set style data histogram\n");
	fprintf(pipegnu,"set style fill solid border\n");
	fprintf(pipegnu,"set boxwidth 0.95 relative\n");
	fprintf(pipegnu,"set style histogram rowstacked\n");
	fprintf(pipegnu,"set offsets graph -0.1,-0.5, 0, 0\n");
	fprintf(pipegnu,"set yrange [0:100]\n");
	fprintf(pipegnu,"set xlabel \"Agrupacions\"\n");
	fprintf(pipegnu,"set ylabel \"Vots (percentatge)\"\n");
}

void dadesgrafic(const char *const id, int votes, void *const data){
	fprintf(stderr,"Parametres: %s %d\n",id,votes);
	fprintf(pipegnu,"\"%s\" %d\n",id,votes);
	fflush(pipegnu);
}

void update(void){
fprintf(pipegnu,"replot\n");
fflush(pipegnu);
if (get_nparties() > 0)
	traverse(dadesgrafic,NULL);
fprintf(pipegnu,"e\n");
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
	while(!get_nparties()) sleep(4);
	grafic_init();
	fprintf(pipegnu,"plot '-' using 2:xticlabel(1) lt rgb \"#66FF66\"\n");
	fflush(pipegnu);
	traverse(dadesgrafic,NULL);
  	fprintf(pipegnu,"e\n");
	fflush(pipegnu);
	
	while(!is_end){
		sleep(4);
		update();
		fprintf(pipegnu,"%s\n","replot");
		fflush(pipegnu);
	}
	printf("Borrada memoria compartida\n");
	remove_shared_table();
	
	pclose(pipegnu);

		
	
	return 0;
}

