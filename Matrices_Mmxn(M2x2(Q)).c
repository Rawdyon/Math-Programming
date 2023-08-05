#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>    
#include <string.h>  
#include <math.h>
typedef struct _Q_{
	int p,q;
}Q;
typedef struct _Qmatriz_{
	Q A[2][2];
	//Q a,b,c,d;
}MQ;
typedef struct _M_{
	int m,n;
	MQ **A;
}M;
/*----------------------------------------------*/
int mcd(int a, int b);
Q sumaQ(Q a, Q b);   
Q prodQ(Q a, Q b);
Q leeQ(void);
Q simplificaQ(Q a);
int escribeQ(Q a);
MQ sumaMQ(MQ A, MQ B);
MQ prodMQ(MQ A, MQ B);
MQ leeMQ(void);
void escribeMQ(MQ A);
/*-------------------------------------------------*/
M creaEspacioMatriz(int m, int n);
int leeMatriz(M *mat);
int escMatriz(M mat);
int liberaEspacioMatriz(M *mat);
M sumaM(M X, M Y);
M prodM(M X, M Y);
int m,n;


int main(int argc, char *argv[])
{
  M a, b, r;
  int i, j, k;
  
  printf("Digite numero de renglones entre 1 y 30:");
  do{
  	scanf("%d", &m);
  }while(m<1||m>30);
  
  printf("Digite numero de columnas entre 1 y 30:");
  do{
  	scanf("%d", &n);
  }while(n<1||n>30);
  
  printf("Este programa suma, resta y multiplica matrices de mxn \n");
  printf("Por leer la primera matriz \n");
  leeMatriz(&a);
  printf("Por leer la segunda matriz \n");
  leeMatriz(&b);
  printf("las matrices a sumar son:\n\tPrimera matriz mxn (%d x %d):\n", a.m, a.n);
  escMatriz(a);
  printf("\n\tSegunda matriz mxn (%d x %d):\n", b.m, b.n);
  escMatriz(b);
  r = sumaM(a, b);
  printf("\nLa suma es una matriz  mxn (%d x %d):\n", r.m, r.n);
  escMatriz(r);
  liberaEspacioMatriz(&r); 
  
  /*if(a.n != b.m)
  	printf("\nEl producto no se puede realizar.");
  else{
  	r = prodM(a, b);
	printf("\nEl producto es una matriz  mxn (%d x %d):\n", r.m, r.n);
	escMatriz(r);
    liberaEspacioMatriz(&r);
  }*/
  liberaEspacioMatriz(&a);
  liberaEspacioMatriz(&b);
  system("pause");
  return 0;
}

/*----------------------------------------------------------------------------------------*/
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
Q leeQ(void){
	Q a;
	do{
	printf("Escriba el numerador: ");
	scanf("%d",&a.p);
	printf("Escriba el denominador: ");
	scanf("%d",&a.q);
	}while(a.q==0);
	a = simplificaQ(a);
	return a;
}

/*----------------------------------------------------------------------------------------------------------*/

Q prodQ(Q a, Q b){                
  Q r;           
  r.p = a.p*b.p;
  r.q = a.q*b.q;
  r=simplificaQ(r);
  return r;
}
int escribeQ(Q a){
  char buferTemporal[128];
  int l;
  sprintf(buferTemporal,"%d", a.p);
  l = strlen(buferTemporal);
  if(a.q!= 1) sprintf(buferTemporal+l,"/%d", a.q);
  printf("%6s",buferTemporal);
}

/*==============================================================================*/
MQ sumaMQ(MQ A, MQ B){
	MQ ret; 
	ret.A[0][0] = sumaQ(A.A[0][0],B.A[0][0]);
	ret.A[0][1] = sumaQ(A.A[0][1],B.A[0][1]);
	ret.A[1][0] = sumaQ(A.A[1][0],B.A[1][0]);
	ret.A[1][1] = sumaQ(A.A[1][1],B.A[1][1]);
	/*ret.a = sumaQ(A.a,B.a);
	ret.b = sumaQ(A.b,B.b);
	ret.c = sumaQ(A.c,B.c);
	ret.d = sumaQ(A.d,B.d);*/
	return ret;
}

