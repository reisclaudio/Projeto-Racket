#include"retangulo.h"

struct StRetangulo {
    char id[50], tipo;
    double x, y, w, h;
    char cor1[24],cor2[24], sw[20];
};

typedef struct StRetangulo *RetanguloImp;

Retangulo criaRetangulo (char id[], double x, double y, double w,double h, char cor1[], char cor2[], char sw[])
{
    RetanguloImp novo;
    novo = (RetanguloImp) malloc (sizeof (struct StRetangulo));

    strcpy (novo->id, id);
    novo->x = x;
    novo->y = y;
    novo->w = w;
    novo->h = h;
    novo->tipo = 'r';
    strcpy (novo->cor1, cor1);
    strcpy (novo->cor2, cor2);
    strcpy (novo->sw, sw);

    return novo;
}

double getXRet (Retangulo retangulo)
{
    RetanguloImp r;
    r = (RetanguloImp) retangulo;
    return r->x; 
}

double getYRet (Retangulo retangulo)
{
    RetanguloImp r;
    r = (RetanguloImp) retangulo;
    return r->y; 
}

double getWRet (Retangulo retangulo)
{
    RetanguloImp r;
    r = (RetanguloImp) retangulo;
    return r->w; 
}


double getHRet (Retangulo retangulo)
{
    RetanguloImp r;
    r = (RetanguloImp) retangulo;
    return r->h; 
}

char* getCor1Ret (Retangulo retangulo)
{
    RetanguloImp r;
    r = (RetanguloImp) retangulo;
    return r->cor1; 
}

char* getCor2Ret (Retangulo retangulo)
{
    RetanguloImp r;
    r = (RetanguloImp) retangulo;
    return r->cor2; 
}

char* getSWRet (Retangulo retangulo)
{
    RetanguloImp r;
    r = (RetanguloImp) retangulo;
    return r->sw;
}

void freeRetangulo (Retangulo retangulo)
{
    RetanguloImp r;
    r = (RetanguloImp) retangulo;
    free (r);
}

