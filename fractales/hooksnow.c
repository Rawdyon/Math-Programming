#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "logo.h"
#include "hooksnow.h"

int nivelHS;
double longitudHS;
double miX0HS;
double miY0HS;
LOGO *tortugaAuxHS;

int Hooksnow(double l, int nivel, LOGO *tortuga);
int RSnow(double l, int nivel, LOGO *tortuga);
int LSnow(double l, int nivel, LOGO *tortuga);

int iniciaHooksnow(int nivel, double l, double x,double y, LOGO *tortuga){
	longitudHS= l;
	nivelHS = nivel;
	miX0HS = x;
	miY0HS = y;
	tortugaAuxHS = tortuga;
	return 0;
}
int dibujaHooksnow(void){
	inicia(miX0HS,miY0HS,0,ABAJO,tortugaAuxHS);
	return Hooksnow(longitudHS,nivelHS,tortugaAuxHS);
}
int Hooksnow(double l, int nivel, LOGO *tortuga){
	RSnow(l,nivel,tortuga);
	return 0;
}
int RSnow(double l, int nivel, LOGO *tortuga){
	double unit,sunit;
	if(nivel == 0){
		avanza(l,tortuga);
		return 0;
	}
	unit = l/3;
	sunit = l*2*sqrt(3)/18;
	izq(60,tortuga);
	LSnow(unit,nivel-1,tortuga);
	RSnow(unit,nivel-1,tortuga);
	der(60,tortuga);
	RSnow(unit,nivel-1,tortuga);
	der(60,tortuga);
	RSnow(unit,nivel-1,tortuga);
	der(150,tortuga);
	RSnow(sunit,nivel-1,tortuga);
	LSnow(sunit,nivel-1,tortuga);
	izq(60,tortuga);
	RSnow(sunit,nivel-1,tortuga);
	izq(60,tortuga);
	LSnow(sunit,nivel-1,tortuga);
	RSnow(sunit,nivel-1,tortuga);
	izq(90,tortuga);
	LSnow(unit,nivel-1,tortuga);
	RSnow(unit,nivel-1,tortuga);
	return 0;
}
int LSnow(double l, int nivel, LOGO *tortuga){
	double unit,sunit;
	if(nivel==0){
		avanza(l,tortuga);
		return 0;
	}
	unit = l/3;
	sunit = l*2*sqrt(3)/18;
	LSnow(unit,nivel-1,tortuga);
	RSnow(unit,nivel-1,tortuga);
	der(90,tortuga);
	LSnow(sunit,nivel-1,tortuga);
	RSnow(sunit,nivel-1,tortuga);
	der(60,tortuga);
	LSnow(sunit,nivel-1,tortuga);
	der(60,tortuga);
	RSnow(sunit,nivel-1,tortuga);
	LSnow(sunit,nivel-1,tortuga);
	izq(150,tortuga);
	LSnow(unit,nivel-1,tortuga);
	izq(60,tortuga);
	LSnow(unit,nivel-1,tortuga);
	izq(60,tortuga);
	LSnow(unit,nivel-1,tortuga);
	RSnow(unit,nivel-1,tortuga);
	der(60,tortuga);
	return 0;
}

