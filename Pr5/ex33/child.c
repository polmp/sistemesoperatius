#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
	if(argc == 4){
		for(int i=1;i<argc;i++){
			printf("%s\n",argv[i]);
		}
	}

	else{
		exit(EXIT_FAILURE);
	}
	
}
