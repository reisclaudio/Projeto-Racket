#include"circulo.h"

struct StCirculo {
    char id[50], tipo;
    double x, y, r;
    char cor1[24],cor2[24], sw[20];
};

typedef struct StCirculo *CirculoImp;

Circulo criaCirculo (char id[], double x, double y, double r, char cor1[], char cor2[], char sw[])
{
    CirculoImp novo;
    novo = (CirculoImp) malloc (sizeof (struct StCirculo));

    strcpy (novo->id, id);
    novo->x = x;
    novo->y = y;
    novo->r = r;
    novo->tipo = 'c';
    strcpy (novo->cor1, cor1);
    strcpy (novo->cor2, cor2);
    strcpy (novo->sw, sw);

    return novo;
}

double getXCirc (Circulo circulo)
{
    CirculoImp c;
    c = (CirculoImp) circulo;
    return c->x; 
}

double getYCirc (Circulo circulo)
{
    CirculoImp c;
    c = (CirculoImp) circulo;
    return c->y;
}

double getRaioCirc (Circulo circulo)
{
    CirculoImp c;
    c = (CirculoImp) circulo;
    return c->r;
}

char* getCor1Circ (Circulo circulo)
{
    CirculoImp c;
    c = (CirculoImp) circulo;
    return c->cor1;
}

char* getCor2Circ (Circulo circulo)
{
    CirculoImp c;
    c = (CirculoImp) circulo;
    return c->cor2;    
}

char* getSWCirc (Circulo circulo)
{
    CirculoImp c;
    c = (CirculoImp) circulo;
    return c->sw;
}

char getTipo (Circulo circulo)
{
    CirculoImp c;
    c = (CirculoImp) circulo;
    return c->tipo;
}

void freeCirculo (Circulo circulo)
{
    CirculoImp c;
    c = (CirculoImp) circulo;
    free (c);
}



