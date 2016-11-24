#include "matrix.h"
#include <stdio.h>

int main(void){
	float m1[DIM][DIM];
	float m2[DIM][DIM];
	float mr[DIM][DIM];
	const_matrix(mr,0);
	load_matrix("matA.dat",m1);
	//print_matrix(m1);
	load_matrix("matB.dat",m2);
	//print_matrix(m2);
	prod_matrix(m1,m2,mr,1,DIM,1,DIM);
	printf("\n\n\nRESULTAT:");
	print_matrix(mr);
	save_matrix("matResultat.dat",mr);
	//print_matrix(mr);
	//const_matrix(m2,5);
	return 0;
	/*
	const_matrix(m2,3);
	const_matrix(mr,0);
	prod_matrix(m1,m2,mr,1,4,1,4);
	print_matrix(m1);
	print_matrix(m2);
	print_matrix(mr);
	return 0;
	*/
}
