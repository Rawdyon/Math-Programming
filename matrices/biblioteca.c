#include <stdio.h>    
#include <stdlib.h>  
#include <string.h>     
#include <math.h>
#include "biblioteca.h"


#define EPSILON 1e-2

Coeficiente opera(Coeficiente a, Coeficiente  b, void *suma, enum tipoCoeficiente tipo)
{
  Q (*fRacional)(Q, Q);
  R (*fReal)(R,R);
  G (*fGaus)(G,G);
  GQ(*fGausQ)(GQ,GQ);
  Zp (*fZp)(Zp, Zp);
  C (*fCompleja)(C, C);
  H (*fCuatern)(H,H);
  Coeficiente ret;
  //{RACIONALES, REALES, CUATERNIONES, GAUSSIANOS, GAUSSIANOSQ, ZP, COMPLEJOS, TOTAL}
   if (tipo==RACIONALES){
    fRacional = suma;
    ret.unRacional = fRacional(a.unRacional, b.unRacional);
   } else if (tipo==REALES){
    fReal = suma;
    ret.unReal= fReal(a.unReal, b.unReal);
  } else if (tipo == GAUSSIANOS){
  	fGaus = suma;
	ret.unGaussiano = fGaus(a.unGaussiano,b.unGaussiano);
  } else if (tipo == GAUSSIANOSQ){
  	fGausQ = suma;
	ret.unGaussianoQ = fGausQ(a.unGaussianoQ,b.unGaussianoQ);	
  }else if (tipo==COMPLEJOS){
    fCompleja = suma;
    ret.unComplejo = fCompleja(a.unComplejo, b.unComplejo);
  } else if (tipo==ZP){
    fZp = suma;
    ret.unZp = fZp(a.unZp, b.unZp);
  } else if (tipo == CUATERNIONES){
  	fCuatern = suma;
  	ret.unCuaternion = fCuatern(a.unCuaternion,b.unCuaternion);
  }
  return ret;
}
int esCeroR(Coeficiente a){
	int i=1;
	if(a.unReal.a == 0.0)
		i =0;
	return i;
}
int esCeroC(Coeficiente a){
	int i=1;
	if(a.unComplejo.a == 0.0 && a.unComplejo.b == 0.0)
		i =0;
	return i;
}
int esCeroH(Coeficiente a){
	int i=1;
	if(a.unCuaternion.a == 0.0 && a.unCuaternion.b == 0.0
	  &&a.unCuaternion.c == 0.0 &&a.unCuaternion.d == 0.0)
		i =0;
	return i;
}
int esCeroG(Coeficiente a){
	int i=1;
	if(a.unGaussiano.a == 0 && a.unGaussiano.b == 0)
		i =0;
	return i;
}
int esCeroGQ(Coeficiente a){
	int i=1;
	if(a.unGaussianoQ.a.p == 0 && a.unGaussianoQ.b.p == 0)
		i =0;
	return i;
}
int esCeroQ(Coeficiente a){
	int i=1;
	if(a.unRacional.p == 0 && a.unRacional.p == 0)
		i =0;
	return i;
}
int esCeroZp(Coeficiente a){
	int i=1;
	if(a.unZp.n == 0)
		i =0;
	return i;
}
int esCeroCoef(Coeficiente a,enum tipoCoeficiente tipo){
	int i;
  //{RACIONALES, REALES, CUATERNIONES, GAUSSIANOS, GAUSSIANOSQ, ZP, COMPLEJOS, TOTAL}
	if (tipo==RACIONALES)
		i= esCeroQ(a);
	else if (tipo==REALES)
		i=esCeroR(a);
	else if (tipo == GAUSSIANOS)
		i=esCeroG(a);
	else if (tipo == GAUSSIANOSQ)
		i=esCeroGQ(a);
	else if (tipo==COMPLEJOS)
		i=esCeroC(a);
	else if (tipo==ZP)
		i=esCeroZp(a);
	else if (tipo == CUATERNIONES)
		i=esCeroH(a);
  return i;
}
//enum tipoCoeficiente {RACIONALES, REALES, CUATERNIONES, GAUSSIANOS, GAUSSIANOSQ, ZP, COMPLEJOS, TOTAL};

