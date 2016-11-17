#ifndef MATRIX_H
#define MATRIX_H

/* dimensio de la matriu */
#define DIM 3

/* espai que ocupa una matriu */
#define SIZE (DIM*DIM*sizeof(float))

/* el tipus matriu */
typedef float (* const matrix) [DIM];

/* escriu pel canal de sortida la matriu 'a' */
void print_matrix(const matrix a);

/* calcula el producte parcial de matrius seguent:
 * r[minf,maxf;minc,maxc] = a[minf,maxf;] x b[;minc,maxc]
 */
void prod_matrix(const matrix a, const matrix b, matrix r, int minf, int maxf, int minc, int maxc);

/* omple 'm' amb el valor 'v' */
void const_matrix(matrix m, float v);
#endif
