double *vet_cria(int n);

void vet_libera (double* v);

double** mat_cria (int m, int n);

void mat_libera (int m, double** A);

void mat_imprime (int m, int n, double** A);

void mat_transposta (int m, int n, double **A, double** T);

void mat_multv (int m, int n, double** A, double* v, double* w);

void mat_multm(int m, int n, int q, double** A, double** B, double** C);

void trocar_linhas(double **A, double *b, int linha1, int linha2, int n);

void gauss(int n, double** A, double* b, double* x);

double mmq(int m,int n, double**A, double*b, double* x);


double ajuste_parabola(int n, double* px, double* py, double* a, double* b, double* c);

double ajuste_cubica(int n, double* px, double* py, double* a, double* b, double* c, double* d);