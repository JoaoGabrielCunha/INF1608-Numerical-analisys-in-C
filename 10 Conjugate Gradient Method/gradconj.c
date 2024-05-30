#include "gradconj.h"
#include "matriz.h"

int gradconj (int n, double** A, double* b, double* x, double tol)
{
  double r1,novo,bet,al;
  double* r = vet_cria (n);
  double* vAux = vet_cria (n);
  double* vAux2 = vet_cria (n);
  double* d =  vet_cria (n);
  int num = -1;
  
  mat_multv (n,n, A, x, vAux);
  for(int i = 0; i<n;i++){
    *(r+i) = *(b+i) - *(vAux+i);
    *(d+i) = *(r+i);
  }
  for(int i = 0;i <n;i++){
    if(tol > vet_norma2 (n, r)){
      num = i;
      break;
    }
      mat_multv (n,n, A, d, vAux2);
    if(i == 0){
      r1 = vet_escalar (n, r, r);
    } else {
      r1 = novo;
    }
    al = r1/vet_escalar (n, d, vAux2);
    vet_mults (n, d, al, vAux);
    vet_mults (n, vAux2, al, vAux2);
    for(int i = 0;i <n;i++){
      *(x+i) = *(x+i)+ *(vAux+i);
      *(r+i) = *(r+i) - *(vAux2+i);
    }
    novo = vet_escalar (n, r, r);
    bet = novo/r1;
    vet_mults (n, d, bet, vAux);
    for(int i = 0;i <n;i++){
      *(d+i) = *(r+i) + *(vAux+i);
    }
  }
  if(num == -1){
    num = n;
  }
  vet_libera (vAux);
  vet_libera (vAux2);
  vet_libera (r);
  vet_libera (d);
  return num;
}

int gradconj_jacobi (int n, double** A, double* b, double* x, double tol){
  double* m = vet_cria (n);
  double* r = vet_cria (n);
  double* vAux = vet_cria (n);
  double* Ad = vet_cria (n);
  double r1,novo,bet,al;
  double* d = vet_cria (n);
  double* z =     vet_cria (n);
  int num = -1;
  mat_multv (n,n, A, x, vAux);
  for(int i = 0; i<n;i++){
    *(r+i) = *(b+i) - *(vAux+i);
    *(m+i) = 1/(*(*(A+i)+i));
    *(d+i) = *(r+i)* *(m+i);
    *(z+i) = *(d+i);
  }
  for(int i = 0;i <n;i++){
    if(tol > vet_norma2 (n, r)){
      num = i;
      break;
    }
    mat_multv (n,n, A, d, Ad);
    if(i == 0){
      r1 = vet_escalar (n, z, r);
    } else {
      r1 = novo;
    }
    al = r1/vet_escalar (n, d, Ad);
    vet_mults (n, d, al, vAux);
    vet_mults (n, Ad, al, Ad);
    for(int i = 0;i <n;i++){
      *(x+i) = *(x+i) + *(vAux+i);
      *(r+i) = *(r+i)- *(Ad+i);
      *(z+i) = *(r+i)* *(m+i);
    }
    novo = vet_escalar (n, z, r);
    bet = novo/r1;
    vet_mults (n, d, bet, vAux);
    for(int i = 0;i <n;i++){
      *(d+i) = *(z+i) + *(vAux+i);
    }
  }
  if(num == -1){
    num = n;
  }
  vet_libera (vAux);
  vet_libera (m);
  vet_libera (Ad);
  vet_libera (z);
  vet_libera (r);
  vet_libera(d);
  return num;
}