Coeficiente CopiaMenosCoef(Coeficiente a,enum tipoCoeficiente tipo){
	Coeficiente b;
   if (tipo==RACIONALES){
   	b.unRacional.p = -a.unRacional.p;
   	b.unRacional.q = a.unRacional.q;
	b.unRacional = simplificaQ(b.unRacional);
  } else if (tipo==REALES){
   	b.unReal.a = -a.unReal.a;
  } else if (tipo==ZP){
  	b.unZp.n = -a.unZp.n;
  } else if (tipo== CUATERNIONES){
  	b.unCuaternion.a = -a.unCuaternion.a;
  	b.unCuaternion.b = -a.unCuaternion.b;
  	b.unCuaternion.c = -a.unCuaternion.c;
  	b.unCuaternion.d = -a.unCuaternion.d;
  } else if(tipo == GAUSSIANOS){
  	b.unGaussiano.a = -a.unGaussiano.a;
  	b.unGaussiano.b = -a.unGaussiano.b;
  } else if(tipo == GAUSSIANOSQ){
  	b.unGaussianoQ.a.p = -a.unGaussianoQ.a.p;
  	b.unGaussianoQ.b.p = -a.unGaussianoQ.b.p;
  	b.unGaussianoQ.a = simplificaQ(a.unGaussianoQ.a);
  	b.unGaussianoQ.b = simplificaQ(b.unGaussianoQ.b);
  } else if(tipo == COMPLEJOS){
  	b.unComplejo.a = -a.unComplejo.a;
  	b.unComplejo.b = -a.unComplejo.b;
  }
  return b;
}
Coeficiente Cero(enum tipoCoeficiente tipo){
	Coeficiente b;
   if (tipo==RACIONALES){
   	b.unRacional.p= 0;
   	b.unRacional.q= 1;
  } else if (tipo==REALES){
   	b.unReal.a = 0.0;
  } else if (tipo==ZP){
  	b.unZp.n = 0;
  } else if (tipo== CUATERNIONES){
  	b.unCuaternion.a = 0.0;
  	b.unCuaternion.b = 0.0;
  	b.unCuaternion.c = 0.0;
  	b.unCuaternion.d = 0.0;
  } else if(tipo == GAUSSIANOS){
  	b.unGaussiano.a = 0;
  	b.unGaussiano.b = 0;
  } else if(tipo == GAUSSIANOSQ){
  	b.unGaussianoQ.a.p = 0;
  	b.unGaussianoQ.b.p = 0;
  	b.unGaussianoQ.a.q = 1;
  	b.unGaussianoQ.b.q = 1;
  } else if(tipo == COMPLEJOS){
  	b.unComplejo.a = 0.0;
  	b.unComplejo.b = 0.0;
  }
  return b;
}
H leeH(FILE *f){
	H a;
	fscanf(f,"%lg",&a.a);
	fscanf(f,"%lg",&a.b);
	fscanf(f,"%lg",&a.c);
	fscanf(f,"%lg",&a.d);
	return a;
}
H escribeH(H c,char buferTemporal[],FILE *f){
	//char buferTemporal[128];
	int l;
	if(c.a == 0.0 && c.b == 0.0 && c.c == 0.0 && c.d ==0.0)
		sprintf(buferTemporal,"0");
	else{
		sprintf(buferTemporal,"+(");
		l = strlen(buferTemporal);
		if(c.a!=0.0){
			sprintf(buferTemporal+l,"%+lg", c.a);
			if(c.b!=0.0){
				l = strlen(buferTemporal);
				if(c.b==1.0 || c.b==-1.0)
					sprintf(buferTemporal+l,"%s", c.b==1.0?"+i":"-i");
				else sprintf(buferTemporal+l,"%+lgi",c.b);
				if(c.c!=0.0){
					l = strlen(buferTemporal);
					if(c.c==1.0 || c.c==-1.0)
						sprintf(buferTemporal+l,"%s", c.c==1.0?"+j":"-j");
					else sprintf(buferTemporal+l,"%+lgj",c.c);
					if(c.d!=0.0){
						l = strlen(buferTemporal);
						if(c.d==1.0 || c.d==-1.0)
							sprintf(buferTemporal+l,"%s", c.d==1.0?"+k":"-k");
						else sprintf(buferTemporal+l,"%+lgk",c.d);
					}
				}
				else{
					if(c.d!=0.0){
						l = strlen(buferTemporal);
						if(c.d==1.0 || c.d==-1.0)
							sprintf(buferTemporal+l,"%s", c.d==1.0?"+k":"-k");
						else sprintf(buferTemporal+l,"%+lgk",c.d);
						}
				}
			}
			else{
				if(c.c!=0.0){
					l = strlen(buferTemporal);
					if(c.c==1.0 || c.c==-1.0)
						sprintf(buferTemporal+l,"%s", c.c==1.0?"+j":"-j");
					else sprintf(buferTemporal+l,"%+lgj",c.c);
					if(c.d!=0.0){
						l = strlen(buferTemporal);
						if(c.d==1.0 || c.d==-1.0)
							sprintf(buferTemporal+l,"%s", c.d==1.0?"+k":"-k");
						else sprintf(buferTemporal+l,"%+lgk",c.d);
					}
				}
				else{
					if(c.d!=0.0){
						l = strlen(buferTemporal);
						if(c.d==1.0 || c.d==-1.0)
							sprintf(buferTemporal+l,"%s", c.d==1.0?"+k":"-k");
						else sprintf(buferTemporal+l,"%+lgk",c.d);
						}
					}
				}
			}
		else{
			if(c.b!=0.0){
				if(c.b==1.0 || c.b==-1.0)
					sprintf(buferTemporal+l,"%s", c.b==1.0?"+i":"-i");
				else sprintf(buferTemporal+l,"%+lgi",c.b);
				if(c.c!=0.0){
					l = strlen(buferTemporal);
					if(c.c==1.0 || c.c==-1.0)
						sprintf(buferTemporal+l,"%s", c.c==1.0?"+j":"-j");
					else sprintf(buferTemporal+l,"%+lgj",c.c);
					if(c.d!=0.0){
						l = strlen(buferTemporal);
						if(c.d==1.0 || c.d==-1.0)
							sprintf(buferTemporal+l,"%s", c.d==1.0?"+k":"-k");
						else sprintf(buferTemporal+l,"%+lgk",c.d);
					}
				}
				else{
					l = strlen(buferTemporal);
					if(c.d!=0.0){
						if(c.d==1.0 || c.d==-1.0)
							sprintf(buferTemporal+l,"%s", c.d==1.0?"+k":"-k");
						else sprintf(buferTemporal+l,"%+lgk",c.d);
					}
				}
			}
			else{
				if(c.c!=0.0){
					if(c.c==1.0 || c.c==-1.0)
						sprintf(buferTemporal+l,"%s", c.c==1.0?"+j":"-j");
					else sprintf(buferTemporal+l,"%+lgj",c.c);
					if(c.d!=0.0){
						l = strlen(buferTemporal);
						if(c.d==1.0 || c.d==-1.0)
							sprintf(buferTemporal+l,"%s", c.d==1.0?"+k":"-k");
						else sprintf(buferTemporal+l,"%+lgk",c.d);
					}
				}
				else{
					if(c.d!=0.0){
						if(c.d==1.0 || c.d==-1.0)
							sprintf(buferTemporal+l,"%s", c.d==1.0?"+k":"-k");
						else sprintf(buferTemporal+l,"%+lgk",c.d);
					}
				}
			}
		}
	l = strlen(buferTemporal);
	sprintf(buferTemporal+l,")");
	}
	//fprintf(f,"%12s",buferTemporal);
}
H sumaH(H a , H b){
	H c;
	c.a = a.a + b.a;
	c.b = a.b + b.b;
	c.c = a.c + b.c;
	c.d = a.d + b.d;
	return c;
}
H restaH(H a ,H b){
	H c;
	c.a = a.a - b.a;
	c.b = a.b - b.b;
	c.c = a.c - b.c;
	c.d = a.d - b.d;
	return c;
}
H prodH(H a, H b)
{
  H ret={
    a.a*b.a - a.b*b.b - a.c*b.c - a.d*b.d,
    a.a*b.b + a.b*b.a + a.c*b.d - a.d*b.c,
    a.a*b.c - a.b*b.d + a.c*b.a + a.d*b.b,
    a.a*b.d + a.b*b.c - a.c*b.b + a.d*b.a
  };
  if (-EPSILON <= ret.a && ret.a <= EPSILON) ret.a = 0.0;
  if (-EPSILON <= ret.b && ret.b <= EPSILON) ret.b = 0.0;
  if (-EPSILON <= ret.c && ret.c <= EPSILON) ret.c = 0.0;
  if (-EPSILON <= ret.d && ret.d <= EPSILON) ret.d = 0.0;

  return ret;
}
H invH(H h)
{
  double norma2=h.a*h.a+h.b*h.b+h.c*h.c+h.d*h.d;
  H ret={h.a, -h.b, -h.c, -h.d};

  if (norma2==0.0) return h;
  ret.a/=norma2;
  ret.b/=norma2;
  ret.c/=norma2;
  ret.d/=norma2;

  if (-EPSILON <= ret.a && ret.a <= EPSILON) ret.a = 0.0;
  if (-EPSILON <= ret.b && ret.b <= EPSILON) ret.b = 0.0;
  if (-EPSILON <= ret.c && ret.c <= EPSILON) ret.c = 0.0;
  if (-EPSILON <= ret.d && ret.d <= EPSILON) ret.d = 0.0;

  return ret;
}
H divH(H a, H b)
{
  return prodH(a, invH(b));
}

