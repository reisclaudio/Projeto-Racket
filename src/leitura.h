#ifndef ___LEITURA_H
#define ___LEITURA_H
//Contem as funcoes que fazem a leitura dos arquivos de entrada.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#include"lista.h"

/* Principal funcao do codigo, recebe varios parametros para alimentar outras funcoes */
void Learqs (FILE * nomegeo,FILE * nomeqry, char * nomesvg, char * nometxt, char * nomesvg2);
/* Funcao que le apenas o .geo, para o caso de o .qry ser nulo */
void Legeo (FILE * nomegeo, char * nomesvg);
/* Funcao que le apenas o .geo para auxiliar na consulta "BB" */
void geoBB (FILE * nomegeo, FILE * nomesvg, Lista lformas, char * cor);
/* Funcao que le as consultas do arquivo .qry */
void LeQRY (FILE * nomearq,FILE * nomegeo,FILE * nometxt,FILE * nomesvg, char * nomesvg2, Lista Lformas, Lista Lquadra, Lista LHidrante,
Lista Lsemaforo, Lista LRadio);

#endif

