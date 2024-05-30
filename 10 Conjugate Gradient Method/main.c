#include <stdio.h>
#include "gradconj.h"
#include "matriz.h"



int main(void) 
{
  int n = 10;
  double tol = 1e-7;
  double* x = vet_cria (n);
  double* b = vet_cria (n);
  double** A = mat_cria (n, n);
  
  for(int i = 0;i<n;i++){
    if(i == 0 || i == n-1){
      *(b+i) = i+1.0+0.4;
    } else {
      *(b+i) = i+1+0.8;
    }
    *(x+i) = 0;
    for(int j = 0;j<n;j++){
      if(i == j){
        *(*(A+i)+j) = (double)(i+1.0);
      } else if (i -1 == j || i+1.0 == j){
        *(*(A+i)+j) = 0.4;
      } else {
        *(*(A+i)+j) = 0;
      }
    }
  }
  printf("matriz:\n");
  mat_imprime (n, n,A);
  printf("\nvetor B:\n");
  vet_imprime (n, b);
  
  printf("\niteracoes gradconj:  %d.\n",gradconj (n,A, b, x, tol));
  printf("vetor x:\n");
  vet_imprime (n, x);

  double* x1 = vet_cria (n);

  printf("\ninteracoes gradconjJacobi: %d.\n",gradconj_jacobi (n,A,b,x1,tol));
  printf("vetor x1:\n");
  vet_imprime (n, x1);
  mat_libera (n, A);
  vet_libera (b);
  vet_libera (x);
  vet_libera(x1);
  return 0;
}