#include<stdio.h>
#include<math.h>
#include "interp.h"


void regular(int n,double a, double b, double *xi){


  double distance= (b-a)/(n-1);

  xi[0] = a;
  xi[n-1]=b;

  for(int i=1; i< n-1; i++ ){
    xi[i]= a +i*distance;
  }
  
}


void chebyshev(int n, double a, double b, double* xi) {

  int i=0;
  double teta= M_PI/(2*n);
  for(int beta = 1; beta<= 2*n-1; beta+=2){
    *(xi +i)= ((b-a)/2)*(double)(cos(beta*teta))  + (a+b)/2.0;
    i++;
  }
  



}

void coeficientes(int n, double *xi, double (*f)(double), double *bi) {
  
    double tabela[n][n];
    for (int i = 0; i < n; i++) {
        tabela[i][0] = f(xi[i]);
    }

    
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            tabela[i][j] = (tabela[i + 1][j - 1] - tabela[i][j - 1]) / (xi[i + j] - xi[i]);
        }
    }

    
    for (int i = 0; i < n; i++) {
        bi[i] = tabela[0][i];
    }
}




double avalia(int n, double *xi, double *bi, double x) {
    double result = 0.0;
    double termo = 1.0;

    for (int i = 0; i < n; i++) {
        double coeficiente = bi[i] * termo;
        result += coeficiente;
        termo *= (x - xi[i]);
    }

    return result;
}



