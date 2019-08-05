#include"leitura.h"
#include"arquivos.h"
#include"geometria.h"
#include"lista.h"

typedef struct {
    int id;
    double x, y;
    double largura, altura;
    double raio;
} valores;

double distanciaEuclidiana (double x1, double y1, double x2, double y2)
{
    return sqrt((pow((x1-x2),2) + pow((y1-y2),2)));
}

double manhattanDistance (double x1, double y1, double x2, double y2)
{
    return fabs (x1-x2) + fabs (y1-y2);
}

double clamp (double pc, double pmi, double pma)
{
    if (pc > pma) return pma;
    else if (pc < pmi) return pmi;
    else return pc;
}

void consultaD (char* j, char* k,Lista lformas, FILE * nometxt, FILE * nomesvg)
{
    char strtexto[50];
    double dist, xline, yline;
    valores d[2];

    Elemento elemento1 = encontrarElemento (lformas, j);
    Elemento elemento2 = encontrarElemento (lformas, k);

    //Verifica se as figuras sao circulos ou retangulos, coleta os dados
    //E realiza os calculos da distancia
    if (getTipo(elemento1) == 'c'){ 
        d[0].x = getXCirc (elemento1);
        d[0].y = getYCirc (elemento1);
    }
    else{
        d[0].x = getXRet (elemento1) + (getWRet (elemento1)/2.0);
        d[0].y = getYRet (elemento1) + (getHRet (elemento1)/2.0);
    }

    if (getTipo (elemento2) == 'c'){
        d[1].x = getXCirc (elemento2);
        d[1].y = getYCirc (elemento2);
    }
    else {
        d[1].x = getXRet (elemento2) + (getWRet (elemento2)/2.0);
        d[1].y = getYRet (elemento2) + (getHRet (elemento2)/2.0);
    }
        
    dist = distanciaEuclidiana (d[0].x, d[0].y, d[1].x, d[1].y);
    sprintf(strtexto, "%lf", dist);
    fprintf(nometxt, "%lf\n\n", dist);

    xline = (d[0].x + d[1].x)/2;
    yline = (d[0].y + d[1].y)/2;
      
    fprintf(nomesvg, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"black\" />\n", d[0].x, d[0].y, d[1].x, d[1].y);
    svgprinttext (strtexto, xline, yline, nomesvg);
}


