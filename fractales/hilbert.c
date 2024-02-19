
#include <stdio.h>
#include <stdlib.h>

#include "logo.h"
#include "hilbert.h"

int nivelH;
double longitudH;
double miX0Hilbert;
double miY0Hilbert;
LOGO *tortugaAuxHilbert;


int iniciaHilbert(int nivel, double l, double x, double y, LOGO *tortuga);
int Hill(int nivel, double l, LOGO *tortuga);
int Hilbert(double l, int nivel, int parity,LOGO *tortuga);
int dibujaHilbert(void);

int iniciaHilbert(int nivel, double l, double x,double y, LOGO *tortuga){
	longitudH= l;
	nivelH = nivel;
	miX0Hilbert = x;
	miY0Hilbert = y;
	tortugaAuxHilbert = tortuga;
	return 0;
}
int dibujaHilbert(void){
	inicia(miX0Hilbert,miY0Hilbert,0,ABAJO,tortugaAuxHilbert);
	return Hill(nivelH,longitudH,tortugaAuxHilbert);
}

int Hill(int nivel, double l, LOGO *tortuga){
	Hilbert(l,nivel,1,tortuga);
	return 0;
}
int Hilbert(double l, int nivel, int parity, LOGO *tortuga){
	if(nivel == 0)
		return 0;
	
	izq(parity*90, tortuga);
	
	Hilbert(l,nivel -1, -parity,tortuga);
	
	avanza(l,  tortuga);
	
	der(parity*90, tortuga);
	
	Hilbert(l,nivel -1, parity,tortuga);
	
	avanza(l, tortuga);
	
	Hilbert(l,nivel -1, parity,tortuga);
	
	der(parity*90, tortuga);
	
	avanza(l, tortuga);
	
	Hilbert(l,nivel -1, -parity,tortuga);
	izq(parity*90, tortuga);
	return 0;
}