double normaH(H a){
	double norma;
	norma = sqrt( a.a*a.a + a.b*a.b + a.c*a.c + a.d*a.d );
	return norma;
}
int mcd(int a, int b){                    
  int r;             
  if (a < 0) a=-a;
  if (b < 0) b=-b;
  if (b == 0) return a;

  while ((r=a%b) != 0){
    a = b;             
    b = r;             
  }                    

  return b;
}          

Q simplificaQ(Q a){                     
  int d;
  Q regreso;
  regreso = a;
  d = mcd (a.p, a.q);
  if (d>1){            
    regreso.p /= d;         
    regreso.q /= d;         
  }                    
  if (regreso.q < 0){       
    regreso.p *= -1;        
    regreso.q *= -1;        
  }

  return regreso;
}
Q sumaQ(Q a, Q b){                
  Q r;           

  r.p = a.p*b.q + a.q*b.p;
  r.q = a.q*b.q;
  r=simplificaQ(r);

  return r;
}
Q leeQ(FILE *f){
	Coeficiente a;
	fscanf(f,"%d",&a.unRacional.p);
	fscanf(f,"%d",&a.unRacional.q);
	//printf("%d/%d",a.unRacional.p,a.unRacional.q);
	a.unRacional = simplificaQ(a.unRacional);
	return a.unRacional;
}
Q restaQ(Q a, Q b){                
  Q r;           
  r.p = a.p*b.q - a.q*b.p;
  r.q = a.q*b.q;
  r=simplificaQ(r);

  return r;
}
Q prodQ(Q a, Q b){                
  Q r;           
  r.p = a.p*b.p;
  r.q = a.q*b.q;
  r=simplificaQ(r);
  //printf("%d/%d",r.p,r.q);
  return r;
}
Q divQ(Q a, Q b){                
  Q r;
  //printf("\n %d/%d \n %d/%d",a.p,a.q,b.p,b.q);
  r.p = a.p*b.q;
  r.q = a.q*b.p;
  r=simplificaQ(r);
  //printf("%d/%d\n",r.p,r.q);
  return r;
}
int escribeQ(Q a,char buferTemporal[],FILE *f){
  int l;
  sprintf(buferTemporal,"%+d", a.p);
  l  = strlen(buferTemporal);
  if (a.q!= 1) sprintf(buferTemporal+l,"/%d", a.q);
  return 0;
}

