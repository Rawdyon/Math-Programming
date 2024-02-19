#include <stdio.h>    
#include <stdlib.h>  
#include<string.h>   
#include <math.h>
#include "biblioteca.h"

void *fs[]={sumaQ, sumaR, sumaH, sumaG,sumaGQ,sumaZp,sumaC};
void *fr[]={restaQ, restaR, restaH, restaG,restaGQ,restaZp,restaC};
void *fp[]={prodQ, prodR, prodH, prodG,prodGQ,prodZp,prodC};
void *fd[]={divQ, divR, divH, divG,divGQ,divZp,divC};


int main(int argc, char *argv[])
{
  MATRIZ a, b, r;
  int i, j, k;
  FILE *ent, *sal;
  int opc;
  char *noment="Matcoef.txt", *nomsal="resultado.txt";
  ent=fopen(noment, "rt");
  if(ent==NULL){
    int mi_error=errno; 
    printf("Hubo un error en la lectura del archivo. Codigo: %d. Mensaje: <<%s>>\nPor finalizar la ejecucion del programa.\n", 
	   mi_error, strerror(mi_error));
    return -1;
  }
  sal=fopen(nomsal, "wt");
  if (sal==NULL){
    int mi_error=errno; 
    printf("Hubo un error en la escritura del archivo: %d <<%s>>\nPor finalizar la ejecucion del programa.\n", 
      mi_error, strerror(mi_error));
    fclose(ent); 
    return -1;
  }
  
  fscanf(ent,"%d",&opc);
  if(opc == ZP){
  	fscanf(ent,"%d",&p);
  	if(p == 0 || p== 1){
			fprintf(sal,"Ingrese un numero primo");
			return 0;	
		}	
	for(k=2;k<=sqrt(p);k++){
		if(p%k == 0){
			fprintf(sal,"Ingrese un numero primo");
			return 0;	
		}	
	}
	}
  //printf("\n%d\n",opc);
  printf("Por leer la primera matriz: \n");
  leeM(&a,opc,ent);
  printf("Por leer la segunda matriz: \n");
  leeM(&b,opc,ent);
  fprintf(sal,"las matrices a sumar son:\n\tPrimera matriz: \n");// mxn (%d x %d):\n", a.m, a.n);
  escribeM(a,opc,sal);
  //fprintf(sal,"%lg",a.a[1][0].unComplejo.a);
  fprintf(sal,"\n\tSegunda matriz: \n");// mxn (%d x %d):\n", b.m, b.n);
  escribeM(b,opc,sal);
  
  r = sumaM(a,b,fs[opc],opc,sal);
  
  fprintf(sal,"\nLa suma es la matriz: \n");// (%d x %d):\n", r.m, r.n);
  escribeM(r,opc,sal);
  
  r = restaM(a, b,fr[opc],opc,sal);
  fprintf(sal,"\nLa resta es la matriz:\n");// (%d x %d):\n", r.m, r.n);
  escribeM(r,opc,sal);
  r = prodM(a, b,fs[opc],fp[opc],opc,sal);
  fprintf(sal,"\nEl producto es la matriz:\n");// (%d x %d):\n", r.m, r.n);
  escribeM(r,opc,sal);

  liberaEspacioMatriz(&a);
  liberaEspacioMatriz(&b);
  liberaEspacioMatriz(&r);
  printf("\n\nFIN DEL PROGRAMA\n");

  return 0;
}

