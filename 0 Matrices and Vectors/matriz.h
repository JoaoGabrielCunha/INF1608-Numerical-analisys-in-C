#ifndef MATRIZ_H
#define MATRIZ_H

// cria (aloca) uma matriz de dimensão m x n, retornando seu ponteiro;
// a matriz é representado por vetor de vetores linha
double** mat_cria (int m, int n);

// libera (a memória) de uma matriz previamente criada
void mat_libera (int m, double** A);

// preenche a matriz transposta de A em T, previamente criada;
// A tem dimensão m x n; T tem dimensão n x m
void mat_transposta (int m, int n, double **A, double** T);

// calcula o produto de uma matriz A (m x n) por um vetor v (m),
// resultando no vetor w (m), previamente criado
void mat_multv (int m, int n, double** A, double* v, double* w);

// calcula o produto de uma matriz A (m x n) por uma matriz B (n x q),
// armazenando o resultado na matriz C (m x q), previamente criada
void mat_multm (int m, int n, int q, double** A, double** B, double** C);

// imprime elementos da matriz
void mat_imprime (int m, int n, double** A);

#endif
