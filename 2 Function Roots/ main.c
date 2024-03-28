#include <stdio.h>
#include "raizes.h"
#include<math.h>



double f(double x)
{
return (x*x*x) + 2*(x*x)  -2;
  
}


double g(double x)
{

  return (x*x*x*x) + x + 1;
  
}



double paraquedista(double m)
{
  return 35.0 - ((9.8*m)/(15.0))* (1.0- exp((-15.0*9.0)/m));
  
}



int main(void){

//Teste da 2 acontecendo:
  
  double raiz=0;
  int num_iteracoes;
  num_iteracoes = bissecao(0,1,f,&raiz);
  
  if (num_iteracoes == 0) {
      printf("Não foi possível encontrar a raiz usando o método da bisseção.\n");
  } else {
      printf("Raiz encontrada: %.8lf\n", raiz);
      printf("Número de iterações: %d\n\n\n", num_iteracoes);
  }

//Teste 3 acontecendo:
  raiz = 0;
  num_iteracoes =  bissecao(-2,+2,g,&raiz);

//Teste 4 acontecendo:
  
  raiz=0;
  num_iteracoes = bissecao(0,1000,paraquedista,&raiz);
  if (num_iteracoes == 0) {
      printf("Não foi possível encontrar a raiz usando o método da bisseção.\n");
  } else {
      printf("Raiz encontrada: %.8lf\n", raiz);
      printf("Número de iterações: %d\n\n\n", num_iteracoes);
  }

  
  return 0;
}