MQ prodMQ(MQ A,MQ B){
	MQ ret;
	ret.A[0][0] = sumaQ(prodQ(A.A[0][0],B.A[0][0]),prodQ(A.A[0][1],B.A[1][0]));
	ret.A[0][1] = sumaQ(prodQ(A.A[0][0],B.A[0][1]),prodQ(A.A[0][1],B.A[1][1]));
	ret.A[1][0] = sumaQ(prodQ(A.A[1][0],B.A[0][0]),prodQ(A.A[1][1],B.A[1][0]));
	ret.A[1][1] = sumaQ(prodQ(A.A[1][0],B.A[0][1]),prodQ(A.A[1][1],B.A[1][1]));/*
	ret.a = sumaQ(prodQ(A.a,B.a),prodQ(A.b,B.c));
	ret.b = sumaQ(prodQ(A.a,B.b),prodQ(A.b,B.d));
	ret.c = sumaQ(prodQ(A.c,B.a),prodQ(A.d,B.c));
	ret.d = sumaQ(prodQ(A.c,B.b),prodQ(A.d,B.d));*/
	return ret;
}

MQ leeMQ(void){
	MQ ret;
	ret.A[0][0] = leeQ();
	ret.A[0][1] = leeQ();
	ret.A[1][0] = leeQ();
	ret.A[1][1] = leeQ();
	return ret;
}
void escribeMQ(MQ A){
	int i,j;
	printf("[");
	escribeQ(A.A[0][0]);
	printf(" ");
	escribeQ(A.A[0][1]);
	printf(",");
	escribeQ(A.A[1][0]);
	printf(" ");
	escribeQ(A.A[1][1]);
	printf("]");
}



/*------------------------------------------------------------------------------*/
M creaEspacioMatriz(int m, int n){
  M ret={m:m, n:n, A:NULL};
  int i;
  ret.A = (MQ**)malloc(m*sizeof(MQ*));
  if (ret.A!=NULL){
    for(i=0; i<m; i++){
      ret.A[i] = (MQ *)malloc(n*sizeof(MQ));
      if (ret.A[i]==NULL){
        while(i>0){
          free(ret.A[--i]);
          ret.A[i] = NULL;
        }
        break;
      }
    }
  }
  return ret;
}
int leeMatriz(M *mat){
  int i, j;

  if (mat == NULL) return -1; 
  /*printf("Digite numero de renglones m:");
  scanf("%d", &m);
  printf("Digite numero de columnas n:");
  scanf("%d", &n)*/;
  *mat = creaEspacioMatriz(m, n);
  //printf("Digite las entradas de la matriz:\n");
  for(i=0; i<m; i++)
    for (j=0; j<n; j++){
      printf("[%2d, %2d]=", i+1, j+1);
      mat->A[i][j] = leeMQ();
	}
  
  return 0; 
}
int escMatriz(M mat){
  int i, j;
  for (i=0; i<mat.m; i++){
    printf("\n");
    for (j=0; j<mat.n; j++)
      escribeMQ(mat.A[i][j]);
  }
  printf("\n");
  return 0;
}
int liberaEspacioMatriz(M *mat){
  int i;

  for (i=0; i<mat->m; i++){
    free(mat->A[i]);
    mat->A[i]=NULL;
  }
  free(mat->A);
  mat->A=NULL;
  mat->m = mat->n = 0;

  return 0;
}

M sumaM(M X, M Y){
  M porRegresar;
  int i, j;
  porRegresar.m = porRegresar.n = 0;
  porRegresar = creaEspacioMatriz(X.m,X.n);
  for (i=0; i<X.m; i++)
    for (j=0; j<X.n; j++)
      porRegresar.A[i][j] = sumaMQ(X.A[i][j],Y.A[i][j]);
  return porRegresar;
}

M prodM(M X, M Y){
  M porRegresar;
  int i, j, k;
  porRegresar.m = porRegresar.n = 0;
  if (X.n!=Y.m){
    printf("No se puede realizar el producto de las matrices...\n");
    return porRegresar;} 
  porRegresar = creaEspacioMatriz(X.m,Y.n);
  for (i=0; i<porRegresar.m; i++)
    for (j=0; j<porRegresar.n; j++){
		porRegresar.A[i][j].A[0][0].p= 0;
		porRegresar.A[i][j].A[0][1].p= 0;
		porRegresar.A[i][j].A[1][0].p= 0;
		porRegresar.A[i][j].A[1][1].p= 0;
		porRegresar.A[i][j].A[0][0].q= 1;
		porRegresar.A[i][j].A[0][1].q= 1;
		porRegresar.A[i][j].A[1][0].q= 1;
		porRegresar.A[i][j].A[1][1].q= 1;
	}
	
  for (i=0; i<porRegresar.m; i++)
    for (j=0; j<porRegresar.n; j++)
      for (k=0;k<Y.m;k++)
		porRegresar.A[i][j] = sumaMQ(porRegresar.A[i][j], prodMQ(X.A[i][k],Y.A[k][j]));
  return porRegresar;
}
