#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double **mat_cria(int m, int n)
{
  double **A = (double **)malloc(m * sizeof(double *));
  for (int i = 0; i < m; ++i)
    A[i] = (double *)malloc(n * sizeof(double));
  return A;
}

void mat_libera(int m, double **A)
{
  for (int i = 0; i < m; ++i)
    free(A[i]);
  free(A);
}

void mat_transposta(int m, int n, double **A, double **T) 
{
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j)
      T[j][i] = A[i][j];
}

void mat_multv(int m, int n, double **A, double *v, double *w) 
{
  for (int i = 0; i < m; ++i) {
    w[i] = 0.0;
    for (int j = 0; j < n; ++j)
      w[i] += A[i][j] * v[j];
  }
}

void mat_multm(int m, int n, int q, double **A, double **B, double **C) {
  for (int i = 0; i < m; ++i)
    {
    for (int k = 0; k < q; ++k) 
    {
      C[i][k] = 0.0;
      for (int j = 0; j < n; ++j)
        C[i][k] += A[i][j] * B[j][k];
    }
  }
}

void mat_imprime(int m, int n, double **A) {
  for (int i = 0; i < m; ++i) 
  {
    for (int j = 0; j < n; ++j) 
    {
      printf("%.16g  ", A[i][j]);
    }
    printf("\n");
  }
}

double *vet_cria(int n) 
{
  double *v = (double *)malloc(n * sizeof(double));
  return v;
}

void vet_libera(double *v) { free(v); }
double myvet_escalar(int n, double *v, double *w)
{
  double s = 0;
  for (int i = 0; i < n; ++i)
    s += v[i] * w[i];
  return s;
}

double vet_norma2(int n, double *v)
{
  double s = myvet_escalar(n, v, v);
  return sqrt(s);
}

int vet_iguais(int n, double *g, double *x, double tol)
{
  for (int i = 0; i < n; ++i) 
  {
    if (fabs(g[i] - x[i]) > tol)
      return 0;
  }
  return 1;
}

void vet_mults(int n, double *v, double s, double *w)
{
  for (int i = 0; i < n; ++i)
    w[i] = v[i] * s;
}

void vet_imprime(int n, double *v)
{
  for (int i = 0; i < n; ++i)
    printf("%.16g  ", v[i]);
  printf("\n");
}