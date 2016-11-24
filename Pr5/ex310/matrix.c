#include "matrix.h"
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

int returncolumns(char line[]){
	int i=-1;
	int count=0;
	while(line[++i]){
   		if(line[i] == ',') count++;
	}  
	return count+1;
}

int save_matrix(const char filename[],const matrix m){
	FILE *f=fopen(filename,"w");
	if(f==NULL){
		fprintf(stderr,"Error opening the file");
		exit(EXIT_FAILURE);
	}

	for(int i=0;i<DIM;i++){
		for(int j=0;j<DIM;j++){
			if(j==(DIM-1)){
				fprintf(f,"%f",m[i][j]);
			}
			else{
				fprintf(f,"%f,",m[i][j]);
			}
			
		}
		fprintf(f,"\n");
	}
	fclose(f);
	return 1;	
}

int load_matrix(const char filename[],matrix m){
	FILE *f=fopen(filename,"r");
	if(f==NULL){
		fprintf(stderr,"Error opening the file");
		exit(EXIT_FAILURE);
	}
	for(int j=0;j<DIM;j++){
		for(int i=0;i<DIM;i++){
			fscanf(f,"%f,",&m[j][i]);
		}
	}
	fclose(f);
	return 1;

}



void const_matrix(matrix m, float v){
for(int j=0;j<DIM;j++){
	for(int i=0;i<DIM;i++){
		m[i][j]=v;
	}
}
}

void print_matrix(const matrix a){
	fprintf(stdout,"Matrix %d x %d\n",DIM,DIM);
	for(int i=0;i<DIM;i++){
		for(int j=0;j<DIM;j++){
			if(j!=DIM-1){
				fprintf(stdout,"%f ",a[i][j]);
			}
			else{
				fprintf(stdout,"%f",a[i][j]);
			
			}
		}
	fprintf(stdout,"\n");
	}

}

void prod_matrix(const matrix a, const matrix b, matrix r, int minf, int maxf, int minc, int maxc){
	if((maxf-minf) == (maxc-minc)){
		for(int i=minf-1;i<maxf;i++){
			for(int j=minc-1;j<maxc;j++){
				for(int index=0;index<DIM;index++){
					r[i][j]+=a[i][index]*b[index][j];
				
				}
		
			}
	
		}
	}

	else{
		fprintf(stderr,"Error in parameters");
	}
	
}

