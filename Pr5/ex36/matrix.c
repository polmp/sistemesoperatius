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
	for(int j=0;j<DIM;j++){
		for(int i=0;i<DIM;i++){
			if(i!=DIM-1){
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
for(int i=minf-1;i<maxf;i++){
	for(int j=minc-1;j<maxc;j++){
		r[i][j]=a[i][j]*b[i][j]
		
	}
}
}


int main(void){
float m1[DIM][DIM];
float m2[DIM][DIM];
float mr[DIM][DIM];
const_matrix(m1,5);
const_matrix(m2,3);
const_matrix(mr,0);
print_matrix(m2);
return 0;
}
