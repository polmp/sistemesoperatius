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
	for(int i=minf-1;i<maxf;i++){
		for(int j=minc-1;j<maxc;j++){
			for(int index=0;index<DIM-1;index++){
				printf("%d\n",index-1+minc);
				r[i][j]+=a[i][index-1+minc]*b[index-1+minf][j];
				
			}
		
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
m1[0][1]=7;
m1[0][2]=8;
m2[0][2]=2;
prod_matrix(m1,m2,mr,1,2,2,3);
print_matrix(m1);
print_matrix(m2);
print_matrix(mr);
return 0;
}
