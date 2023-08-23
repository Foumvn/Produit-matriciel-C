
#include<stdlib.h>
#include<sys/time.h>
#include<time.h>
#include <pthread.h>
#ifndef  PRODUIT_MATRICIEL_H
#define PRODUIT_MATRICIEL_H
#define MAX_VAL 15
#define MIN_VAL 0
#define NUMTHRDS 5

int DIM,dimension;
typedef double** matrix_t;
matrix_t matrixA,matrixB,matrixC;
matrix_t allocate_matrix(int dimension);
void matrice_multiplication(matrix_t matrixA,matrix_t matrixB,matrix_t matrixC,int dimension);
void generate_matrix_values(matrix_t mat,int dimension);
void print_matrix(matrix_t mat ,int dimension);

#endif
