double** mat_cria (int m, int n);

void mat_libera (int m, double** A);

void mat_multv (int m, int n, double** A, double* v, double* w);

void mat_transposta (int m, int n, double **A, double** T);

void mat_multm (int m, int n, int q, double** A, double** B, double** C);

void mat_imprime (int m, int n, double** A);

double* vet_cria (int n);

void vet_libera (double* v);

double vet_escalar (int n, double* v, double* w);

double vet_norma2 (int n, double* v);

int vet_iguais (int n, double* g, double* x, double tol);

void vet_mults (int n, double* v, double s, double* w);

void vet_imprime (int n, double* v);