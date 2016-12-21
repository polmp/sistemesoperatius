#include "shrtbl.h"
#include <stdlib.h>
#include <string.h>
/*

*/
int main(int argc,char *argv[]){
	if(!strcmp("new",argv[1])){
		add_party(argv[2]);
	}
	else if(!strcmp("add",argv[1])){
		inc_votes(argv[2],atoi(argv[3]));
	}
	return 0;
}
