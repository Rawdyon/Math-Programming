#include <stdio.h>
#include <stdlib.h>

#include "logo.h"
#include "nestedtriangle.h"

int nivelN;
double longitudN;
double miX0N;
double miY0N;
LOGO *tortugaAuxN;


int Nest(double l, int nivel, LOGO *tortuga);
int Nested(double l, int nivel,LOGO *tortuga);

int iniciaNest(int n, double l, double x, double y, LOGO *tortuga)
{
  nivelN=n;
  longitudN = l;
  miX0N=x;
  miY0N=y;
  tortugaAuxN = tortuga;
  return 0;
}

int dibujaNest(void){
  inicia(miX0N, miY0N, 0, ABAJO, tortugaAuxN);
  return Nest(longitudN,nivelN, tortugaAuxN);
}
int Nest(double l, int nivel, LOGO *tortuga){
	Nested(l,nivel,tortuga);
	return 0;
}
int Nested(double l, int nivel,LOGO *tortuga){
	int i;
	if(nivel ==0)
		return 0;
	for(i = 0;i<3;i++){
		Nested(l/2,nivel-1,tortuga);
		avanza(l,tortuga);
		der(120,tortuga);
	}
	return 0;
}
