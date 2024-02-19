
#include <stdio.h>
#include <stdlib.h>

#include "logo.h"
#include "corner.h"

int angCorner;
double limCorner;
double longitudCorner;
double miX0Corner;
double miY0Corner;
LOGO *tortugaAuxCorner;
int dibujaCorner(void);
int Cornerpoly(int ang, int TT, double l, LOGO *tortuga);
int Cornerpolystep(int ang,double l, LOGO *tortuga);
int iniciaCorner(int ang,double l,double lim,double x,double y, LOGO *tortuga);

int iniciaCorner(int ang,double l,double lim,double x,double y, LOGO *tortuga){
	angCorner=ang;
	limCorner = lim;
	longitudCorner = l;
	miX0Corner = x;
	miY0Corner = y;
	tortugaAuxCorner = tortuga;
	return 0;
}

int dibujaCorner(void){
	inicia(miX0Corner,miY0Corner,0,ABAJO,tortugaAuxCorner);
	return Cornerpoly(angCorner,0,longitudCorner,tortugaAuxCorner);
}


int Cornerpoly(int ang, int TT, double l, LOGO *tortuga){
	if(l<=limCorner)
		return 0;
	Cornerpolystep(ang,l,tortuga);
	TT+=ang;
	if((TT%360)!=0)
		Cornerpoly(ang,TT,l,tortuga);
	return 0;
}
int Cornerpolystep(int ang,double l, LOGO *tortuga){
	avanza(l,tortuga);
	Cornerpoly(-ang, 0,l/2.0,tortuga);
	der(ang,tortuga);
	return 0;
}
