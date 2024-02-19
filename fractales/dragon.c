#include <stdio.h>
#include <stdlib.h>

#include "logo.h"
#include "dragon.h"

int nivelD;
double longitudD;
double miX0Dragon;
double miY0Dragon;
LOGO *tortugaAuxDragon;


int iniciaDragon(int nivel, double l, double x, double y, LOGO *tortuga);
int dibujaDragon(void);
int Dragon(double l, int nivel,LOGO *tortuga);
int LDragon(double l,int nivel, LOGO *tortuga);
int RDragon(double l, int nivel, LOGO *tortuga);

int iniciaDragon(int nivel, double l, double x, double y, LOGO *tortuga){
	nivelD = nivel;
	longitudD = l;
	miX0Dragon = x;
	miY0Dragon = y;
	tortugaAuxDragon = tortuga;
	return 0;
}
int dibujaDragon(void){
	inicia(miX0Dragon,miY0Dragon,0,ABAJO,tortugaAuxDragon);
	return Dragon(longitudD,nivelD,tortugaAuxDragon);
}

int Dragon(double l, int nivel,LOGO *tortuga){
	LDragon(l,nivel,tortuga);
	return 0;
}
int LDragon(double l,int nivel, LOGO *tortuga){
	if(nivel == 0){
		avanza(l,tortuga);
		return 0;
	}
	LDragon(l,nivel-1,tortuga);
	izq(90,tortuga);
	RDragon(l,nivel-1,tortuga);
	return 0;
}

int RDragon(double l, int nivel, LOGO *tortuga){
	if(nivel == 0){
		avanza(l,tortuga);
		return 0;
	}
	LDragon(l,nivel-1,tortuga);
	der(90,tortuga);
	RDragon(l,nivel-1,tortuga);
	return 0;
}

