#include "matriz.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double** mat_cria (int m, int n)
{
  double** A = (double**) malloc(m*sizeof(double*));
  for (int i=0; i<m; ++i)
    A[i] = (double*) malloc(n*sizeof(double));
  return A;
}

void mat_libera (int m, double** A)
{
  for (int i=0; i<m; ++i)
    free(A[i]);
  free(A);
}

void mat_imprime (int m, int n, double** A)
{
  for (int i=0; i<m; ++i) {
    for (int j=0; j<n; ++j) {
      printf("%.16g  ", A[i][j]);
    }
    printf("\n");
  }
}


void mat_transposta (int m, int n, double **A, double** T){
  for (int i=0; i<n ;++i){
    for(int j=0;j<m;++j) {
     T[i][j]  = A[j][i];
    }    
  }
}

void mat_multv (int m, int n, double** A, double* v, double* w){
  for(int i=0; i<m;++i){
    w[i]=0;
    for(int j=0;j<n;++j)
      w[i]+= A[i][j]*v[j];
  }
}

void mat_multm(int m, int n, int q, double** A, double** B, double** C) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < q; ++j) {
            C[i][j] = 0.0; // Inicializa o elemento C[i][j]
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j]; // Calcula o produto das linhas de A pelos elementos correspondentes de B
            }
        }
    }
}