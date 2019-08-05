#include"leitura.h"
#include"geometria.h"
#include"lista.h"

void LeQRY (FILE * nomearq,FILE * nomegeo,FILE * nometxt,FILE * nomesvg, char * nomesvg2, Lista Lformas, Lista Lquadra, Lista LHidrante,
Lista Lsemaforo, Lista LRadio)
{   
    char cond[20], metrica[5], aux, strtexto[50], sufixo[20], cor[24], cstrk[24];
    char j[20], k[20];
    double x, y, w, h, r;
    double dx, dy, dist;
    
    while (1){
        fscanf (nomearq, "%s", cond);

        if (feof(nomearq)){
            break;
        }

        if (strcmp (cond, "d?") == 0){
            fscanf(nomearq, "%s", j);
            fscanf(nomearq, "%s", k);

            fprintf(nometxt, "d? %s %s\n", j, k);
            consultaD (j, k, Lformas,nometxt, nomesvg);
            
            fscanf(nomearq, "%c", &aux);
        }

        else if (strcmp (cond, "o?") == 0){
            fscanf (nomearq, "%s", j);
            fscanf (nomearq, "%s", k);

            fprintf(nometxt, "o? %s %s\n", j, k);
            consultaO (j, k, Lformas, nometxt, nomesvg);
            
            fscanf(nomearq, "%c", &aux); 
        }

        else if (strcmp (cond, "i?") == 0){
            fscanf (nomearq, "%s", j);
            fscanf (nomearq, "%lf", &x);
            fscanf (nomearq, "%lf", &y);

            fprintf (nometxt, "i? %s %lf %lf\n", j, x, y);
            consultaI (j, x, y, Lformas, nometxt, nomesvg);

            fscanf (nomearq, "%c", &aux);
        }

        else if (strcmp (cond, "bb") == 0){
            fscanf (nomearq, "%s", sufixo);
            fscanf (nomearq, "%s", cor);

            consultaBB (sufixo, cor, nomesvg2,Lformas, nomegeo);

            fscanf (nomearq, "%c", &aux);
        }

        else if (strcmp (cond, "crd?") == 0){
            fscanf (nomearq, "%s", j);

            fprintf (nometxt, "crd? %s\n", j);            
            consultaCRD (j, Lquadra, LHidrante, Lsemaforo, LRadio, nometxt);

            fscanf (nomearq, "%c", &aux);
        }

        else if (strcmp (cond, "del") == 0){
            fscanf (nomearq, "%s", j);

            fprintf (nometxt, "del %s\n", j);
            consultaDEL (j, Lquadra, LHidrante, Lsemaforo, LRadio, nometxt);

            fscanf (nomearq, "%c", &aux);
        }

        else if (strcmp (cond, "cbq") == 0){
            fscanf (nomearq, "%lf", &x);
            fscanf (nomearq, "%lf", &y);
            fscanf (nomearq, "%lf", &r);
            fscanf (nomearq, "%s", cstrk);

            fprintf (nometxt, "cbq %lf %lf %lf %s\n", x, y, r, cstrk);
            consultaCBQ (x, y, r, cstrk, Lquadra, nometxt);

            fscanf (nomearq, "%c", &aux);
        }

        else if (strcmp (cond, "trns") == 0){
            fscanf (nomearq ,"%lf", &x);
            fscanf (nomearq ,"%lf", &y);
            fscanf (nomearq ,"%lf", &w);
            fscanf (nomearq ,"%lf", &h);
            fscanf (nomearq ,"%lf", &dx);
            fscanf (nomearq ,"%lf", &dy);

            fprintf (nometxt, "trns %lf %lf %lf %lf %lf %lf\n",x, y, w, h, dx, dy);
            consultaTRNS (x, y, w, h, dx, dy, Lquadra, LHidrante, Lsemaforo, LRadio, nometxt);

            fscanf (nomearq, "%c", &aux);
        }

        else if (strcmp (cond, "dq") == 0){
            fscanf (nomearq, "%s", metrica);
            fscanf (nomearq, "%s", j);
            fscanf (nomearq, "%lf", &dist);

            fprintf (nometxt, "dq %s %s %lf\n", metrica, j, dist);
            consultaDQ (j, metrica, dist, Lquadra, LHidrante, Lsemaforo, LRadio, nometxt, nomesvg);

            fscanf (nomearq, "%c", &aux);
        }
    }
}
