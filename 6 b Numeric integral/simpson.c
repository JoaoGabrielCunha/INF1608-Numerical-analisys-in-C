#include<stdio.h>
#include<math.h>


double simpson(double a, double b, double (*f)(double x))
{
    double h = (b - a) / 2.0;
    double fa = f(a);
    double fb = f(b);
    double fm = f((a + b) / 2.0);
    return (h / 3.0) * (fa + 4 * fm + fb);
}




double adaptsimpson(double a, double b, double (*f)(double x), double tol) {
    double m = (a + b) / 2.0;
    double integral_ab = simpson(a, b, f);
    double integral_am = simpson(a, m, f);
    double integral_mb = simpson(m, b, f);
    double delta = integral_ab - (integral_am + integral_mb);

    if (fabs(delta) > 15.0 * tol) {
  
        double left_integral = adaptsimpson(a, m, f, tol / 2.0);
        double right_integral = adaptsimpson(m, b, f, tol / 2.0);
        return left_integral + right_integral;
    } 
    else {
      
        return integral_am + integral_mb - (delta / 15.0);
    }
}