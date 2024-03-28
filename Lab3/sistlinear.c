#include<math.h>

//1)

//Trocando linhas de A e B, função auxiliar.
void trocar_linhas(double **A, double *b, int linha1, int linha2, int n)
{
  double* temp = A[linha1];
  A[linha1] = A[linha2];
  A[linha2] = temp;

  double temp_b = b[linha1];
  b[linha1]= b[linha2];
  b[linha2] = temp_b;

}


void gauss(int n, double** A, double* b, double* x) {
    // Implementação do método de eliminação de Gauss com pivotamento

    // Fase de eliminação
    for (int k = 0; k < n-1; ++k) {
        // Pivoteamento parcial: encontra o pivô máximo
        int linha_pivo = k;
        double valor_pivo = fabs(A[k][k]);
        for (int i = k+1; i < n; ++i) {
            if (fabs(A[i][k]) > valor_pivo) {
                linha_pivo = i;
                valor_pivo = fabs(A[i][k]);
            }
        }
        // Troca a linha atual com a linha do pivô máximo
        if (linha_pivo != k) {
            trocar_linhas(A, b, k, linha_pivo, n);
        }

        // Eliminação gaussiana
        for (int i = k+1; i < n; ++i) {
            double fator = A[i][k] / A[k][k];
            for (int j = k; j < n; ++j) {
                A[i][j] -= fator * A[k][j];
            }
            b[i] -= fator * b[k];
        }
    }

    // Fase de substituição regressiva
    for (int i = n-1; i >= 0; --i) {
        x[i] = b[i];
        for (int j = i+1; j < n; ++j) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }
}
