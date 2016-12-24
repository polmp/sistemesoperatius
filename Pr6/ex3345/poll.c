#include "shrtbl.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/*

*/
int main(int argc,char *argv[]){
	if(bind_shared_table() != ERR){
		if(!strcmp("new",argv[1])){
			if(add_party(argv[2]) == ERR)
				printf("Ja existeix!\n");
			else{
				printf("Afegit %s\n",argv[2]);
			}
				
		}
		else if(!strcmp("add",argv[1])){
			inc_votes(argv[2],atoi(argv[3]));
		}
	}

	else{
		fprintf(stderr,"BIND ERROR\n");

	}
	
	return 0;
}
