#include "vetor.h"
#include "matriz.h"
#include <stdio.h>

int main (void)
{
  /* Exemplo de construção de vetor dinâmico */
  double* v = vet_cria(2);
  v[0] = 1.0;
  v[1] = 2.0;

  /* Exemplo de construção de vetor estático */
  double w[] = {1.0,2.0f};

  

  /* Imprime vetores (são iguais em conteúdo) */

  

  /*Calcula e imprime o produto escalar */
printf("Produto escalar de v e w: %.2f\n",vet_escalar(2,v,w));

  /*Calcula e imprime a norma euclidiana de v */

  printf("Norma Euclidiana de v: %.2f\n", vet_norma2(2,v));

  
  
  vet_imprime(2,v);
  vet_imprime(2,w);

  /* Exemplo de construção de matriz dinâmica */
  double** A = mat_cria(3,2);
  A[0][0] = 1.0;
  A[0][1] = 2.0;
  A[1][0] = 3.0;
  A[1][1] = 4.0;
  A[2][0] = 5.0;
  A[2][1] = 6.0;

  /* Exemplo de construção de matriz estática no formato ponteiro para ponteiro */
  double linha1[] = {1.0,2.0};
  double linha2[] = {3.0,4.0};
  double linha3[] = {5.0,6.0};
  double* B[] = {linha1,linha2,linha3};


  // Imprime matrizes
  printf("Matriz A:\n");
  mat_imprime(3, 2, A);
  printf("Matriz B:\n");
  mat_imprime(3, 2, B);

  // Teste da função mat_multv
  double* resultado_multv = vet_cria(3); // Vetor resultado da multiplicação da matriz pelo vetor
  mat_multv(3, 2, A, w, resultado_multv);
  printf("Resultado da multiplicação da matriz A pelo vetor w:\n");
  vet_imprime(3, resultado_multv);
  vet_libera(resultado_multv);

  // Teste da função mat_multm
  double** resultado_multm = mat_cria(3, 2); // Matriz resultado da multiplicação das matrizes
  mat_multm(3, 2, 2, A, A, resultado_multm);
  printf("Resultado da multiplicação das matrizes A e A:\n");
  mat_imprime(3, 2, resultado_multm);
  mat_libera(3, resultado_multm);

  /* Imprime matrizes (são iguais em conteúdo) */
  mat_imprime(3,2,A);
  mat_imprime(3,2,B);

  /* Apenas objetos dinâmicos podem ser liberados */
  vet_libera(v);
  mat_libera(3,A);

  return 0; 
} 
