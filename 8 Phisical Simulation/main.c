#include <stdio.h>
#include"massamola.h"
#include<math.h>

void salvar_pontos_em_arquivo(const char *filename, double *x, double *y, int n) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "x = %lf\n", x[i]);
        fprintf(file, "y = %lf\n", y[i]);
        fprintf(file, "-----------------------\n");
    }

    fclose(file);
}






int main(void) {

  int n = 1000;
  double x[n];
  double y[n];
  simula(200, 0, 100, n, x,y);
  int number = sizeof(x) / sizeof(x[0]);

  
  const char *filename = "pontos.txt";


  salvar_pontos_em_arquivo(filename, x, y, number);

  printf("Pontos salvos em %s\n", filename);


  

  



  
  return 0;
}