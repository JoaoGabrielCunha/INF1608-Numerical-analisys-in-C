#include <stdio.h>

int main(void) {

  // Sistema 1
  printf("Sistema 1:\n");
  int n1 = 3;
  double** A1 = mat_cria(n1, n1);
  A1[0][0] = 1; A1[0][1] = -1; A1[0][2] = 0;
  A1[1][0] = -1; A1[1][1] = 2; A1[1][2] = 1;
  A1[2][0] = 0; A1[2][1] = 1; A1[2][2] = 2;
  double* b1 = malloc(n1 * sizeof(double));
  b1[0] = 0; b1[1] = 2; b1[2] = 3;
  double* x1 = malloc(n1 * sizeof(double));
  gauss(n1, A1, b1, x1);
  printf("Solucao esperada: 1 1 1\n");
  printf("Solucao encontrada: %.2f %.2f %.2f\n", x1[0], x1[1], x1[2]);
  printf("\n");

  // Sistema 2
  printf("Sistema 2:\n");
  int n2 = 6;
  double** A2 = mat_cria(n2, n2);
  A2[0][0] = 3; A2[0][1] = -1; A2[0][2] = 0; A2[0][3] = 0; A2[0][4] = 0; A2[0][5] = 0.5;
  A2[1][0] = -1; A2[1][1] = 3; A2[1][2] = -1; A2[1][3] = 0; A2[1][4] = 0.5; A2[1][5] = 0;
  A2[2][0] = 0; A2[2][1] = -1; A2[2][2] = 3; A2[2][3] = -1; A2[2][4] = 0; A2[2][5] = 0;
  A2[3][0] = 0; A2[3][1] = 0; A2[3][2] = -1; A2[3][3] = 3; A2[3][4] = -1; A2[3][5] = 0;
  A2[4][0] = 0; A2[4][1] = 0.5; A2[4][2] = 0; A2[4][3] = -1; A2[4][4] = 3; A2[4][5] = -1;
  A2[5][0] = 0.5; A2[5][1] = 0; A2[5][2] = 0; A2[5][3] = 0; A2[5][4] = -1; A2[5][5] = 3;
  double* b2 = malloc(n2 * sizeof(double));
  b2[0] = 2.5; b2[1] = 1.5; b2[2] = 1; b2[3] = 1; b2[4] = 1.5; b2[5] = 2.5;
  double* x2 = malloc(n2 * sizeof(double));
  gauss(n2, A2, b2, x2);
  printf("Solucao esperada: 1 1 1 1 1 1\n");
  printf("Solucao encontrada: %.2f %.2f %.2f %.2f %.2f %.2f\n", x2[0], x2[1], x2[2], x2[3], x2[4], x2[5]);
  printf("\n");

  // Liberando memória
  mat_libera(n1, A1);
  free(b1);
  free(x1);
  mat_libera(n2, A2);
  free(b2);
  free(x2);

  return 0;












  
}