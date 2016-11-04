#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	struct dirent *llegirdad;
	DIR *directori;
	struct stat st;
	int a;

	char cwd[1024];
	if(argc == 1)
		getcwd(cwd, sizeof(cwd));
	else
		strcpy(cwd, argv[1]);

	if ((directori=opendir(cwd)) != NULL){
		printf("Obert directori %s\n",cwd);
		while((llegirdad=readdir(directori))!=NULL){
			if((llegirdad->d_name)[0] != '.'){
				if (stat((char *)llegirdad->d_name, &st) == 0){
					printf("File %s-> Diferencia entre tamanys: %ld\n",llegirdad->d_name,(st.st_blocks*512) - st.st_size);
			}
			}
		}
		closedir(directori);
	}
	else
		printf("El directori %s no s'ha pogut obrir!\n",cwd);
 	
	return 0;
}