void consultaO (char* j, char* k,Lista lformas, FILE * nometxt, FILE * nomesvg)
{
    double dist, h, w, x, y, xmin, xmax, ymin, ymax;
    double mx, mex, my, mey,mxr, mexr,myr, meyr, wm, hm;
    valores d[2];
    
    Elemento elemento1 = encontrarElemento (lformas, j);
    Elemento elemento2 = encontrarElemento (lformas, k);
    
    //Verifica se as duas figuras sao circulos, coleta os dados
    //E realiza os calculos da sobreposiçao
    if (getTipo (elemento1) == 'c' && getTipo (elemento2) == 'c'){
        d[0].x = getXCirc (elemento1);
        d[0].y = getYCirc (elemento1);
        d[1].x = getXCirc (elemento2);
        d[1].y = getYCirc (elemento2);

        //Define o menor e o maior x e y
    
        if (getXCirc (elemento1) > getXCirc (elemento2)){
            mx = getXCirc (elemento1);
            mxr = getRaioCirc (elemento1);
            mex = getXCirc (elemento2);
            mexr = getRaioCirc (elemento2);
        }
        else {
            mx = getXCirc (elemento2);
            mxr = getRaioCirc (elemento2);
            mex = getXCirc (elemento1);
            mexr = getRaioCirc (elemento1);
        }

        if (getYCirc (elemento1) > getYCirc (elemento2)){
            my = getYCirc (elemento1);
            myr = getRaioCirc (elemento1);
            mey = getYCirc (elemento2);
            meyr = getRaioCirc (elemento2);
        }
        else{
            my = getYCirc (elemento2);
            myr = getRaioCirc (elemento2);
            mey = getYCirc (elemento1);
            meyr = getRaioCirc (elemento1);
        }

        //Define a largura, altura, x e y do retangulo delimitador
        w = (mx + mxr) - (mex - mexr);
        h = (my + myr) - (mey - meyr);
        x = mex - mexr;
        y = mey - meyr;

        dist = distanciaEuclidiana (d[0].x, d[0].y, d[1].x, d[1].y);
        if (dist <=  getRaioCirc (elemento1) + getRaioCirc (elemento2)){ 
            fprintf (nometxt, "SIM\n\n");
            fprintf (nomesvg, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"none\" stroke=\"black\"/>\n",x, y, w, h);
        }
        else{
            fprintf (nometxt,"NAO\n\n");
            fprintf (nomesvg, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"none\" stroke=\"black\" stroke-dasharray=\"5\"/>\n",x, y, w, h);
        }
    }

    //Verifica se as duas figuras sao retangulos, coleta os dados
    //E realiza os calculos da sobreposiçao
    if (getTipo (elemento1) == 'r' && getTipo (elemento2) == 'r'){
        d[0].x = getXRet (elemento1);
        d[0].y = getYRet (elemento1);
        d[1].x = getXRet (elemento2);
        d[1].y = getYRet (elemento2);
        
        //Define o menor e o maior x e y
        if (getXRet (elemento1) > getXRet (elemento2)){
            mx = getXRet (elemento1);
            mex = getXRet (elemento2);
        }
        else {
            mx = getXRet (elemento2);
            mex = getXRet (elemento1);
        }
        
        if (getYRet (elemento1) > getYRet (elemento2)){
            my = getYRet (elemento1);
            mey = getYRet (elemento2);
        }
        else {
            my = getYRet (elemento2);
            mey = getYRet (elemento1);
        }

        if (getWRet (elemento1) > getWRet (elemento2))
            wm = getWRet (elemento1);
        else
            wm = getWRet (elemento2);

        if (getHRet (elemento1) > getHRet (elemento2))
            hm = getHRet (elemento1);
        else
            hm = getHRet (elemento2);

        //Define a largura, altura, x e y do retangulo delimitador
        w = mx + wm - mex;
        h = my + hm - mey;
        x = mex;
        y = mey;

        if (getXRet (elemento1) <= getXRet (elemento2) + getWRet (elemento1) && getYRet (elemento1) <= getYRet (elemento2) + getHRet (elemento2) && 
        getXRet (elemento1) + getWRet (elemento1) >= getXRet (elemento2) && getYRet (elemento1) + getHRet (elemento1) >= getYRet (elemento2)){
            fprintf (nometxt, "SIM\n\n");
            fprintf (nomesvg, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"none\" stroke=\"black\"/>\n",x,y, w, h);
        }
        else{
            fprintf (nometxt, "NAO\n\n");
            fprintf (nomesvg, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"none\" stroke=\"black\" stroke-dasharray=\"5\"/>\n",x,y, w, h);
        }
    }

    //Verifica se uma delas é circulo e a outa é retangulo, coleta os dados
    //E realiza os calculos da sobreposicao
    if ((getTipo (elemento1) =='c' && getTipo (elemento2) == 'r') || (getTipo (elemento1) == 'r' && getTipo (elemento2) == 'c')){
        if (getTipo (elemento1) == 'c'){
            d[0].raio = getRaioCirc (elemento1);
            d[0].x = getXCirc (elemento1);
            d[0].y = getYCirc (elemento1);
        }
        if (getTipo (elemento1) == 'r'){
            d[1].largura = getWRet (elemento1);
            d[1].altura = getHRet (elemento1);
            d[1].x = getXRet (elemento1);
            d[1].y = getYRet (elemento1);
        }
        if (getTipo (elemento2) == 'c'){
            d[0].raio = getRaioCirc (elemento2);
            d[0].x = getXCirc (elemento2);
            d[0].y = getYCirc (elemento2);
        }
        if (getTipo (elemento2) == 'r'){
            d[1].largura = getWRet (elemento2);
            d[1].altura = getHRet (elemento2);
            d[1].x = getXRet (elemento2);
            d[1].y = getYRet (elemento2);
        }

        //Define x e y maximo e x e y minimo
        if ((d[0].x - d[0].raio) < d[1].x) xmin = d[0].x - d[0].raio;
        else xmin = d[1].x;

        if ((d[0].x + d[0].raio) > (d[1].x + d[1].largura)) xmax = d[0].x + d[0].raio;
        else xmax = d[1].x + d[1].largura;

        if ((d[0].y - d[0].raio) < d[1].y) ymin = d[0].y - d[0].raio;
        else ymin = d[1].y;

        if ((d[0].y + d[0].raio) > (d[1].y + d[1].altura)) ymax = d[0].y + d[0].raio;
        else ymax = d[1].y + d[1].altura;

        //Define a largura e altura do retangulo delimitador                
        w = xmax - xmin;
        h = ymax - ymin;

        //Define o x mais proximo e y mais proximo
        double xmp = clamp (d[0].x, d[1].x, d[1].x + d[1].largura);
        double ymp = clamp (d[0].y, d[1].y, d[1].y + d[1].altura);

        if ((distanciaEuclidiana (d[0].x, d[0].y, xmp, ymp)) <= d[0].raio){
            fprintf (nometxt, "SIM\n\n");
            fprintf (nomesvg, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"none\" stroke=\"black\"/>\n",xmin,ymin, w, h);
        }
        else {
            fprintf (nometxt, "NAO\n\n");
            fprintf (nomesvg, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"none\" stroke=\"black\" stroke-dasharray=\"5\"/>\n",xmin,ymin, w, h);
        }
    }
}

