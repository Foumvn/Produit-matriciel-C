#include<stdio.h>
#include "produit_matriciel.h"
void *produit_matriciel_ligne(void *arg);
int main( int argc, char*argv[])
{   


   int dimension=atoi(argv[1]);
   DIM=dimension;
   pthread_t tid[NUMTHRDS];
    long j,k;
    //generation des matrices
   matrixA=allocate_matrix(dimension);
   matrixB=allocate_matrix(dimension);
   matrixC=allocate_matrix(dimension);
   generate_matrix_values(matrixA,dimension);
   generate_matrix_values(matrixB,dimension);
   generate_matrix_values(matrixC,dimension);
  for(j=0;j<=NUMTHRDS-1;j++){
  printf("Thread file %ld\n",j);
  pthread_create(&tid[j],NULL,produit_matriciel_ligne,(void*)j);
  }
  for(j=0;j<=NUMTHRDS-1;j++){
  printf("Attendre %ld\n",j);
  pthread_join(tid[j],NULL);
  }
  printf("\n\nMatrice A");
   print_matrix(matrixA,dimension);
   printf("\n\nMatrice B");
   print_matrix(matrixB,dimension);
   printf("\n\nMatrice C");		
   print_matrix(matrixC,dimension);
   return 0;
}

void *produit_matriciel_ligne(void *arg){
    int debut, fin,i,j,k;
     long indice=(long)arg;
    debut=(indice*dimension)/NUMTHRDS;
    fin=(((indice+1)*DIM)/NUMTHRDS);
    for(i=debut; i<fin;i++){
       for(j=0; j<DIM;j++){
         matrixC[i][j]=0;
         for(k=0; k<DIM;k++){
            matrixC[i][j]+=matrixA[i][k]*matrixB[k][j];
         }
       
         }
    }
    pthread_exit(NULL);
 }


