#ifndef _TIPOS_
#define _TIPOS_
#ifdef __cplusplus
extern "C" {
#endif

enum tipoCoeficiente {RACIONALES, REALES,CUATERNIONES, GAUSSIANOS, GAUSSIANOSQ, ZP, COMPLEJOS, TOTAL};

  
typedef struct _racionales_{
  int p, q;
}Q;
typedef struct _complejos_{
  double a, b;
}C;
typedef struct _cuaternion_ {
	double a,b,c,d;	
}H;
typedef struct _Gaussiano_{
	int a,b;
}G;
typedef struct _GaussianoG_{
	Q a,b;
}GQ;
typedef struct _Real_{
	double a;
}R;
typedef struct _Zp_{
	int p;
	int n;
}Zp;

typedef union _coeficiente_{
  Q unRacional;
  R unReal;
  H unCuaternion;
  C unComplejo;
  G unGaussiano;
  GQ unGaussianoQ;
  Zp unZp;
}Coeficiente;

H leeH(FILE *f);
H escribeH(H c,FILE *f);
H sumaH(H a , H b);
H restaH(H a , H b);
H prodH(H a , H b);
H invH(H h);
H divH(H a ,H b);
double normaH(H b);

G leeG(FILE *f);
int escribeG(G a,FILE *f);
G sumaG(G a, G b);
G restaG(G a, G b);
G prodG(G a, G b);
G divG(G a, G b);
int funNG(G a);
G invG(G a);
G conjG(G a);

int mcd(int a, int b);
Q sumaQ(Q a, Q b);    
Q restaQ(Q a, Q b);
Q prodQ(Q a, Q b);
Q divQ(Q a, Q b);
Q leeQ(FILE *f);
Q simplificaQ(Q a);
int escribeQ(Q a,FILE *f);
Q norma2GQ(GQ a);
int funQ(Q a);

GQ leeGQ(FILE *f);
int escribeGQ(GQ a,FILE *f);
GQ sumaGQ(GQ a, GQ b);
GQ restaGQ(GQ a, GQ b);
GQ prodGQ(GQ a, GQ b);
GQ divGQ(GQ a, GQ b);
int funNGQ(GQ a);
GQ invGQ(GQ a);
GQ conjGQ(GQ a);

C leeC(FILE *f);
int escribeC(C a,FILE *f);
C sumaC(C a,C b);
C restaC(C a,C b);
C prodC(C a,C b);
C divC(C a,C b);
double normaC(C a);

R leeR(FILE *f);
int escribeR(R a,FILE *f);
R sumaR(R a,R b);
R restaR(R a,R b);
R prodR(R a,R b);
R divR(R a,R b);

Zp LeeZp(FILE *f);
int escribeZp(Zp a,FILE *f);
Zp sumaZp(Zp a, Zp b);
Zp restaZp(Zp a, Zp b);
Zp prodZp(Zp a, Zp b);
Zp invZp(Zp n);
Zp divZp(Zp a, Zp b);
Zp simplificaZp(Zp a);
Zp raizZp(Zp a);



int muestraA(void *a, void *b, void *suma, enum tipoCoeficiente tipo);
int muestraB(Coeficiente a, Coeficiente b, void *suma, enum tipoCoeficiente tipo);
Coeficiente opera(Coeficiente a, Coeficiente b, void *suma, enum tipoCoeficiente tipo);
int esccoef(Coeficiente a,enum tipoCoeficiente tipo,FILE *f);
int escribeCoef(Coeficiente ret, enum tipoCoeficiente tipo,FILE *f);
Coeficiente leerCoef(enum tipoCoeficiente tipo, FILE *f);

Coeficiente CopiaMenosCoef(Coeficiente a,enum tipoCoeficiente tipo);
int esCeroCoef(Coeficiente a,enum tipoCoeficiente tipo);
int esCeroQ(Coeficiente a);
int esCeroR(Coeficiente a);
int esCeroH(Coeficiente a);
int esCeroG(Coeficiente a);
int esCeroGQ(Coeficiente a);
int esCeroZp(Coeficiente a);
int esCeroC(Coeficiente a);


Coeficiente Cero(enum tipoCoeficiente tipo);



int p;



#ifdef __cplusplus
}
#endif

#endif