void consultaI (char* j, double x, double y, Lista lformas, FILE * nometxt, FILE * nomesvg)
{
    double dist;
    valores d;
    
    Elemento elemento = encontrarElemento (lformas, j);

    d.x = getXRet(elemento) + (getWRet (elemento)/2.0);
    d.y = getYRet (elemento) + (getHRet (elemento)/2.0);

    //Verifica se a figura é um circulo, coleta os dados
    //E realiza os calculos do inside/not inside
    if (getTipo (elemento) == 'c'){
        dist = distanciaEuclidiana(x, y, getXCirc (elemento), getYCirc (elemento));
        if (dist <= getRaioCirc (elemento)){
            fprintf (nometxt, "INTERNO\n\n");
            fprintf (nomesvg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"2\" fill=\"green\" stroke=\"green\" />\n", x, y);
            fprintf(nomesvg, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"green\" />\n", x, y, getXCirc (elemento), getYCirc (elemento));
        }
        else{
            fprintf (nometxt, "NAO INTERNO\n\n");
            fprintf (nomesvg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"2\" fill=\"red\" stroke=\"red\" />\n", x, y);
            fprintf(nomesvg, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"red\" />\n", x, y, getXCirc (elemento), getYCirc (elemento));
        }
    }
    
    //Verifica se a figura é um retangulo, coleta os dados
    //E realiza os calculos do inside/not inside
    if (getTipo (elemento) == 'r'){
        if (x > getXRet (elemento) && x < getXRet (elemento) + getWRet (elemento) && y > getYRet (elemento) && y < getYRet (elemento) + getHRet (elemento)){
            fprintf (nometxt, "INTERNO\n\n");
            fprintf (nomesvg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"2\" fill=\"green\" stroke=\"green\" />\n", x, y);
            fprintf(nomesvg, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"green\" />\n", x, y, d.x, d.y);
        }
        else {
            fprintf (nometxt, "NAO INTERNO\n\n"); 
            fprintf (nomesvg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"2\" fill=\"red\" stroke=\"red\" />\n", x, y);
            fprintf(nomesvg, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"red\" />\n", x, y, d.x, d.y);   
        }
    }
}

void consultaBB (char * sufixo, char * cor, char * nomesvg, Lista lformas, FILE * nomegeo)
{   
    char * arqsvg3;
    FILE * arqBB;
    arqsvg3 = criaSVG3 (nomesvg, sufixo);
    arqBB = fopen (arqsvg3, "w+");
    VerificaArquivo (arqBB, arqsvg3);

    geoBB (nomegeo, arqBB, lformas, cor);
}

bool consultaCRD (char *j, Lista lquadras, Lista lhidrantes, Lista lsemaforos, Lista lRB, FILE *nometxt)
{
    char tipo;
    Elemento elemento = encontrarElementoListas (j, lquadras, lhidrantes, lsemaforos, lRB);

    if (elemento != NULL){
        tipo = getTipo (elemento);

        if (tipo == 'q')
            fprintf (nometxt, "Quadra x = %lf y = %lf w = %lf h = %lf\n\n", getXQuadra (elemento), getYQuadra (elemento), getWQuadra (elemento), getHQuadra (elemento));
        else if (tipo == 'h')
            fprintf (nometxt, "Hidrante x = %lf y = %lf\n\n", getXHid (elemento), getYHid (elemento));
        else if (tipo == 's')
            fprintf (nometxt, "Semaforo x = %lf y = %lf\n\n", getXSema (elemento), getYSema(elemento));
        else if (tipo == 'b')
            fprintf (nometxt, "Radio base x = %lf y = %lf\n\n", getXRB (elemento), getYRB(elemento));
    }
    else {
        fprintf (nometxt, "Elemento nao encontrado!\n\n");
    }
}

