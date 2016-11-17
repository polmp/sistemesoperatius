#include "matrix.h"

int main(void){
	float m1[DIM][DIM];
	float m2[DIM][DIM];
	float mr[DIM][DIM];
	const_matrix(m1,5);
	save_matrix("ola.dat",m1);
	const_matrix(m2,3);
	const_matrix(mr,0);
	m1[0][1]=7;
	m1[0][2]=8;
	m2[0][1]=2;
	prod_matrix(m1,m2,mr,1,4,1,4);
	print_matrix(m1);
	print_matrix(m2);
	print_matrix(mr);
	return 0;
}
