#include<math.h>
#include"massamola.h"

void forca(double t, double x, double y, double *fx, double *fy)
{
  double massa = 2.0;
  double gravidade = 9.8;
  double fGravidade = massa * gravidade;

  double fventoIni = 10.0;
  double vento = fventoIni * exp(-t / 20.0);

  double rigidezMola = 0.3;
  double comprimentoRepouso = 200.0;
  double comprimentoAtual = sqrt(x * x + y * y);
 
double forcaMolax = -rigidezMola * (comprimentoAtual - comprimentoRepouso) *(x / comprimentoAtual);
                    
  double forcaMolay = -rigidezMola * (comprimentoAtual - comprimentoRepouso) *(y / comprimentoAtual);

  *fx = vento + forcaMolax;
  *fy = fGravidade + forcaMolay;
  return;
}



double evolui (double t, double h, double x, double y, double xp, double yp,
double* xn, double* yn)
{
  double amortecimento = 0.002;                    
  double massa = 2.0;
  double fx,fy;
                    
  forca(t,x,y,&fx,&fy);  
                    
  *xn = x + (1.0- amortecimento)*(x-xp) + (h*h)*(fx/massa);
  *yn = y+ (1.0-amortecimento)*(y-yp) + (h*h)*(fy/massa);

   return t+h;
                    
      
}

void simula (double x0, double y0, double t_final, int n, double* x, double* y)
{
  double h = t_final/n;
  double tini = 0.0;
  double xp = x0;
  double yp = y0;
  double xn;
  double yn;

  for(int i=0; i<n; i++)
  {
   tini = evolui(tini,h,x0,y0,xp,yp,&xn,&yn);
   yp= y0;
   xp= x0;
   x0= xn;
   y0= yn;

   *(x+i) = xn;
   *(y+i) = yn;
                    
  }

  return ;
          
}

