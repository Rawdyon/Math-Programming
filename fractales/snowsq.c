
#include <stdio.h>
#include <stdlib.h>

#include "logo.h"
#include "snowsq.h"

int nivelSnow;
double longitudSnow;
double miX0Snow;
double miY0Snow;
LOGO *tortugaAuxSnow;

int iniciaSnow(int nivel, double l, double x, double y, LOGO *tortuga);
int dibujaSnow(void);
int Snow(double l, int nivel, LOGO *tortuga);
int Edge(double l, int nivel, LOGO *tortuga);


int iniciaSnow(int nivel, double l, double x,double y, LOGO *tortuga){
	longitudSnow = l;
	nivelSnow = nivel;
	miX0Snow = x;
	miY0Snow = y;
	tortugaAuxSnow = tortuga;
	return 0;
}
int dibujaSnow(void){
	inicia(miX0Snow,miY0Snow,0,ABAJO,tortugaAuxSnow);
	return Snow(longitudSnow,nivelSnow,tortugaAuxSnow);
}
int Snow(double l, int nivel,LOGO *tortuga){
	int i;
	for(i=0;i<4;i++){
		Edge(l,nivel,tortuga);
		der(90,tortuga);
	}
	return 0;
}
int Edge(double l, int nivel, LOGO *tortuga){
	double unit;
	if(nivel==0){
		avanza(l,tortuga);
		return 0;
	}
	unit = l/4;
	Edge(unit,nivel-1,tortuga);
	izq(90,tortuga);
	Edge(unit,nivel-1,tortuga);
	der(90,tortuga);
	Edge(unit,nivel-1,tortuga);
	der(90,tortuga);
	Edge(unit,nivel-1,tortuga);
	Edge(unit,nivel-1,tortuga);
	izq(90,tortuga);
	Edge(unit,nivel-1,tortuga);
	izq(90,tortuga);
	Edge(unit,nivel-1,tortuga);
	der(90,tortuga);
	Edge(unit,nivel-1,tortuga);
	return 0;
}