/* -----------------------------------------------------------------------------------------------------*/
GQ leeGQ(FILE *f){
	GQ a;
	a.a = leeQ(f);
	a.b = leeQ(f);
	return a;	
}
int escribeGQ(GQ a,char buferTemporal[],FILE *f){
	//char buferTemporal[128];}
	int l;
	if(a.a.p==0 && a.b.p ==0)
		sprintf(buferTemporal,"0");
	else{
		sprintf(buferTemporal,"+(");
		l = strlen(buferTemporal);
		if(a.a.p!=0){
			a.a = simplificaQ(a.a);
			escribeQ(a.a,buferTemporal+l,f);
			if(a.b.p!=0){
				l = strlen(buferTemporal);
				if(funQ(a.b))
					sprintf(buferTemporal+l,"%s",a.b.p==1?"+i":"-i");
				else{
					a.b = simplificaQ(a.b);
					/*if(a.b.p > 0){	
						escribeQ(a.b,buferTemporal+l,f);
					}
					else*/ escribeQ(a.b,buferTemporal+l,f);
					l = strlen(buferTemporal);
					sprintf(buferTemporal+l,"i");
				}
			}
		}else{
			if(a.b.p!=0){
				if(funQ(a.b))
					sprintf(buferTemporal+l,"%s",a.b.p==1?"i":"-i");
				else{
					a.b = simplificaQ(a.b);
					escribeQ(a.b,buferTemporal+l,f);
					sprintf(buferTemporal,"i");
				}
			}
		}
		l = strlen(buferTemporal);
		sprintf(buferTemporal+l,")");
		
	}
	//fprintf(f,"%12s",buferTemporal);
	return 0;
}
GQ sumaGQ(GQ a, GQ b){
	GQ c;
	c.a = sumaQ(a.a,b.a);
	c.b = sumaQ(a.b,b.b);
	return c;
}
GQ restaGQ(GQ a, GQ b){
	GQ c;
	c.a = restaQ(a.a,b.a);
	c.b = restaQ(a.b,b.b);
	return c;
}
GQ prodGQ(GQ a, GQ b){	
	GQ c;
	Q pa, pb;
	pa = prodQ(a.a,b.a);
	pb = prodQ(a.b,b.b);
	c.a = restaQ(pa,pb);
	c.b = sumaQ(pa,pb);
	c.b = sumaQ(prodQ(a.a,b.b),prodQ(a.b,b.a));
	return c;
}
GQ divGQ(GQ a, GQ b){
	GQ c;
	Q n;
	
	n = norma2GQ(b);
	b = conjGQ(b);
	
	c = prodGQ(a,b);
	
	c.a = divQ(c.a,n);
	c.b = divQ(c.b,n);
	return c;
}
Q norma2GQ(GQ a){
	Q n;
	n = sumaQ(prodQ(a.a,a.a),prodQ(a.b,a.b));
	return n;
}
GQ invGQ(GQ a){
	GQ c;
	Q n,na,nb;
	n = norma2GQ(a);
	c.a= divQ(a.a,n);
	
	c.b= divQ(a.b,n);
	c = conjGQ(c);
	return c;
}
int funNGQ(GQ a){
	Q n;
	n = norma2GQ(a);
	if(n.p == 0)
		return 0;
	else
		return 1;
}
GQ conjGQ(GQ a){
	a.b.p *= -1;
	a.b = simplificaQ(a.b);
	return a;
}
int funQ(Q a){
	if((a.p ==1 || a.p == -1) && (a.q ==1 || a.q ==-1 ))
		return 1;
	else
		return 0;
}
G leeG(FILE *f){
	G a;
	fscanf(f,"%d",&a.a);
	fscanf(f,"%d",&a.b);
	return a;
}
int escribeG(G a,char buferTemporal[], FILE *f){
	//char buferTemporal[128];
	int l;
	if(a.a!= 0 && a.b == 0)
		sprintf(buferTemporal,"%+d",a.a);
	else if(a.a!=0){
		sprintf(buferTemporal,"+(%+d",a.a);
		if(a.b!=0){
			l = strlen(buferTemporal);
			if(a.b == 1 || a.b == -1)
				sprintf(buferTemporal+l,"%s", a.b==1?"+i":"-i");
			else 
				sprintf(buferTemporal+l,"%+di", a.b);
		}
		l = strlen(buferTemporal);
		sprintf(buferTemporal+l,")");
	}else{
		if(a.b!=0){
			if(a.b == 1 || a.b == -1)
				sprintf(buferTemporal,"%s", a.b==1?"+i":"-i");
			else 
				sprintf(buferTemporal,"%+di", a.b);
		}else
			sprintf(buferTemporal,"0");
	}
	//fprintf(f,"%8s",buferTemporal);
	return 0;
}
G sumaG(G a, G b){
	G c;
	c.a = a.a + b.a;
	c.b = a.b + b.b;
	return c;
}
G restaG(G a, G b){
	G c;
	c.a = a.a - b.a;
	c.b = a.b - b.b;
	return c;
}
G prodG(G a, G b){
	G c;
	c.a = (a.a*b.a) - (a.b*b.b); 
	c.b = (a.a*b.b) + (a.b*b.a);
	return c;
}
G divG(G a, G b){
	G c;
	c.a = (a.a*b.a + a.b*b.b)/(b.a*b.a + b.b*b.b); 
	c.b = (a.b*b.a - a.a*b.b)/(b.a*b.a + b.b*b.b);
	return c;
}

