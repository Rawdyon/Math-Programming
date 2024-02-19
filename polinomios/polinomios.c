#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tipos.h"
#include "poli.h"

void *fs[]={sumaQ, sumaR, sumaH, sumaG,sumaGQ,sumaZp,sumaC};
void *fr[]={restaQ, restaR, restaH, restaG,restaGQ,restaZp,restaC};
void *fp[]={prodQ, prodR, prodH, prodG,prodGQ,prodZp,prodC};
void *fd[]={divQ, divR, divH, divG,divGQ,divZp,divC};
  
int main(int argc, char *argv[])
{
  P a, b, q,r /*,r={c:NULL, g:-1}*/;
  FILE *ent, *sal;
  char *noment="policoef.txt", *nomsal="resultado.txt";
  int opc,k;
  
  printf("Por leer el archivo %s.\n", noment);
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
  printf("Por leer los polinomios.\n");
  a=leeP(opc,ent);
  printf("Por leer el segundo polinomio: ");
  b=leeP(opc,ent);
  //printf("G");
  printf("B");
  fprintf(sal,"Los polinomios son:\na = ");
  escP(a,opc,sal);
  fprintf(sal,"\nb = ");
  escP(b,opc,sal);
  //printf("F");
  fprintf(sal,"\nCociente y residuo:\n");
  if(esCeroP(b) || opc == 3)
  	fprintf(sal,"No se puede llevar acabo. \n");
  else{
  	//DIVISIÓN
  	q = divP(a,b,&r,fp[opc],fd[opc],fr[opc],opc);
	fprintf(sal,"\nq = ");
	escP(q,opc,sal);
	fprintf(sal,"\nr = ");
	escP(r,opc,sal);
	liberaP(&q);
	liberaP(&r);
  }
  q = sumaP(a,b,fs[opc],opc);
  fprintf(sal,"\nLa suma es: ");
  escP(q,opc,sal);
  liberaP(&q);
  
  q = restaP(a,b,fr[opc],opc);
  fprintf(sal,"\nLa resta es: ");
  escP(q,opc,sal);
  liberaP(&q);
  
  q = multP(a,b,fs[opc],fp[opc],opc);
  fprintf(sal,"\nEl producto es: ");
  escP(q,opc,sal);
  liberaP(&q);

  printf("\n\nFin del programa\n");
  liberaP(&a);
  liberaP(&b);
  return 0;
}

