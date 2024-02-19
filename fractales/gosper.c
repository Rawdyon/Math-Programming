
#include <stdio.h>
#include <stdlib.h>

#include "logo.h"
#include "gosper.h"

int nivelG;
double longitudG;
double miX0Gosper;
double miY0Gosper;
double gsegment;
LOGO *tortugaAuxGosper;


int iniciaGosper(int nivel, double l, double x, double y, LOGO *tortuga);
int RGosper( double l,int nivel, LOGO *tortuga);
int LGosper( double l,int nivel, LOGO *tortuga);
int Gosper(double l, int nivel,LOGO *tortuga);
int dibujaGosper(void);

int iniciaGosper(int nivel, double l, double x,double y, LOGO *tortuga){
	longitudG= l;
	nivelG = nivel;
	miX0Gosper = x;
	miY0Gosper = y;
	tortugaAuxGosper = tortuga;
	gsegment = 1/sqrt(7);
	return 0;
}
int dibujaGosper(void){
	inicia(miX0Gosper,miY0Gosper,0,ABAJO,tortugaAuxGosper);
	return Gosper(longitudG,nivelG,tortugaAuxGosper);
}

int Gosper(double l, int nivel,LOGO *tortuga){
	gsegment = 1/sqrt(7);
	RGosper(l, nivel, tortuga);
	return 0;
}



int RGosper( double l,int nivel, LOGO *tortuga){
	double unit;
	if(nivel == 0){
		avanza(l,tortuga);
		return 0;
	}
	unit = l*gsegment;
	//RGosper(l,nivel-1,tortuga);
	der(75,tortuga);
	LGosper(unit,nivel-1,tortuga);
	izq(60,tortuga);
	RGosper(unit,nivel-1,tortuga);
	RGosper(unit,nivel-1,tortuga);
	izq(120,tortuga);
	RGosper(unit,nivel-1,tortuga);
	izq(60,tortuga);
	LGosper(unit,nivel-1,tortuga);
	der(120,tortuga);
	LGosper(unit,nivel-1,tortuga);
	der(60,tortuga);
	RGosper(unit,nivel-1,tortuga);
	izq(15,tortuga);
	return 0;
}
int LGosper(double l, int nivel, LOGO *tortuga){
	double unit;
	if(nivel==0){
		avanza(l,tortuga);
		return 0;
	}
	unit = l*gsegment;
	der(15,tortuga);
	LGosper(unit,nivel-1,tortuga);
	izq(60,tortuga);
	RGosper(unit,nivel-1,tortuga);
	izq(120,tortuga);
	RGosper(unit,nivel-1,tortuga);
	der(60,tortuga);
	LGosper(unit,nivel-1,tortuga);
	der(120,tortuga);
	LGosper(unit,nivel-1,tortuga);
	LGosper(unit,nivel-1,tortuga);
	der(60,tortuga);
	RGosper(unit,nivel-1,tortuga);
	izq(75,tortuga);
	return 0;
}