C leeC(FILE *f){
	C a;
	fscanf(f,"%lg",&a.a);
	fscanf(f,"%lg",&a.b);
	//printf("Hola %lg\n",a.a);
	return a;
}
int escribeC(C c,/*char a[],*/char buferTemporal[],FILE *f){
	//char buferTemporal[128];
	int l,m;
	//m = strlen(buferTemporal);
	l = strlen(buferTemporal);
	//char *buferTemporal = &a;
	if(c.a==0.0 && c.b==0.0)
		sprintf(buferTemporal+l,"0");
	else{
		if(c.a!=0.0){
			sprintf(buferTemporal+l,"+(%lg",c.a);
			l = strlen(buferTemporal);
			if(c.b != 0.0){
				if(c.b == 1.0 || c.b== -1.0){
					sprintf(buferTemporal+l,"%s", c.b==1.0?"+i":"-i");
				}else
					sprintf(buferTemporal+l,"%+lgi",c.b);
			}
			l = strlen(buferTemporal);
			sprintf(buferTemporal+l,")");
		}else
			if(c.b == 1.0 || c.b== -1.0)
				sprintf(buferTemporal,"%s", c.b==1.0?"i":"-i");
			else
				sprintf(buferTemporal,"%+lgi",c.b);
	}
	//sprintf(C,"%s",buferTemporal);
	//fprintf(f,"%10s",buferTemporal);
	//sprintf(buferTemporal,"complejo");
	return 0;
}
C sumaC(C a,C b){
	C c;
	c.a = a.a + b.a;
	c.b = a.b + b.b;
	//printf("Suma");
	//printf("%lg",a.a);
	//printf("%lg+ %lgi",c.a,c.b);
	return c;
}
C restaC(C a,C b){
	C c;
	c.a = a.a - b.a;
	c.b = a.b - b.b;
	return c;
}
C prodC(C a,C b){
	C c;
	c.a = (a.a*b.a) - (a.b*b.b);
	c.b = (a.a*b.b)+(a.b*b.a);
	return c;
}
C divC(C a,C b){
	C c;
	double n;
	n = normaC(b);
	n*=n;
	c.a = (a.a*b.a + a.b*b.b)/(n);
	c.b = (a.b*b.a - a.a*b.b)/(n);
	return c;
}
double normaC(C a){
	double n;
	n = sqrt(a.a*a.a + a.b*a.b);
	return n;
}


