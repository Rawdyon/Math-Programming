#include <stdio.h>
#include <stdlib.h>

#include "logo.h"
#include "weave.h"

int nivelW;
double longitudW;
double miX0Weave;
double miY0Weave;
double parityW;
LOGO *tortugaAuxWeave;


int iniciaWeave(int nivel, double l, double x, double y, LOGO *tortuga);
int dibujaWeave(void);

int interior(double l,LOGO *tortuga);
int Maze(double l, int nivel , LOGO *tortuga);
int Weave(double l, int nivel, LOGO *tortuga);


int iniciaWeave(int n, double l, double x, double y, LOGO *tortuga){
	nivelW = n;
	longitudW = l;
	miY0Weave = x;
	miX0Weave = y;
	tortugaAuxWeave = tortuga;
	return 0;
}
int dibujaWeave(void){
	inicia(miX0Weave,miY0Weave,0,ABAJO,tortugaAuxWeave);
	return Weave(longitudW,nivelW,tortugaAuxWeave);
}

int Weave(double l, int nivel, LOGO *tortuga){
	parityW = -1;
	Maze(l,nivel,tortuga);
	return 0;
}

int Maze(double l, int nivel , LOGO *tortuga){
	int i;
	double unit;
	if(nivel == 0){
		interior(l,tortuga);
		return 0;
	}
	unit = l/3;
	Maze(unit,nivel-1,tortuga);
	izq(90,tortuga);
	Maze(unit,nivel-1,tortuga);
	for(i=0;i<3;i++){
		der(90,tortuga);
		Maze(unit,nivel-1,tortuga);
	}
	for(i=0;i<3;i++){
		izq(90,tortuga);
		Maze(unit,nivel-1,tortuga);
	}
	der(90,tortuga);
	Maze(unit,nivel-1,tortuga);
	return 0;
}
int interior(double l,LOGO *tortuga){
	parityW = -parityW;
	double unit = l/5;
	if(miY0Weave){
		parityW = 1;
		izq(45,tortuga);
	}
	avanza(4*unit,tortuga);
	der(90*parityW,tortuga);
	avanza(3*unit,tortuga);
	der(90*parityW,tortuga);
	avanza(2*unit,tortuga);
	der(90*parityW,tortuga);
	avanza(unit,tortuga);
	der(90*parityW,tortuga);
	avanza(unit,tortuga);
	izq(90*parityW,tortuga);
	avanza(unit,tortuga);
	izq(90*parityW,tortuga);
	avanza(2*unit,tortuga);
	izq(90*parityW,tortuga);
	avanza(3*unit,tortuga);
	izq(90*parityW,tortuga);
	avanza(4*unit,tortuga);
	izq(90*parityW,tortuga);
	avanza(4*unit,tortuga);
	der(90*parityW,tortuga);
	if(miY0Weave){
		der(90,tortuga);
		avanza(4*unit,tortuga);
		izq(45,tortuga);
	}
	return 0;
}










