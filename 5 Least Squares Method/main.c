#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include"mmq.h"

int main(void) {
//2 a sistema 1)
  // Definição do sistema
  double A_data[5][3] = {
      {3, -1, 2},
      {4, 1, 0},
      {-3, 2, 1},
      {1, 1, 5},
      {-2, 0, 3}
  };

  double b_data[5] = {10, 10, -5, 15, 0};

  int m = 5; // número de equações
  int n = 3; // número de incógnitas

  // Alocação de memória para a matriz A usando mat_cria
  double** A = mat_cria(m, n);
  for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
          A[i][j] = A_data[i][j];
      }
  }

  // Alocação de memória para o vetor b usando vet_cria
  double* b = vet_cria(m);
  for (int i = 0; i < m; i++) {
      b[i] = b_data[i];
  }




  

  // Alocação de memória para o vetor de solução
  double *x = (double *)malloc(n * sizeof(double));

  // Chama a função mmq para resolver o sistema
  double erro = mmq(m, n, A, b, x);

  // Imprime a solução aproximada e o erro associado
  printf("Solução aproximada:\n");
  for (int i = 0; i < n; i++) {
      printf("x%d = %.6f\n", i + 1, x[i]);
  }
  printf("Erro associado (norma-2): %.6f\n", erro);



  mat_libera(m, A);


//2 a sistema 2)
  double A_data_2[5][4] = {
    {4, 2, 3, 0},
    {-2, 3, -1, 1},
    {1, 3, -4, 2},
    {1, 0, 1, -1},
    {3, 1, 3, -2}
  };

  double b_data_2[5] = {10, 0, 2, 0, 5};

  m = 5; // número de equações
  n = 4; // número de incógnitas

  // Alocação de memória para a matriz A usando mat_cria
  double** A_2 = mat_cria(m, n);
  for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
          A_2[i][j] = A_data_2[i][j];
      }
  }

  // Alocação de memória para o vetor b usando vet_cria
  double* b_2 = vet_cria(m);
  for (int i = 0; i < m; i++) {
      b_2[i] = b_data_2[i];
  }

  // Alocação de memória para o vetor de solução usando vet_cria
  double* x_2 = vet_cria(n);

  // Chama a função mmq para resolver o sistema
  double erro_2 = mmq(m,n, A_2, b_2, x_2);

  
  // Imprime a solução aproximada e o erro associado
  printf("Solução aproximada:\n");
  for (int i = 0; i < n; i++) {
      printf("x%d = %.6f\n", i + 1, x_2[i]);
  }
  printf("Erro associado (norma-2): %.6f\n\n", erro_2);

  // Libera a memória alocada para A, b e x usando mat_libera e vet_libera
  mat_libera(m, A_2);
  vet_libera(b_2);
  vet_libera(x_2);


//2b)
  // Conjunto de pontos i
  double px_i[] = {0, 1, 2, 5};
  double py_i[] = {0, 3, 3, 6};
  int n_i = sizeof(px_i) / sizeof(px_i[0]);

  // Encontrando os coeficientes para a melhor parábola
  double a_parabola_i, b_parabola_i, c_parabola_i;
  double erro_parabola_i = ajuste_parabola(n_i, px_i, py_i, &a_parabola_i, &b_parabola_i, &c_parabola_i);

  // Encontrando os coeficientes para a melhor cúbica
  double a_cubica_i, b_cubica_i, c_cubica_i, d_cubica_i;
  double erro_cubica_i = ajuste_cubica(n_i, px_i, py_i, &a_cubica_i, &b_cubica_i, &c_cubica_i, &d_cubica_i);

  printf("Conjunto de pontos i:\n");
  printf("Coeficientes da melhor parábola: a = %.6f, b = %.6f, c = %.6f\n", a_parabola_i, b_parabola_i, c_parabola_i);
  printf("Erro do ajuste da parábola: %.6f\n", erro_parabola_i);
  printf("Coeficientes da melhor cúbica: a = %.6f, b = %.6f, c = %.6f, d = %.6f\n", a_cubica_i, b_cubica_i, c_cubica_i, d_cubica_i);
  printf("Erro do ajuste da cúbica: %.6f\n", erro_cubica_i);
  printf("Melhor ajuste: %s\n", erro_parabola_i < erro_cubica_i ? "parábola" : "cúbica");
  printf("\n");

  // Conjunto de pontos ii
  double px_ii[] = {1, 3, 4, 6};
  double py_ii[] = {1, 2, 1, 3};
  int n_ii = sizeof(px_ii) / sizeof(px_ii[0]);

  // Encontrando os coeficientes para a melhor parábola
  double a_parabola_ii, b_parabola_ii, c_parabola_ii;
  double erro_parabola_ii = ajuste_parabola(n_ii, px_ii, py_ii, &a_parabola_ii, &b_parabola_ii, &c_parabola_ii);

  // Encontrando os coeficientes para a melhor cúbica
  double a_cubica_ii, b_cubica_ii, c_cubica_ii, d_cubica_ii;
  double erro_cubica_ii = ajuste_cubica(n_ii, px_ii, py_ii, &a_cubica_ii, &b_cubica_ii, &c_cubica_ii, &d_cubica_ii);

  printf("Conjunto de pontos ii:\n");
  printf("Coeficientes da melhor parábola: a = %.6f, b = %.6f, c = %.6f\n", a_parabola_ii, b_parabola_ii, c_parabola_ii);
  printf("Erro do ajuste da parábola: %.6f\n", erro_parabola_ii);
  printf("Coeficientes da melhor cúbica: a = %.6f, b = %.6f, c = %.6f, d = %.6f\n", a_cubica_ii, b_cubica_ii, c_cubica_ii, d_cubica_ii);
  printf("Erro do ajuste da cúbica: %.6f\n", erro_cubica_ii);
  printf("Melhor ajuste: %s\n", erro_parabola_ii < erro_cubica_ii ? "parábola" : "cúbica");
  printf("\n");

  

  


  
  
  return 0;
}