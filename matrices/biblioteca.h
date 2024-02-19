#ifndef _BIB_
#define _BIB_
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
typedef struct _P_{
	int g;
	Coeficiente *c;
}P;
typedef struct _matriz_{
  int n,m;
  P **a;
}MATRIZ;





H leeH(FILE *f);
H escribeH(H c,char buferTemporal[],FILE *f);
H sumaH(H a , H b);
H restaH(H a , H b);
H prodH(H a , H b);
H invH(H h);
H divH(H a ,H b);
double normaH(H b);

G leeG(FILE *f);
int escribeG(G a,char buferTemporal[], FILE *f);
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
int escribeQ(Q a,char buferTemporal[],FILE *f);
Q norma2GQ(GQ a);
int funQ(Q a);

GQ leeGQ(FILE *f);
int escribeGQ(GQ a,char buferTemporal[],FILE *f);
GQ sumaGQ(GQ a, GQ b);
GQ restaGQ(GQ a, GQ b);
GQ prodGQ(GQ a, GQ b);
GQ divGQ(GQ a, GQ b);
int funNGQ(GQ a);
GQ invGQ(GQ a);
GQ conjGQ(GQ a);

C leeC(FILE *f);
int escribeC(C c,char buferTemporal[],FILE *f);
C sumaC(C a,C b);
C restaC(C a,C b);
C prodC(C a,C b);
C divC(C a,C b);
double normaC(C a);

R leeR(FILE *f);
int escribeR(R a,char buferTemporal[],FILE *f);
R sumaR(R a,R b);
R restaR(R a,R b);
R prodR(R a,R b);
R divR(R a,R b);

Zp LeeZp(FILE *f);
int escribeZp(Zp a,char buferTemporal[],FILE *f);
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
int escribeCoef(Coeficiente ret,char c[], enum tipoCoeficiente tipo,FILE *f);
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



P leeP(enum tipoCoeficiente tipo,FILE *f);
P sumaP(P a, P b,void *oper,enum tipoCoeficiente tipo);
P restaP(P a, P b,void *oper,enum tipoCoeficiente tipo);
P multP(P a, P b,void *oper,void *operA,enum tipoCoeficiente tipo);
P multMonomioP(P a, Coeficiente c, int e,void *oper,enum tipoCoeficiente tipo);
P divP(P a, P b, P *r,void *oper,void *operD,void *operR,enum tipoCoeficiente tipo);
int escP(P a,enum tipoCoeficiente tipo,FILE *f);
P copiaMenosP(P a,enum tipoCoeficiente tipo);
P copiaP(P a);
int esCeroP(P a);

int leeM(MATRIZ *a,enum tipoCoeficiente tipo,FILE *f);
int escribeM(MATRIZ X, enum tipoCoeficiente tipo,FILE *f);
MATRIZ restaM(MATRIZ X, MATRIZ Y,void *oper, enum tipoCoeficiente tipo,FILE *f);
MATRIZ sumaM(MATRIZ X, MATRIZ Y,void *oper, enum tipoCoeficiente tipo,FILE *f);
MATRIZ prodM(MATRIZ X, MATRIZ Y,void *operS, void *operP,enum tipoCoeficiente tipo,FILE *f);
MATRIZ creaEspacioMatriz(int m, int n);
int liberaEspacioMatriz(MATRIZ *mat);


#ifdef __cplusplus
}
#endif

#endif
