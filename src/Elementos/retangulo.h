#ifndef RETANGULO__H
#define RETANGULO__H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//TAD RETANGULO
typedef void* Retangulo;

/* Funcao que cria um retangulo */
Retangulo criaRetangulo (char id[], double x, double y, double w,double h, char cor1[], char cor2[], char sw[]);

/* Funcoes que fazem o get dos elementos de um retangulo */
double getXRet (Retangulo retangulo);
double getYRet (Retangulo retangulo);
double getWRet (Retangulo retangulo);
double getHRet (Retangulo retangulo);
char* getCor1Ret (Retangulo retangulo);
char* getCor2Ret (Retangulo retangulo);
char* getSWRet (Retangulo retangulo);

/* Funcao que free em um retangulo */
void freeRetangulo (Retangulo retangulo);

#endif