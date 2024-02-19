#ifndef _POLI_
#define _POLI_
#ifdef __cplusplus
extern "C" {
#endif

typedef struct _P_{
	int g;
	Coeficiente *c;
}P;

P leeP(enum tipoCoeficiente tipo,FILE *f);
P sumaP(P a, P b,void *oper,enum tipoCoeficiente tipo);
P restaP(P a, P b,void *oper,enum tipoCoeficiente tipo);
//P prodP(P a, P b,void *oper,void *opera,enum tipoCoeficiente tipo);
P multP(P a, P b,void *oper,void *operA,enum tipoCoeficiente tipo);
P multMonomioP(P a, Coeficiente c, int e,void *oper,enum tipoCoeficiente tipo);
P divP(P a, P b, P *r,void *oper,void *operD,void *operR,enum tipoCoeficiente tipo);
int escP(P a,enum tipoCoeficiente tipo,FILE *f);
P copiaMenosP(P a,enum tipoCoeficiente tipo);
P copiaP(P a);
int esCeroP(P a);

#ifdef __cplusplus
}
#endif

#endif
