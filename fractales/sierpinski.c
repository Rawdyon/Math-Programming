
#include <stdio.h>
#include <stdlib.h>

#include "logo.h"
#include "sierpinski.h"
#include "math.h"

int nivelS;
double longitudS;
double miX0Sierp;
double miY0Sierp;
double diag;
LOGO *tortugaAuxSierp;

	

int iniciaSierpinski(int nivel, double l, double x, double y, LOGO *tortuga);
int dibujaHilbert(void);
int Sierpinski(int nivel, double l, LOGO *tortuga);
int oneside(int nivel, LOGO *tortuga);


int iniciaSierpinski(int nivel, double l, double x,double y, LOGO *tortuga){
	longitudS = l;
	nivelS = nivel;
	miX0Sierp = x;
	miY0Sierp = y;
	tortugaAuxSierp = tortuga;
	diag = l/sqrt(2);
	return 0;
}
int dibujaSierpinski(void){
	inicia(miX0Sierp,miY0Sierp,0,ABAJO,tortugaAuxSierp);
	return Sierpinski(nivelS,longitudS,tortugaAuxSierp);
}

int Sierpinski(int nivel, double l, LOGO *tortuga){
	int i;
	double diagS = l/sqrt(2);
	for(i=0;i<4;i++){
		oneside(nivel,tortuga);
		der(45,tortuga);
		avanza(diagS,tortuga);
		der(45,tortuga);
	}
	return 0;
}
int oneside(int nivel, LOGO *tortuga){
	if(nivel == 0)
		return 0;
	oneside(nivel-1,tortuga);
	der(45,tortuga);
	avanza(diag,tortuga);
	der(45,tortuga);
	oneside(nivel-1,tortuga);
	izq(90,tortuga);
	avanza(longitudS,tortuga);
	izq(90,tortuga);
	oneside(nivel-1,tortuga);
	der(45,tortuga);
	avanza(diag,tortuga);
	der(45,tortuga);
	oneside(nivel-1,tortuga);	
	return 0;
}


