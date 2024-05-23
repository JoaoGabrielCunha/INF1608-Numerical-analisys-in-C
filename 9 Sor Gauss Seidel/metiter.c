#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>



int gauss_seidel(int n, double **A, double *b, double *x, double tol)
{
  int cont = 0;
  int i, j;
  double *r = vet_cria(n);
  double *vetaux = vet_cria(n);
  
  do {
    for (i = 0; i < n; i++) 
    {
      double temp = 0.0;
      for (j = 0; j < n; j++) 
      {
        if (j != i) 
        {
          temp += (A[i][j]) * x[j];
        }
      }
      x[i] = ((b[i] - temp) / A[i][i]);
    }
    cont++;
    mat_multv(n, n, A, x, vetaux);
    for (i = 0; i < n; i++) {
      r[i] = b[i] - vetaux[i];
    }
    double norm = vet_norma2(n, r);
    if (norm <= tol) {
      break;
    }
  } while (1);
  
  vet_libera(r);
  vet_libera(vetaux);
  return cont;
}

int sor_gauss_seidel(int n, double **A, double *b, double *x, double tol,
                     double w) 
{
  int cont = 0;
  int i, j;
  double *r = vet_cria(n);
  double *vetaux = vet_cria(n);
  double aux;
  do
    {
    for (i = 0; i < n; i++) 
    {
      vetaux[i] = x[i];
      double temp = 0.0;
      for (j = 0; j < n; j++) 
      {
        if (j != i) {
          temp += (A[i][j]) * x[j];
        }
      }
      x[i] = (b[i] - temp) / A[i][i];
    }
    for (int i = 0; i < n; i++) 
    {
      x[i] = (1 - w) * vetaux[i] + w * x[i];
    }
    mat_multv(n, n, A, x, vetaux);
    for (int i = 0; i < n; i++)
    {
      r[i] = b[i] - vetaux[i];
    }
    cont++;

    double norm = vet_norma2(n, r);
    if (norm <= tol) 
    {
      break;
    }
  } while (1);

  vet_libera(r);
  vet_libera(vetaux);
  return cont;
}
