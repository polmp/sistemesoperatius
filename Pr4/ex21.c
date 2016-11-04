#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>


int main(int argc, char *argv[]){
	struct dirent *llegirdad;
	DIR *directori;
	char cwd[1024];
	if(argc == 1)
		getcwd(cwd, sizeof(cwd));
	else
		strcpy(cwd, argv[1]);
	
	if ((directori=opendir(cwd)) != NULL){
		printf("Obert directori %s\n",cwd);
		while((llegirdad=readdir(directori))!=NULL)
			if((llegirdad->d_name)[0] != '.')
				printf("%s\n",llegirdad->d_name);
		
	closedir(directori);
	}
	else
		printf("El directori %s no s'ha pogut obrir!\n",argv[1]);
 	
	return 0;
}