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


int main(void){
float m1[DIM][DIM];
float m2[DIM][DIM];
float m3[DIM][DIM];
const_matrix(m1,5);
const_matrix(m2,3);
print_matrix(m2);
return 0;
}