R leeR(FILE *f){
	R a;
	fscanf(f,"%lg",&a.a);
	return a;
}
int escribeR(R a,char buferTemporal[],FILE *f){
	sprintf(buferTemporal,"%+lg",a.a);
	return 0;
}
R sumaR(R a,R b){
	R c;
	c.a = a.a + b.a;
	return c;
}
R restaR(R  a,R  b){
	R c;
	c.a = a.a-b.a;
	return c;
}
R prodR(R a,R  b){
	R c;
	c.a = a.a*b.a;
	return c;
}
R divR(R  a,R  b){
	R c;
	c.a = a.a/b.a;
	return c;
}
//enum tipoCoeficiente {RACIONALES, REALES, CUATERNIONES, GAUSSIANOS, GAUSSIANOSQ, ZP, COMPLEJOS, TOTAL};
Coeficiente leerCoef(enum tipoCoeficiente tipo,FILE *f){/*{RACIONALES, REALES, CUATERNIONES, GAUSSIANOS, GAUSSIANOSQ, ZP, COMPLEJOS, TOTAL}*/
	Coeficiente a;
	if(tipo == RACIONALES)
		a.unRacional = leeQ(f);
	else if (tipo == REALES)
		a.unReal = leeR(f);
	else if (tipo ==CUATERNIONES)
		a.unCuaternion = leeH(f);
	else if (tipo == GAUSSIANOS)
		a.unGaussiano = leeG(f);
	else if(tipo == GAUSSIANOSQ)
		a.unGaussianoQ = leeGQ(f);
	else if(tipo == ZP)
		a.unZp = LeeZp(f);
	else if(tipo == COMPLEJOS){
		a.unComplejo = leeC(f);}
	return a;
}
int escribeCoef(Coeficiente a, char c[],enum tipoCoeficiente tipo,FILE *f){
   if (tipo==RACIONALES){
    escribeQ(a.unRacional,c,f);
  } else if (tipo==REALES){
  	escribeR(a.unReal,c,f);
  } else if (tipo==ZP){
	escribeZp(a.unZp,c,f);
  } else if (tipo== CUATERNIONES){
  	escribeH(a.unCuaternion,c,f);
  } else if(tipo == GAUSSIANOS){
  	escribeG(a.unGaussiano,c,f);
  } else if(tipo == GAUSSIANOSQ){
  	escribeGQ(a.unGaussianoQ,c,f);
  } else if(tipo == COMPLEJOS){
  	escribeC(a.unComplejo,c,f);
  } else if(tipo == TOTAL){
  	//sprintf(buferTemporal,)
  }
  //fprintf(f,"%s",buferTemporal);
  return 0;
  }

