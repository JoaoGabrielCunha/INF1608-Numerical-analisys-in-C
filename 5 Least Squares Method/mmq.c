#include<stdio.h>
#include <stdlib.h>
#include <math.h>
// Lab0

double* vet_cria (int n)
{
  double* v = (double*)malloc(n*sizeof(double));
  return v;
}

void vet_libera (double* v)
{
  free(v);
}



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
// Lab 3 Funções para resolver o sistema linear.

void trocar_linhas(double **A, double *b, int linha1, int linha2, int n)
{
  double* temp = A[linha1];
  A[linha1] = A[linha2];
  A[linha2] = temp;

  double temp_b = b[linha1];
  b[linha1]= b[linha2];
  b[linha2] = temp_b;

}


void gauss(int n, double** A, double* b, double* x) {
    // Implementação do método de eliminação de Gauss com pivotamento

    // Fase de eliminação
    for (int k = 0; k < n-1; ++k) {
        // Pivoteamento parcial: encontra o pivô máximo
        int linha_pivo = k;
        double valor_pivo = fabs(A[k][k]);
        for (int i = k+1; i < n; ++i) {
            if (fabs(A[i][k]) > valor_pivo) {
                linha_pivo = i;
                valor_pivo = fabs(A[i][k]);
            }
        }
        // Troca a linha atual com a linha do pivô máximo
        if (linha_pivo != k) {
            trocar_linhas(A, b, k, linha_pivo, n);
        }

        // Eliminação gaussiana
        for (int i = k+1; i < n; ++i) {
            double fator = A[i][k] / A[k][k];
            for (int j = k; j < n; ++j) {
                A[i][j] -= fator * A[k][j];
            }
            b[i] -= fator * b[k];
        }
    }

    // Fase de substituição regressiva
    for (int i = n-1; i >= 0; --i) {
        x[i] = b[i];
        for (int j = i+1; j < n; ++j) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }
}










//1a)

double mmq(int m,int n, double**A, double*b, double* x){


  double** At = mat_cria(n, m); // Matriz transposta de A
  double** AtA = mat_cria(n, n); // Produto A^T * A
  double* Atb = (double*)malloc(n * sizeof(double)); // Produto A^T * b
  double norma_residuo;

  // Passo 1: Calcular a transposta de A
  mat_transposta(m, n, A, At);

  // Passo 2: Multiplicar A^T por A
  mat_multm(n, m, n, At, A, AtA);

  // Passo 3: Multiplicar A^T por b
  mat_multv(n, m, At, b, Atb);

  // Passo 4: Resolver o sistema AtA * x = Atb utilizando um método adequado (não implementado aqui)
  
  gauss(n,AtA,Atb,x);
  
 //Passo 5
  double* Ax = vet_cria(m);
  mat_multv(m, n, A, x, Ax);

  // Calcular a diferença entre b e A * x
  for (int i = 0; i < m; i++) {
      Ax[i] = b[i] - Ax[i];
  }

  // Calcular a norma-2 do vetor resíduo
  norma_residuo = 0.0;
  for (int i = 0; i < m; i++) {
      norma_residuo += Ax[i] * Ax[i];
  }
  norma_residuo = sqrt(norma_residuo);

  // Liberar memória alocada
  mat_libera(n, At);
  mat_libera(n, AtA);
  free(Atb);
  free(Ax);

  return norma_residuo;
  
  
}

//1b)


double ajuste_parabola(int n, double* px, double* py, double* a, double* b, double* c) {
    double** A = mat_cria(n, 3); // Matriz para armazenar os coeficientes dos termos a, b e c
    double* b_vector = vet_cria(n); // Vetor b (valores de y)

    // Preencher a matriz A e o vetor b
    for (int i = 0; i < n; i++) {
        A[i][0] = 1.0; 
        A[i][1] = px[i]; 
        A[i][2] = px[i] * px[i]; 
        b_vector[i] = py[i]; 
    }

  
    double* coeficientes = vet_cria(3); // Vetor para armazenar os coeficientes a, b e c
    double erro = mmq(n, 3, A, b_vector, coeficientes);

    // Preencher os coeficientes a, b e c
    *a = coeficientes[0];
    *b = coeficientes[1];
    *c = coeficientes[2];

   
    mat_libera(n, A);
    vet_libera(b_vector);
    vet_libera(coeficientes);

    return erro;
}



double ajuste_cubica(int n, double* px, double* py, double* a, double* b, double* c, double* d) {
    double** A = mat_cria(n, 4); // Matriz para armazenar os coeficientes dos termos a, b, c e d
    double* b_vector = vet_cria(n); // Vetor b (valores de y)

    // Preencher a matriz A e o vetor b
    for (int i = 0; i < n; i++) {
        A[i][0] = 1.0; 
        A[i][1] = px[i]; 
        A[i][2] = px[i] * px[i]; 
        A[i][3] = px[i] * px[i] * px[i]; 
        b_vector[i] = py[i]; 
    }


    double* coeficientes = vet_cria(4); // Vetor para armazenar os coeficientes a, b, c e d
    double erro = mmq(n, 4, A, b_vector, coeficientes);

    *a = coeficientes[0];
    *b = coeficientes[1];
    *c = coeficientes[2];
    *d = coeficientes[3];


    mat_libera(n, A);
    vet_libera(b_vector);
    vet_libera(coeficientes);

    return erro;
}
