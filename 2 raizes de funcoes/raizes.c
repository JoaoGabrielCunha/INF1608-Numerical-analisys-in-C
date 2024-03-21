#include <stdio.h>
#include<math.h>

int bissecao (double a, double b, double (*f) (double x), double* r){

  unsigned int num_iteracoes = 0;
  double fa= f(a); 
  double fb= f(b);
  double c;
  double fc;
  
  if (fa*fb >=0)
  {
    printf("f(a)*f(b)>=0, portanto, não é possível aplicar o método da bissecao\n\n");
    return 0;
  }

  double erro = 0.5e-8;

  while((b-a)/2 > erro)
  {
    num_iteracoes++;
    
    c = (a+b)/2;
    
    *r= c;
    
    fc= f(c);

    if (fabs(fc)<1e-12)
       break;
    
    if (fa*fc<0.0)
      b=c;
    else
      a=c;
    
    
    
 }

    return num_iteracoes;
  
}