Zp LeeZp(FILE *f){
	Zp a;
	a.p = p;
	fscanf(f,"%d",&a.n);
	//printf("ZP");
	a = simplificaZp(a);
	//printf("lee");
	return a;
}
int escribeZp(Zp a, char buferTemporal[],FILE *f){
	a = simplificaZp(a);
	sprintf(buferTemporal,"%+d",a.n);
	return 0;
}
Zp sumaZp(Zp a, Zp b){
	Zp c;
	c.p = a.p;
	c.n = a.n + b.n;
	c = simplificaZp(c);
	return c;
}
Zp restaZp(Zp a, Zp b){
	Zp c;
	c.p = a.p;
	c.n = a.n - b.n;
	c = simplificaZp(c);
	return c;
}
Zp prodZp(Zp a, Zp b){
	Zp c;
	c.p = a.p;
	c.n = a.n * b.n;
	c = simplificaZp(c);
	return c;
}
Zp invZp(Zp n){
  int a, b, s, q, r, s0, s_1;
  a = n.n;
  b = n.p;
  s0=0;
  s_1=1;
  while((r=a%b)!=0){
	q = a/b;
	a=b;
	b=r;
	s=s0;
	s0=s_1 - q*s0;
	s_1=s;
  }
  //printf("To bien");
  n.n = s0;
  n = simplificaZp(n);
  return n;
}
Zp divZp(Zp a,Zp b){
	Zp c,d;
	d.p = p;
	c.p = a.p;
	d = invZp(b);
	//printf("0");
	c = prodZp(a,d);
	//printf("1");
	c = simplificaZp(c);
	//printf("2");
	return c;
}
Zp simplificaZp(Zp a){
	a.n = ((a.n%p)+p)%p;
	return a;
}
Zp raizZp(Zp a){
	Zp b;
	int r,i;
	b.n= -1;
	for(i=0;i<a.p;i++){
		if((i*i)%a.p == i ){
			if(b.n==-1)
				b.n = i;
			else
				b.p=i;
		}
	}
	return b;
}