bool consultaDEL (char *j, Lista lquadras, Lista lhidrantes, Lista lsemaforos, Lista lRB, FILE *nometxt)
{
    Elemento elemento = encontrarElementoListas (j, lquadras, lhidrantes, lsemaforos, lRB);

    char tipo = getTipo (elemento);

    if (tipo == 'q'){
        fprintf (nometxt, "Quadra x = %lf y = %lf w = %lf h = %lf\n\n", getXQuadra (elemento), getYQuadra (elemento), getWQuadra (elemento), getHQuadra (elemento));
        excluirElemento (lquadras, j);
    }
    else if (tipo == 'h'){
        fprintf (nometxt, "Hidrante x = %lf y = %lf\n\n", getXHid (elemento), getYHid (elemento));
        excluirElemento (lhidrantes, j);
    }
    else if (tipo == 's') {
        fprintf (nometxt, "Semaforo x = %lf y = %lf\n\n", getXSema (elemento), getYSema(elemento));
        excluirElemento (lsemaforos, j);
    }
    else if (tipo == 'b'){
        fprintf (nometxt, "Radio base x = %lf y = %lf\n\n", getXRB (elemento), getYRB(elemento));
        excluirElemento (lRB, j);
    }
}

void consultaCBQ (double x, double y, double r, char* cstrk, Lista lquadras, FILE *nometxt)
{
    Elemento quadra;
    Elemento newQuadra;
    char cep[20];

    int contador = 0, i;
    fprintf (nometxt, "Quadras com bordas alteradas: ");

    for (i = 0; i < getTamAtual (lquadras);i++){
        quadra = getElemento (lquadras, i);

        if (distanciaEuclidiana (x, y, getXQuadra (quadra), getYQuadra (quadra)) <= r) 
            contador++;        
        if (distanciaEuclidiana (x, y, getXQuadra (quadra) + getWQuadra (quadra), getYQuadra (quadra)) <= r) 
            contador++;        
        if (distanciaEuclidiana (x, y, getXQuadra (quadra), getYQuadra (quadra) + getHQuadra (quadra)) <= r) 
            contador++;        
        if (distanciaEuclidiana (x, y, getXQuadra (quadra) + getWQuadra (quadra), getYQuadra (quadra) + getHQuadra (quadra)) <= r) 
            contador++;

        if (contador == 4){
            fprintf (nometxt, "%s ", getCEPQuadra (quadra));
            setCor2Quadra (quadra, cstrk);
        }
        contador = 0;     
    }
    fprintf (nometxt, "\n\n");
}

void consultaTRNS (double x, double y, double w, double h, double dx, double dy, Lista lquadras,Lista lhidrantes, Lista lsemaforos, Lista lrb, FILE*nometxt)
{
    Elemento elemento;
    Elemento newElemento;
    char cep[20], id[20];
    int contador = 0, i=0;

    for (i = 0; i < getTamAtual (lquadras); i++){
        elemento = getElemento (lquadras, i);

        if (getXQuadra (elemento) > x && getXQuadra (elemento) < x + w && getYQuadra (elemento) > y && getYQuadra (elemento) < y + h) 
            contador++;
        if (getXQuadra (elemento) + getWQuadra (elemento) > x && getXQuadra (elemento) + getWQuadra (elemento) < x + w && getYQuadra (elemento) > y && getYQuadra (elemento) < y + h) 
            contador++;
        if (getXQuadra (elemento) > x && getXQuadra (elemento) < x + w && getYQuadra (elemento) + getHQuadra (elemento) > y && getYQuadra (elemento) + getHQuadra (elemento) < y + h) 
            contador++;
        if (getXQuadra (elemento) + getWQuadra (elemento) > x && getXQuadra (elemento) + getWQuadra (elemento) < x + w && getYQuadra (elemento) + getHQuadra (elemento) > y && getYQuadra (elemento) + getHQuadra (elemento) < y + h) 
            contador++;

        if (contador == 4){
            fprintf (nometxt, "%s: \n Posicao anterior: (%lf, %lf) \n Posicao atualizada: (%lf, %lf)\n", getCEPQuadra (elemento), getXQuadra (elemento), getYQuadra (elemento), getXQuadra (elemento) + dx, getYQuadra (elemento) + dy);

            setXQuadra (elemento, getXQuadra (elemento) + dx);
            setYQuadra (elemento, getYQuadra (elemento) + dy);
        }
        contador = 0;
    }

    for (i = 0; i<getTamAtual (lhidrantes); i++){
        elemento = getElemento (lhidrantes, i);

        if (getXHid (elemento) > x && getXHid (elemento) < x + w && getYHid (elemento) > y && getYHid (elemento) < y + h){
            fprintf (nometxt, "%s: \n Posicao anterior: (%lf, %lf) \n Posicao atualizada: (%lf, %lf)\n", getIDHid (elemento), getXHid (elemento), getYHid (elemento), getXHid (elemento) + dx, getYHid (elemento) + dy);

            setXHid (elemento, getXHid (elemento) + dx);
            setYHid (elemento, getYHid (elemento) + dy);
        }
    }

    for (i = 0; i<getTamAtual (lsemaforos); i++){
        elemento = getElemento (lsemaforos, i);

        if (getXSema (elemento) > x && getXSema (elemento) < x + w && getYSema (elemento) > y && getYSema (elemento) < y + h){
            fprintf (nometxt, "%s: \n Posicao anterior: (%lf, %lf) \n Posicao atualizada: (%lf, %lf)\n", getIDSema (elemento), getXSema (elemento), getYSema (elemento), getXSema (elemento) + dx, getYSema (elemento) + dy);

            setXSema (elemento, getXSema (elemento) + dx);
            setYSema (elemento, getYSema (elemento) + dy);
        }
    }

    for (i = 0; i<getTamAtual (lrb); i++){
        elemento = getElemento (lrb, i);

        if (getXRB (elemento) > x && getXRB (elemento) < x + w && getYRB (elemento) > y && getYRB (elemento) < y + h){
            fprintf (nometxt, "%s: \n Posicao anterior: (%lf, %lf) \n Posicao atualizada: (%lf, %lf)\n", getIDRB (elemento), getXRB (elemento), getYRB (elemento), getXRB (elemento) + dx, getYRB (elemento) + dy);

            setXRB (elemento, getXRB (elemento) + dx);
            setYRB (elemento, getYRB (elemento) + dy);
        }
    }
    fprintf (nometxt, "\n\n");
}

