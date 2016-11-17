#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/mman.h>  
#include <fcntl.h>
#include "matrix.h"


int main(int argc, char *argv[]){
	if(argc == 3){
		struct stat sb;
		int fd;
		void *addr;
		//Accedim a la memòria compartida. A argv[1] tenim el nom del fitxer
		fd=shm_open(argv[1],O_RDWR,0);
		if(fd==-1) {
			fprintf(stderr,"CAN'T CREATE SM");
			exit(EXIT_FAILURE); //Si no podem crear regio de memoria compartida, sortim
		}

		if(fstat(fd,&sb) == -1){
			fprintf(stderr,"Can't check stat");
			exit(EXIT_FAILURE);
		}

		addr=mmap(NULL,sb.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0); //Mapejem a memòria
		if(addr == MAP_FAILED){
			fprintf(stderr,"CAN'T MAP ADRESS");
			exit(EXIT_FAILURE);
		}
		matrix A = addr;
		matrix B = addr + SIZE;
		matrix R = addr + 2*SIZE;
		
		//printf("%s",argv[1]);
		/*
		for(int i=0;i<argc;i++){
			printf("%s\n",argv[i]);
		}
		*/
	}

	else{
		exit(EXIT_FAILURE);
	}
	
}
