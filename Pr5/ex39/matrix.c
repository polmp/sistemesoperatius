#include "matrix.h"
#include <stdint.h>
#include <stdio.h>

void const_matrix(matrix m, float v){
for(int j=0;j<DIM;j++){
	for(int i=0;i<DIM;i++){
		m[i][j]=v;
	}
}
}

void print_matrix(const matrix a){
	fprintf(stdout,"Matriu de %d x %d\n",DIM,DIM);
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