void consultaDQ (char* id, char* metrica, double dist, Lista lquadras, Lista lhidrantes, Lista lsemaforos, Lista lRB, FILE* nometxt, FILE* nomesvg)
{
    char cep [20];
    Elemento elemento = encontrarElementoListas (id, lquadras, lhidrantes, lsemaforos, lRB);
    Elemento quadra;

    svgprintDoubleCircle (elemento, nomesvg);
    int tamanhoLista = getTamAtual (lquadras);
    fprintf (nometxt, "Equipamento Urbano: %s x = %lf y = %lf\nQuadras removidas: ", getIDHid (elemento), getXHid (elemento), getYHid (elemento));

    //L1: Manhattan Distance
    if (strcmp (metrica, "L1") == 0){
        int contador = 0;
        for (int i = 0; i < tamanhoLista; i++){
            quadra = getElemento (lquadras, i);

            if (manhattanDistance (getXHid (elemento), getYHid (elemento), getXQuadra (quadra), getYQuadra (quadra)) <= dist)
                contador++;
            if (manhattanDistance (getXHid (elemento), getYHid (elemento), getXQuadra (quadra) + getWQuadra (quadra), getYQuadra (quadra)) <= dist)
                contador++;
            if (manhattanDistance (getXHid (elemento), getYHid (elemento), getXQuadra (quadra), getYQuadra (quadra) + getHQuadra (quadra)) <= dist)
                contador++;
            if (manhattanDistance (getXHid (elemento), getYHid (elemento), getXQuadra (quadra) + getWQuadra (quadra), getYQuadra (quadra) + getHQuadra (quadra)) <= dist)
                contador++;

            if (contador == 4){
                fprintf (nometxt, "%s ", getCEPQuadra (quadra));
                excluirElemento (lquadras, getCEPQuadra (quadra));
            }
            contador = 0;
        }
    }

    //L2: Euclidian Distance
    else if (strcmp (metrica, "L2") == 0){
        int contador = 0;
        for (int i = 0; i < tamanhoLista; i++){
            quadra = getElemento (lquadras, i);

            if (distanciaEuclidiana (getXHid (elemento), getYHid (elemento), getXQuadra (quadra), getYQuadra (quadra)) <= dist) 
                contador++;        
            if (distanciaEuclidiana (getXHid (elemento), getYHid (elemento), getXQuadra (quadra) + getWQuadra (quadra), getYQuadra (quadra)) <= dist) 
                contador++;        
            if (distanciaEuclidiana (getXHid (elemento), getYHid (elemento), getXQuadra (quadra), getYQuadra (quadra) + getHQuadra (quadra)) <= dist) 
                contador++;        
            if (distanciaEuclidiana (getXHid (elemento), getYHid (elemento), getXQuadra (quadra) + getWQuadra (quadra), getYQuadra (quadra) + getHQuadra (quadra)) <= dist) 
                contador++;
            
            if (contador == 4){
                fprintf (nometxt, "%s ", getCEPQuadra (quadra));
                excluirElemento (lquadras, getCEPQuadra (quadra));
            }
            contador = 0;
        }
    }
    fprintf (nometxt, "\n\n");
}




    

