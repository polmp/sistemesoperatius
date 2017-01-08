#include "shrtbl.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/*

*/
int main(int argc,char *argv[]){
	if(bind_shared_table() != ERR && argc > 1){
		if(!strcmp("new",argv[1]) && argc > 2){
			if(add_party(argv[2]) == ERR)
				printf("Ja existeix!\n");
			else
				printf("Afegit %s\n",argv[2]);
			
				
		}
		else if(!strcmp("add",argv[1]) && argc > 3){
			
			if(!atoi(argv[3])){
				printf("Error en el nombre de vots!\n");
			}
			else{
				inc_votes(argv[2],atoi(argv[3]));
			}
		}
	}

	else{
		fprintf(stderr,"BIND ERROR or not enough parameters specified\n");

	}
	
	return 0;
}
