#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include"integral.h"






//1a)
double derivada(double (*f)(double), double x, double h) {
    double fx_plus_h = f(x + h);
    double fx_minus_h = f(x - h);
    double fx = f(x);
    return (fx_plus_h - 2.0 * fx + fx_minus_h) / (h * h);
}

//2a)
double f(double x) {
  double resultado = cos(x) - 2.0 * sin(x);
  return resultado ;
}


double derivada_analitica(double x) {
    return -sin(x) - 2.0 * cos(x);
}



//1b)

double simpson(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double integral = 0.0;

    for (int i = 0; i < n; i++) {
        double xi = a + i * h;
        double xi1 = xi + h;
        integral += (h / 6.0) * (f(xi) + 4 * f(xi +h/2.0 ) + f(xi +h));
    }

    return integral;
}





double f1(double x) {
    return x/(sqrt(x * x + 9));
}

double f2(double x) {
    return x * x * log(x);
}

double f3(double x) {
    return x * x * sin(x);
}


