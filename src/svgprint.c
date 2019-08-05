#include"leitura.h"
#include"lista.h"
#include"arquivos.h"
#include"./Elementos/circulo.h"
#include"./Elementos/retangulo.h"
#include"./Elementos/quadra.h"
#include"./Elementos/hidrante.h"
#include"./Elementos/semaforo.h"
#include"./Elementos/radioBase.h"

void svgprintcircle (Circulo circulo, FILE * nomesvg)
{   
    fprintf (nomesvg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\" />\n", getXCirc(circulo), getYCirc(circulo), getRaioCirc(circulo), getCor2Circ(circulo), getCor1Circ(circulo), getSWCirc (circulo)); 
}

void svgprintrect (Retangulo retangulo, FILE * nomesvg)
{
    fprintf (nomesvg, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\" />\n", getXRet (retangulo), getYRet (retangulo), getWRet (retangulo), getHRet (retangulo), getCor2Ret (retangulo), getCor1Ret (retangulo), getSWRet (retangulo));
}

void svgprinttext (char * text, double x, double y, FILE * nomesvg)
{
    fprintf (nomesvg, "<text x=\"%lf\" y=\"%lf\"> %s </text>\n", x, y, text);
}

void svgprintrectBB (double xr, double yr, double wr, double hr, char * cor, FILE * nomesvg)
{
    fprintf (nomesvg, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"none\" stroke=\"%s\"/>\n", xr, yr, wr, hr, cor);
}

void svgprintellipseBB (double cx, double cy, double rx, double ry, char * cor, FILE * nomesvg)
{
    fprintf (nomesvg, "<ellipse cx=\"%lf\" cy=\"%lf\" rx=\"%lf\" ry=\"%lf\" fill=\"none\" stroke=\"%s\"/>\n", cx, cy, rx, ry, cor);
}

void svgprintQuadra (Quadra quadra, FILE * nomesvg)
{
    fprintf (nomesvg, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\" />\n", getXQuadra (quadra), getYQuadra (quadra), getWQuadra (quadra), getHQuadra (quadra), getCor1Quadra (quadra), getCor2Quadra (quadra), getSWQuadra (quadra));
    fprintf (nomesvg, "<text x=\"%lf\" y=\"%lf\" font-size=\"12\" fill=\"%s\"> %s </text>\n", getXQuadra (quadra) + 3, getYQuadra (quadra) + 12, getCor2Quadra (quadra), getCEPQuadra (quadra));
}
void svgprintHidrante (Hidrante hidrante, FILE * nomesvg)
{
    fprintf (nomesvg, "<rect x=\"%lf\" y=\"%lf\" width=\"10\" height=\"10\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\" />\n", getXHid (hidrante), getYHid (hidrante), getCor1Hid (hidrante), getCor2Hid (hidrante), getSWHid (hidrante));
    fprintf (nomesvg, "<text x=\"%lf\" y=\"%lf\" font-size=\"12\" fill=\"%s\"> H </text>\n", getXHid (hidrante)+0.5, getYHid (hidrante) + 9, getCor2Hid (hidrante));
}

void svgprintSemaforo (Semaforo semaforo, FILE * nomesvg)
{
    fprintf (nomesvg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"6\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\" /> \n", getXSema(semaforo), getYSema(semaforo),getCor1Sema (semaforo), getCor2Sema (semaforo), getSWSema (semaforo)); 
    fprintf (nomesvg, "<text x=\"%lf\" y=\"%lf\" font-size=\"13\" fill=\"%s\"> S </text>\n", getXSema (semaforo)-4, getYSema (semaforo)+4, getCor2Sema (semaforo));
}

void svgprintRadioBase (RadioBase radioBase, FILE * nomesvg)
{
    fprintf (nomesvg, "<rect x=\"%lf\" y=\"%lf\" width=\"5\" height=\"13\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\" />\n", getXRB (radioBase), getYRB (radioBase), getCor1RB (radioBase), getCor2RB (radioBase), getSWRB (radioBase));
    fprintf (nomesvg, "<text x=\"%lf\" y=\"%lf\" font-size=\"5\" fill=\"%s\"> RB </text>\n", getXHid (radioBase)+3, getYHid (radioBase) + 4, getCor2RB (radioBase));
}

void svgprintDoubleCircle (Circulo elemento, FILE* nomesvg){
    if (getTipo (elemento) == 's'){
        fprintf (nomesvg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"10\" fill=\"none\" stroke=\"blue\" stroke-width=\"6\" />\n", getXHid (elemento), getYHid (elemento));
        fprintf (nomesvg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"16\" fill=\"none\" stroke=\"green\" stroke-width=\"6\" />\n", getXHid (elemento), getYHid (elemento));
    }
    else if (getTipo (elemento) == 'h'){
        fprintf (nomesvg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"10\" fill=\"none\" stroke=\"blue\" stroke-width=\"6\" />\n", getXHid (elemento) + 5, getYHid (elemento) + 5);
        fprintf (nomesvg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"16\" fill=\"none\" stroke=\"green\" stroke-width=\"6\" />\n", getXHid (elemento) + 5, getYHid (elemento) + 5);
    }
    else if (getTipo (elemento) == 'b'){
        fprintf (nomesvg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"10\" fill=\"none\" stroke=\"blue\" stroke-width=\"6\" />\n", getXHid (elemento) + 3, getYHid (elemento) + 4);
        fprintf (nomesvg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"16\" fill=\"none\" stroke=\"green\" stroke-width=\"6\" />\n", getXHid (elemento) + 3, getYHid (elemento) + 4);
    }
}
