#include<stdio.h>
#include "produit_matriciel.h"

//T=nombre de thread
//le threead k va traiter les ligne qui sont telles que i mod T=k
matrix_t allocate_matrix(int dimension)
{
	matrix_t mat ;
	int i;
	mat = (double**)malloc(sizeof(double)*dimension);
	
	for(i=0;i<dimension;i++)
	{
		mat[i] = (double*)malloc(sizeof(double)*dimension);
	}

	return mat;	
}

void print_matrix(matrix_t mat ,int dimension){
        int i,j;
        for(i=0; i<dimension;i++){
          printf("\n");
           for(j=0; j<dimension;j++){
           printf("%f\t",mat[i][j]);
           }
        }
}

void generate_matrix_values(matrix_t mat,int dimension){
       int i,j;
       for(i=0; i<dimension;i++){
           for(j=0; j<dimension;j++){
           mat[i][j]=rand()%MAX_VAL+MIN_VAL;
           }
        }
}
void matrice_multiplication(matrix_t matrixA,matrix_t matrixB,matrix_t matrixC,int dimension){
   for(int i=0;i<dimension;i++){
      for(int j=0;j<dimension;j++){
            matrixC[i][j]=0;
         for(int k=0;k<dimension;k++){
              matrixC[i][j]+=matrixA[i][k]*matrixB[k][j];
         }
      }
}
}


























