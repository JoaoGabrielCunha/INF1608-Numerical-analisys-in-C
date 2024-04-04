#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "interp.h"




double distribuicao_normal(double x) {
    double mu = 0; // Média da distribuição normal
    double sigma = 0.5; // Desvio padrão da distribuição normal
    return 1.0 / (sigma * sqrt(2 * M_PI)) * exp(-0.5 * pow((x - mu) / sigma, 2));
}



int main() {

// Intervalo  e n
double a = -2;
double b= +2;
int n= 10;


//Armazenando os resultados regulares.  
double x[n]; 
regular(n, a, b, x);


//Armazenando os resultados de Chebyshev.
double xc[n];
chebyshev(n,a,b,xc);


double bi[n]; // Vetor para armazenar os coeficientes


  // Calculando os coeficientes usando a função coeficientes
coeficientes(n, x, distribuicao_normal, bi);
  

  double ponto_x= -2;
  
  while (ponto_x <= 2.0){
  
  
  
  double resultado_regular = avalia(n, x, bi, ponto_x);
  double resultado_chebyshev = avalia(n, xc, bi, ponto_x);
  double resultado_verdadeiro =  distribuicao_normal(ponto_x);

  printf("Para o ponto %f\n",ponto_x);
  printf("Resultado usando os pontos regulares: %f\n", resultado_regular);
  printf("Resultado usando os pontos de chebyshev: %f\n ", resultado_chebyshev);
  printf("Resultado verdadeiro %f\n\n ", resultado_verdadeiro);


  ponto_x +=0.5;


  }

 return 0;

}