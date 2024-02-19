#include <stdio.h>    
#include <stdlib.h>     
#include <math.h>
#include "tipos.h"
#include "poli.h"

P leeP(enum tipoCoeficiente tipo,FILE *f){
	P a;
	int i;
	//printf("a");
	fscanf(f,"%d",&a.g);
	if((a.c=(Coeficiente*)malloc((a.g+1)*sizeof(Coeficiente)))==NULL){
		printf("error al generar espacio.\n");
		a.g = -1;
		return a;
	}
	
	for(i= 0; i<=a.g;i++)
		a.c[i] = leerCoef(tipo,f);
	//printf("C");
	return a;
}
int escP(P a,enum tipoCoeficiente tipo,FILE *f){
	int i;
	if(a.g<0){
		fprintf(f,"0");
		return 0;
	}
	for(i=a.g;i>1;i--)
		if(esCeroCoef(a.c[i],tipo)){
			esccoef(a.c[i],tipo,f);
			fprintf(f,"x^%d",i);
		}
	if(a.g>=1 && esCeroCoef(a.c[1],tipo)){
			esccoef(a.c[1],tipo,f);
			fprintf(f,"x");
	}
	if(esCeroCoef(a.c[0],tipo))
			esccoef(a.c[0],tipo,f);		
	
	return 0;
}

P sumaP(P a, P b,void *oper,enum tipoCoeficiente tipo)
{
  P ret;
  int i, min;
  
  if (a.g<0){
    return copiaP(b);
  }
  if (b.g<0){
    return copiaP(a);
  }
  if (a.g<b.g){
    min = a.g;
    ret.g = b.g;
  } else{
    min = b.g;
    ret.g = a.g;
  }
  if((ret.c=(Coeficiente*)malloc((ret.g+1)*sizeof(Coeficiente)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
  }
  for (i=0; i<=min; i++) 
  	ret.c[i] = opera(a.c[i],b.c[i],oper,tipo);
  if (a.g==min){
    for (; i<=ret.g; i++) 
		ret.c[i]=b.c[i];
  }
  if (b.g==min){
    for (; i<=ret.g; i++) 
	    ret.c[i]=a.c[i];
  }
  
  while(ret.g>=0 && !esCeroCoef(ret.c[ret.g],tipo)) ret.g--;
  if (ret.g<0){
    free(ret.c);
    ret.c = NULL;
  }
  return ret;
}

P restaP(P a, P b,void *oper,enum tipoCoeficiente tipo)
{
  P ret;
  int i, min;
  
  if (a.g<0){
    return copiaMenosP(b,tipo);
  }
  if (b.g<0){
    return copiaP(a);
  }
  if (a.g<b.g){
    min = a.g;
    ret.g = b.g;
  } else{
    min = b.g;
    ret.g = a.g;
  }
  if((ret.c=(Coeficiente*)malloc((ret.g+1)*sizeof(Coeficiente)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
  }
  for (i=0; i<=min; i++) 
  	ret.c[i] = opera(a.c[i],b.c[i],oper,tipo);
  	
  if (a.g==min){
    for (; i<=ret.g; i++) 
		ret.c[i]= CopiaMenosCoef(b.c[i],tipo);
  }
  if (b.g==min){
    for (; i<=ret.g; i++) 
	    
		ret.c[i]=a.c[i];
  }
  
  while(ret.g>=0 && !esCeroCoef(ret.c[ret.g],tipo)) ret.g--;
  if (ret.g<0){
    free(ret.c);
    ret.c = NULL;
  }
  return ret;
}

int  liberaP(P *a) 
{
  if(a->c==NULL) free(a->c);
  if(a->c==NULL) free(a->c);
  a->g=-1;
  a->c=NULL;
  return 0;
}
P copiaP(P a){
  P ret;
  int i;
  ret.g = a.g;
  if (ret.g<0){
    ret.c=NULL;
    return ret;
  }
  if((ret.c=(Coeficiente*)malloc((ret.g+1)*sizeof(Coeficiente)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
  }
  for(i=0; i<=ret.g; i++) 
	ret.c[i]=a.c[i];
  return ret;
}

P copiaMenosP(P a,enum tipoCoeficiente tipo){
  P ret;
  int i;
  ret.g = a.g;
  if (ret.g<0){
    ret.c=NULL;
    return ret;
  }
  if((ret.c=(Coeficiente*)malloc((ret.g+1)*sizeof(Coeficiente)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
  }
  for(i=0; i<=ret.g; i++) 
  	ret.c[i]= CopiaMenosCoef(a.c[i],tipo);
  return ret;
}

P multP(P a, P b,void *oper,void *operA,enum tipoCoeficiente tipo)
{
  int i, j;
  P ret;
  ret.g=a.g+b.g;
  if((ret.c=(Coeficiente*)malloc((ret.g+1)*sizeof(Coeficiente)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
  }
  for (i=0; i<=ret.g; i++) 
  	ret.c[i] = Cero(tipo);
  for (i=0; i<=a.g; i++)
    for(j=0; j<=b.g; j++)
      ret.c[i+j] = opera(ret.c[i+j],opera(a.c[i],b.c[j],operA,tipo),oper,tipo);

  return ret;
}
P multMonomioP(P a, Coeficiente c, int e,void *oper,enum tipoCoeficiente tipo)
{
  int i;
  P ret;
  ret.g=a.g+e;
  if((ret.c=(Coeficiente*)malloc((ret.g+1)*sizeof(Coeficiente)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
  }
  for (i=0; i<=ret.g; i++) 
  	ret.c[i]= Cero(tipo);
  for (i=e; i<=ret.g; i++) 
  	ret.c[i]=opera(a.c[i-e],c,oper,tipo);
  return ret;
}
P divP(P a, P b, P *r,void *oper,void *operD,void *operR,enum tipoCoeficiente tipo)
{
  P q, aux, a_aux;
  Coeficiente coef;
  int grad, i,j=0;
  a_aux= copiaP(a);
  a=a_aux;
  if (a.g<b.g){
    q.g=-1;
    q.c=NULL;
    *r = copiaP(a);
    return q;
  }
  q.g=a.g-b.g;
  if((q.c=(Coeficiente*)malloc((q.g+1)*sizeof(Coeficiente)))==NULL){
    printf("error al generar espacio.\n");
    q.g = -1;
    return q;
  }
  for (i=0; i<=q.g; i++) 
  	q.c[i]=Cero(tipo);
  
  do{
    grad=a.g-b.g;
    q.c[grad] = opera(a.c[a.g],b.c[b.g],operD,tipo);
    aux = multMonomioP(b, q.c[grad],grad,oper,tipo);
    a_aux = restaP(a, aux,operR,tipo);
    liberaP(&a);
    liberaP(&aux);
    a = a_aux;
    liberaP(r);
    *r=copiaP(a);
    j+=1;
    if(j>3000000){
    	printf("error");
    	break;
	}
  }while(!esCeroP(*r) && (r->g>=b.g));
  return q;
}
int esCeroP(P a)
{
  return a.g <0;
}

