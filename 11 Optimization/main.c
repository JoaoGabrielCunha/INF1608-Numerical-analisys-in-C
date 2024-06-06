#include <stdio.h>
#include <math.h>
#include "otimizacao.h"

double funcao1(double x)
{
  return (x*x) + sin(x);
}

double funcao2(double x)
{
  return (x*x*x*x*x*x)-(11*x*x*x) + (17*x*x) - 7*x +1;
}

int main(void) {
  double x;
  double xmin;
  double delta= 0.1;
  double r= 0.25;

  int num = mips(r, delta, funcao1, &xmin);
  printf("valor de x: %f , numero de interacoes: %d\n",xmin,num);

  double x2;
  double xmin2;
  double delta2= 0.1;
  double r2= 0.25;

  int num2 = mips(r2, delta2, funcao2, &xmin2);
  printf("valor de x: %f , numero de interacoes: %d\n",xmin2,num2);
  return 0;


  
}