P leeP(enum tipoCoeficiente tipo,FILE *f){
	P a;
	int i;
	//printf("a");
	fscanf(f,"%d",&a.g);
	//printf("\n%d\n",a.g);
	if((a.c=(Coeficiente*)malloc((a.g+1)*sizeof(Coeficiente)))==NULL){
		printf("LEE: ");
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
	//char* buferTemporal;
	char buferTemporal[500];
	buferTemporal[0] =  '\0';
	//buferTemporal:NULL;
	int l=0;
	//char aux[128];
	int k = 5;
	if(a.g<0){
		sprintf(buferTemporal,"0");
		fprintf(f,"%%ds",k,buferTemporal);
		return 0;
	}
	for(i=a.g;i>1;i--)
		if(esCeroCoef(a.c[i],tipo)){
			l = strlen(buferTemporal);
			escribeCoef(a.c[i],buferTemporal+l,tipo,f);
			l = strlen(buferTemporal);
			sprintf(buferTemporal+l,"x^%d",i);
		}
		//printf("A");
	if(a.g>=1 && esCeroCoef(a.c[1],tipo)){
			l = strlen(buferTemporal);
			escribeCoef(a.c[1],buferTemporal+l,tipo,f);
			l = strlen(buferTemporal);
			//sprintf(aux,"%s x",buferTemporal);
			sprintf(buferTemporal+l,"x");
	}
	l = strlen(buferTemporal);
	if(esCeroCoef(a.c[0],tipo))
		escribeCoef(a.c[0],buferTemporal+l,tipo,f);
	
	//printf("B");
	fprintf(f,"%220s",buferTemporal);
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





int leeM(MATRIZ *a,enum tipoCoeficiente tipo,FILE *f){
	int i,j,m,n;
	fscanf(f,"%d %d",&n,&m);
	*a = creaEspacioMatriz(m,n);
	for(i=0;i<m;i++){
		printf("\nr\n");
		for(j=0;j<n;j++){
			a->a[i][j] = leeP(tipo,f);
			printf("c");
		}
	}
	printf("a");
	return 0;
}
  
MATRIZ sumaM(MATRIZ X, MATRIZ Y,void *oper, enum tipoCoeficiente tipo,FILE *f)
{
  MATRIZ porRegresar;
  int i, j;
  porRegresar.m = porRegresar.n = 0;
  if ( (X.m!=Y.m) || (X.n!=Y.n)){
    fprintf(f,"No se puede realizar la suma de las matrices...\n");
    return porRegresar;
  }
  porRegresar.m = X.m;
  porRegresar.n = X.n;
  
  porRegresar = creaEspacioMatriz(X.m,X.n);
  
  for (i=0; i<X.m; i++)
    for (j=0; j<X.n; j++)
      porRegresar.a[i][j] = sumaP(X.a[i][j],Y.a[i][j],oper,tipo);
  return porRegresar;
}

MATRIZ restaM(MATRIZ X, MATRIZ Y,void *oper, enum tipoCoeficiente tipo,FILE *f)
{
  MATRIZ porRegresar;
  int i, j;
  porRegresar.m = porRegresar.n = 0;
  if ( (X.m!=Y.m) || (X.n!=Y.n)){
    fprintf(f,"No se puede realizar la suma de las matrices...\n");
    return porRegresar;
  }
  porRegresar.m = X.m;
  porRegresar.n = X.n;
  
  porRegresar = creaEspacioMatriz(X.m,X.n);
  
  for (i=0; i<X.m; i++)
    for (j=0; j<X.n; j++)
      porRegresar.a[i][j] = restaP(X.a[i][j],Y.a[i][j],oper,tipo);
  return porRegresar;
}
MATRIZ prodM(MATRIZ X, MATRIZ Y,void *operS, void *operP, enum tipoCoeficiente tipo,FILE *f)
{
  MATRIZ porRegresar;
  int i, j, k,grad;

  porRegresar.m = porRegresar.n = 0;

  if (X.n!=Y.m){
    fprintf(f,"No se puede realizar la suma de las matrices...\n");
    return porRegresar;
  }
  porRegresar.m = X.m;
  porRegresar.n = Y.m;

  porRegresar = creaEspacioMatriz(X.m,X.n);
  
  for (i=0; i<porRegresar.m; i++)
    for (j=0; j<porRegresar.n; j++){
    	if((porRegresar.a[i][j].c=(Coeficiente*)malloc((X.a[i][j].g + Y.a[i][j].g+1)*sizeof(Coeficiente)))==NULL){
  			  printf("error al generar espacio.\n");
   			  porRegresar.a[i][j].g = -1;
    		  break;}
    	for(k=0;k <X.a[i][j].g + Y.a[i][j].g;k++)
    		  porRegresar.a[i][j].c[k] = Cero(tipo);   		
    	porRegresar.a[i][j].g = -1;
	}
  for (i=0; i<porRegresar.m; i++)
    for (j=0; j<porRegresar.n; j++)
    	for (k=0; k<porRegresar.m;k++)
			porRegresar.a[i][j] = sumaP(porRegresar.a[i][j], multP(X.a[i][k],Y.a[k][j],operS,operP,tipo),operS,tipo);

  return porRegresar;
}

int escribeM(MATRIZ X, enum tipoCoeficiente tipo,FILE *f)
{
  int i, j,k,l;
  for (i=0; i<X.m; i++){
    for (j=0; j<X.n; j++){
	  escP(X.a[i][j],tipo,f);
      fprintf(f," ");
    }
    fprintf(f,"\n");
  }
  return 0;
}

MATRIZ creaEspacioMatriz(int m, int n){
  MATRIZ ret={m:m, n:n, a:NULL}; 
  int i;
  ret.a = (P**)malloc(m*sizeof(P*));
  if (ret.a!=NULL){
    for(i=0; i<m; i++){
      ret.a[i] = (P *)malloc(n*sizeof(P));
      if (ret.a[i]==NULL){
        while(i>0){
          free(ret.a[--i]);
          ret.a[i] = NULL;
        }
        break;
      }
    }
  }
  return ret;
}

int liberaEspacioMatriz(MATRIZ *mat)
{
  int i;
  for (i=0; i<mat->m; i++){
    free(mat->a[i]);
    mat->a[i]=NULL;
  }
  free(mat->a);
  mat->a=NULL;
  mat->m = mat->n = 0;
  return 0;
}


