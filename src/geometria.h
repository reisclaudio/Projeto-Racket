#ifndef ___GEOMETRIA_H
#define ___GEOMETRIA_H
//Contém as funçoes que tratam da geometria do trabalho.

/* Funcao que realiza a consulta "d?" do .qry */
void consultaD (char* j, char* k,Lista lformas, FILE * nometxt, FILE * nomesvg);
/* Funcao que realiza a consulta "o?" do .qry */ 
void consultaO (char* j, char* k,Lista lformas, FILE * nometxt, FILE * nomesvg);
/* Funcao que realiza a consulta "i?" do .qry */ 
void consultaI (char* j, double x, double y, Lista lformas, FILE * nometxt, FILE * nomesvg);
/* Funcao que realiza a consulta "BB" do .qry */  
void consultaBB (char * sufixo, char * cor, char * nomesvg, Lista lformas, FILE * nomegeo);
/* Funcao que realiza a consulta "crd?" do .qry */  
bool consultaCRD (char *j, Lista lquadras, Lista lhidrantes, Lista lsemaforos, Lista lRB, FILE *nometxt);
/* Funcao que realiza a consulta "del" do .qry */  
bool consultaDEL (char *j, Lista lquadras, Lista lhidrantes, Lista lsemaforos, Lista lRB, FILE *nometxt);
/* Funcao que realiza a consulta "cbq" do .qry */  
void consultaCBQ (double x, double y, double r, char* cstrk, Lista lquadras, FILE *nometxt);
/* Funcao que realiza a consulta "trns" do .qry */  
void consultaTRNS (double x, double y, double w, double h, double dx, double dy, Lista lquadras,Lista lhidrantes, Lista lsemaforos, Lista lrb, FILE*nometxt);
/* Funcao que realiza a consulta "dq" do .qry */  
void consultaDQ (char* id, char* metrica, double dist, Lista lquadras, Lista lhidrantes, Lista lsemaforos, Lista lRB, FILE* nometxt, FILE* nomesvg);

/* Funcao que calcula a distancia euclidiana entre dois pontos */
double distanciaEuclidiana (double x1, double y1, double x2, double y2);
/* Funcao que calcula a distancia de Manhaattan entre dois pontos */
double manhattanDistance (double x1, double y1, double x2, double y2);
/* Funcao que compara valores */
double clamp (double pc, double pmi, double pma);

#endif
