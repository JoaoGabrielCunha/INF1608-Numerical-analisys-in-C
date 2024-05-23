#include "matriz.h"
#include "metiter.h"
#include <stdio.h>

int main(void)
{
  
  int n = 2;
  double tol = 1e-7;            
  double w = 1.1;
  double *vet = vet_cria(n);
  vet[0] = 5;
  vet[1] = 5;
  double *vetx = vet_cria(n);
  vetx[0] = 0;
  vetx[1] = 0;
  double **matriz = mat_cria(n, n);
  matriz[0][0] = 3;
  matriz[0][1] = 1;
  matriz[1][0] = 1;
  matriz[1][1] = 2;
  int num = gauss_seidel(n, matriz, vet, vetx, tol);

  printf("Para o primeiro sistema:\n\n");
  printf("Numero de iteracoes: %d\n", num);
  printf("Soluções x1,x2: ");
  vet_imprime(n, vetx);
  printf("\n");
  vetx[0] = 0;
  vetx[1] = 0;

  num = sor_gauss_seidel(n, matriz, vet, vetx, tol, w);
  printf("Numero de iteracoes com relaxamento: %d\n", num);
  printf("Soluções x1,x2: ");
  vet_imprime(n, vetx);
  printf("\n");

  int n2 = 6;
  double **matriz2 = mat_cria(n2, n2);
  matriz2[0][0] = 3;
  matriz2[0][1] = -1;
  matriz2[0][2] = 0;
  matriz2[0][3] = 0;
  matriz2[0][4] = 0;
  matriz2[0][5] = 0.5;
  matriz2[1][0] = -1;
  matriz2[1][1] = 3;
  matriz2[1][2] = -1;
  matriz2[1][3] = 0;
  matriz2[1][4] = 0.5;
  matriz2[1][5] = 0;
  matriz2[2][0] = 0;
  matriz2[2][1] = -1;
  matriz2[2][2] = 3;
  matriz2[2][3] = -1;
  matriz2[2][4] = 0;
  matriz2[2][5] = 0;
  matriz2[3][0] = 0;
  matriz2[3][1] = 0;
  matriz2[3][2] = -1;
  matriz2[3][3] = 3;
  matriz2[3][4] = -1;
  matriz2[3][5] = 0;
  matriz2[4][0] = 0;
  matriz2[4][1] = 0.5;
  matriz2[4][2] = 0;
  matriz2[4][3] = -1;
  matriz2[4][4] = 3;
  matriz2[4][5] = -1;
  matriz2[5][0] = 0.5;
  matriz2[5][1] = 0;
  matriz2[5][2] = 0;
  matriz2[5][3] = 0;
  matriz2[5][4] = -1;
  matriz2[5][5] = 3;
  double *vet2 = vet_cria(n2);
  vet2[0] = 2.5;
  vet2[1] = 1.5;
  vet2[2] = 1;
  vet2[3] = 1;
  vet2[4] = 1.5;
  vet2[5] = 2.5;
  double *vetx2 = vet_cria(n2);
  for (int i = 0; i < n2; i++) {
    vetx2[i] = 0;
  }
  
  int num2 = gauss_seidel(n2, matriz2, vet2, vetx2, tol);
  printf("\n\n\nPara o segundo sistema:\n\n");
  printf("Numero de iteracoes: %d\n", num2);
  printf("Soluções: x1,x2,x3,x4,x5,x6 :");
  vet_imprime(n2, vetx2);
  printf("\n");
  for (int i = 0; i < n2; i++) {
    vetx2[i] = 0;
  }
  num2 = sor_gauss_seidel(n, matriz2, vet2, vetx2, tol, w);
  printf("Num de iteracoes com relaxamento: %d \n", num2);
  printf("Soluções: x1,x2,x3,x4,x5,x6 :");
  vet_imprime(n2, vetx2);
  printf("\n");
  mat_libera(n, matriz);
  vet_libera(vetx);
  vet_libera(vet);
  mat_libera(n2, matriz2);
  vet_libera(vetx2);
  vet_libera(vet2);
}