#ifndef CIRCULO__H
#define CIRCULO__H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//TAD CIRCULO
typedef void* Circulo;

/* Funcao que cria um circulo */
Circulo criaCirculo (char id[], double x, double y, double r, char cor1[], char cor2[], char sw[]);
/* Funcoes que fazem o get dos elementos de um circulo: */
double getXCirc (Circulo circulo);
double getYCirc (Circulo circulo);
double getRaioCirc (Circulo circulo);
char* getCor1Circ (Circulo circulo);
char* getCor2Circ (Circulo circulo);
char* getSWCirc (Circulo circulo);

/*Funcao generica que retorna o tipo de qualquer elemento*/
char getTipo (Circulo circulo);

/* Funcao que da free em um circulo */
void freeCirculo (Circulo circulo);

#endif