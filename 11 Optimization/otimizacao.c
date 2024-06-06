#include <math.h>


int mips(double r, double delta, double (*f)(double x), double *xmin)
{
 
  double t = r + delta;
  double s = r - delta;
  double tol = 1e-6;
  double tol2 = 1e-10;
  double x;
  double novo_T, novo_S, novo_R;
  int cont = 0;
  double numerador;
  double denominador;

  while (cont < 50) 
  {
    novo_T = f(t);
    novo_S = f(s);
    novo_R = f(r);
    
    denominador = 2 * ((s - r) * (novo_T - novo_S) - (novo_S - novo_R) * (t - s));
    numerador = (novo_S - novo_R) * (t - r) * (t - s);

    if (fabs(denominador) < tol2) 
    {
      x = (r + s + t) / 3;
    } 
    else 
    {
      x = ((r + s) / 2) - (numerador / denominador);
    }
    r = s;
    s = t;
    t = x;

    if (cont > 2)
    {
      double cr = fabs(novo_S - novo_T);
      if (cr <= tol) 
      {
        *(xmin) = (s + t) / 2;
        return cont;
      }
    }
    cont++;
  }
  return 0;
}