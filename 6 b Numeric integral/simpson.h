double simpson(double a, double b, double (*f)(double x));

double adaptsimpson(double a, double b, double (*f)(double x), double tol);