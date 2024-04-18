#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include"integral.h"


int main(void) {

//2a)

  double x = 0.0;
  double h_um = 0.1;
  double h_dois = 0.01;
  double h_tres = 0.001;

  printf("Calculando a derivada numérica da função f(x) = cos(x) - 2*sin(x) em x = 0\n");

  // Derivada numérica para h = 0.1
  double derivada_numerica_um = derivada(f, x, h_um);
  double derivada_analitica_valor = derivada_analitica(x);
  printf("Para h = %.3f:\n", h_um);
  printf("Derivada numérica: %.10f\n", derivada_numerica_um);
  printf("Derivada analítica: %.10f\n", derivada_analitica_valor);
  printf("Diferença absoluta: %.10f\n\n", fabs(derivada_numerica_um - derivada_analitica_valor));

  // Derivada numérica para h = 0.01
  double derivada_numerica_dois = derivada(f, x, h_dois);
  printf("Para h = %.3f:\n", h_dois);
  printf("Derivada numérica: %.10f\n", derivada_numerica_dois);
  printf("Derivada analítica: %.10f\n", derivada_analitica_valor);
  printf("Diferença absoluta: %.10f\n\n", fabs(derivada_numerica_dois - derivada_analitica_valor));

  // Derivada numérica para h = 0.001
  double derivada_numerica_tres = derivada(f, x, h_tres);
  printf("Para h = %.3f:\n", h_tres);
  printf("Derivada numérica: %.10f\n", derivada_numerica_tres);
  printf("Derivada analítica: %.10f\n", derivada_analitica_valor);
  printf("Diferença absoluta: %.10f\n\n", fabs(derivada_numerica_tres - derivada_analitica_valor));
  
  



  
//2b)  

double a,b;
float n1 = 16, n2 = 32;
  

  // Integral 1: x/sqrt(x^2 + 9) from 0 to 4
  a = 0.0;
 b = 4.0;
   double result2_n16 = simpson(f1, a, b, n1);
  double result2_n32 = simpson(f1, a, b, n2);
  printf("Integral 1 (sqrt(x^2 + 9) from 1 to 3): Sn=16: %.12f, Sn=32: %.12f\n", result2_n16, result2_n32);

  // Integral 3: x^2 * ln(x) from 1 to 3
  a = 1.0;
 b = 3.0;
  double result3_n16 = simpson(f2, a, b, n1);
 double  result3_n32 = simpson(f2, a, b, n2);
  printf("Integral 2 (x^2 * ln(x) from 1 to e): Sn=16: %.12f, Sn=32: %.12f\n", result3_n16, result3_n32);

  // Integral 4: x^2 * sin(x) from 0 to pi
   a = 0.0;
  b = M_PI;
  double result4_n16 = simpson(f3, a, b, n1);
  double  result4_n32 = simpson(f3, a, b, n2);
  printf("Integral 3 (x^2 * sin(x) from 0 to pi): Sn=16: %.12f, Sn=32: %.12f\n", result4_n16, result4_n32);



  
  
  
  return 0;



}