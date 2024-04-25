#include <stdio.h>
#include"simpson.h"
#include<math.h>

double func1(double x)
{
    return x / sqrt(x * x + 9.0);
}


double func2(double x)
{
    return (2/sqrt(M_PI))* exp(-x * x);
}


double func3(double x)
{
  return log(cos(x) + sin(x));
}


int main(void) {

  double a = 0.0;
  double b = 1.0; 
  double tol = 0.0001;  

  double result = adaptsimpson(a, b, func1, tol);
  printf("Integral de f(x) = x/sqrt(x^2 + 9) de %f a %f: %f\n\n", a, b, result);

  
  a = 0.0;  
  b = 3.0; 

  result = adaptsimpson(a, b, func2, tol);

  printf("Integral de f(x) = (2/sqrt(M_PI))* exp(-x * x) de %f a %f: %f\n\n", a, b, result);


  a = 0.0;
  b =  M_PI/2;
   
  result = adaptsimpson(a, b, func3, tol);
  printf("Integral de f(x) = ln(cos(x) + sin(x)) de %f a %f: %f\n\n", a, b, result);

  
  return 0;
}