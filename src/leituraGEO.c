#include"leitura.h"
#include"arquivos.h"
#include"lista.h"
#include"./Elementos/circulo.h"
#include"./Elementos/retangulo.h"
#include"./Elementos/quadra.h"
#include"./Elementos/hidrante.h"
#include"./Elementos/semaforo.h"
#include"./Elementos/radioBase.h"

void Legeo (FILE * nomegeo, char * nomesvg)
{
    FILE * arqsvg;	
	arqsvg = fopen (nomesvg, "w+");
	VerificaArquivo(arqsvg, nomesvg);
		
	fprintf (arqsvg, "<svg>\n");

	char tipo [10], barraN, texto[500], cep[50], cor1[24], cor2[24], id[50], c1q[24], c2q[24],
	c1h[24], c2h[24], c1t[24], c2t[24], c1s[24], c2s[24];
	char swq[20], swh[20], swt[20], sws[20], swc[20], swr[20];
	int nx = 1000, nq = 1000, nh = 1000, ns = 1000, nr = 1000;
	double x, y, w, h, r;

	//Atribui cores default
	strcpy (c1q, "blue");
	strcpy (c2q, "black");
	strcpy (c1h, "red");
	strcpy (c2h, "black");
	strcpy (c1s, "green");
	strcpy (c2s, "black");
	strcpy (c1t, "yellow");
	strcpy (c2t, "black");
	strcpy (swc, "1");
	strcpy (swr, "1");
	strcpy (swq, "1");
	strcpy (swh, "1");
	strcpy (sws, "1");
	strcpy (swt, "1");

	//Ponteiros void para cada estruturas
	Circulo circulo;
	Retangulo retangulo;
	Quadra quadra;
	Hidrante hidrante;
	Semaforo semaforo;
	RadioBase radioBase;
	
	//Listas
	Lista listaFormas;
	Lista listaQuadra;
	Lista listaHid;
	Lista listaSema;
	Lista listaRB;

	while (1){
		fscanf (nomegeo, "%s", tipo);

		if (feof (nomegeo))
			break;

		if (strcmp (tipo, "nx") == 0){
			fscanf (nomegeo, "%d", &nx);
			fscanf (nomegeo, "%d", &nq);
			fscanf (nomegeo, "%d", &nh);
			fscanf (nomegeo, "%d", &ns);
			fscanf (nomegeo, "%d", &nr);

			fscanf (nomegeo, "%c", &barraN);
		}
	}

	listaFormas = iniciaLista (nx);
	listaQuadra = iniciaLista (nq);
	listaHid = iniciaLista (nh);
	listaSema = iniciaLista (ns);
	listaRB = iniciaLista (nr);

	rewind (nomegeo);
	
	// Faz a leitura de todo o .geo
	while (1){
		fscanf (nomegeo, "%s", tipo);

		if (feof(nomegeo)){
			break;
		}

		if (strcmp (tipo, "c") == 0){
			fscanf (nomegeo, "%s", id);
			fscanf (nomegeo, "%lf", &r);
			fscanf (nomegeo, "%lf", &x);
			fscanf (nomegeo, "%lf", &y);
			fscanf (nomegeo, "%s", cor1);
			fscanf (nomegeo, "%s", cor2);

			circulo = criaCirculo (id, x, y, r, cor1, cor2, swc);
			inserirElemento (listaFormas, circulo);

			fscanf (nomegeo, "%c", &barraN); //fscanf para pegar  "\n"
		}
		else if (strcmp (tipo, "r") == 0){
			fscanf (nomegeo, "%s", id);
			fscanf (nomegeo, "%lf", &w);	
			fscanf (nomegeo, "%lf", &h);
			fscanf (nomegeo, "%lf", &x);	
			fscanf (nomegeo, "%lf", &y);
			fscanf (nomegeo, "%s", cor1);
			fscanf (nomegeo, "%s", cor2);
			
			retangulo = criaRetangulo (id, x, y, w, h, cor1, cor2, swr);
			inserirElemento (listaFormas, retangulo);
			
			fscanf (nomegeo, "%c", &barraN); //fscanf para pegar  "\n"
		}

		else if (strcmp (tipo, "q") == 0){
			fscanf (nomegeo, "%s", cep);
			fscanf (nomegeo, "%lf", &x);
			fscanf (nomegeo, "%lf", &y);
			fscanf (nomegeo, "%lf", &w);
			fscanf (nomegeo, "%lf", &h);

			quadra = criaQuadra (cep, x, y, w, h, c1q, c2q, swq);
			inserirElemento (listaQuadra, quadra);

			fscanf (nomegeo, "%c", &barraN); //fscanf para pegar "/n"
		}

		else if (strcmp (tipo, "h") == 0){
			fscanf (nomegeo, "%s", id);
			fscanf (nomegeo, "%lf", &x);
			fscanf (nomegeo, "%lf", &y);

			hidrante = criaHidrante (id, x, y, c1h, c2h, swh);
			inserirElemento (listaHid, hidrante);

			fscanf (nomegeo, "%c", &barraN); //fscanf para pegar "/n"
		}

		else if (strcmp (tipo, "s") == 0){
			fscanf (nomegeo, "%s", id);
			fscanf (nomegeo, "%lf", &x);
			fscanf (nomegeo, "%lf", &y);

			semaforo = criaSemaforo (id, x, y, c1s, c2s, sws);
			inserirElemento (listaSema, semaforo);

			fscanf (nomegeo, "%c", &barraN); //fscanf para pegar "/n"
		}

		else if (strcmp (tipo, "rb") == 0){
			fscanf (nomegeo, "%s", id);
			fscanf (nomegeo, "%lf", &x);
			fscanf (nomegeo, "%lf", &y);

			radioBase = criaRadioBase (id, x, y, c1t, c2t, swt);
			inserirElemento (listaRB, radioBase);

			fscanf (nomegeo, "%c", &barraN); //fscanf para pegar "/n"
		}

		else if (strcmp (tipo, "t") == 0){
			fscanf (nomegeo, "%lf", &x);
			fscanf (nomegeo, "%lf", &y);
			fgets(texto, 500, nomegeo);
			svgprinttext(texto,x, y, arqsvg);
		}

		else if (strcmp (tipo, "cq") == 0){
			fscanf (nomegeo, "%s", c1q);
			fscanf (nomegeo, "%s", c2q);
			fscanf (nomegeo, "%s", swq);

			fscanf (nomegeo, "%c", &barraN); //fscanf para pegar "/n"
		}

		else if (strcmp (tipo, "ch") == 0){
			fscanf (nomegeo, "%s", c1h);
			fscanf (nomegeo, "%s", c2h);
			fscanf (nomegeo, "%s", swh);

			fscanf (nomegeo, "%c", &barraN); //fscanf para pegar "/n"
		}

		else if (strcmp (tipo, "cr") == 0){
			fscanf (nomegeo, "%s", c1t);
			fscanf (nomegeo, "%s", c2t);
			fscanf (nomegeo, "%s", swt);

			fscanf (nomegeo, "%c", &barraN); //fscanf para pegar "/n"
		}

		else if (strcmp (tipo, "cs") == 0){
			fscanf (nomegeo, "%s", c1s);
			fscanf (nomegeo, "%s", c2s);
			fscanf (nomegeo, "%s", sws);

			fscanf (nomegeo, "%c", &barraN); //fscanf para pegar "/n"
		}

		else if (strcmp (tipo, "sw") == 0){
			fscanf (nomegeo, "%s", swc);
			fscanf (nomegeo, "%s", swr);

			fscanf (nomegeo, "%c", &barraN); //fscanf para pegar "/n"
		}
	}

	imprimeListaSVG (listaFormas, arqsvg);
	imprimeListaSVG (listaFormas, arqsvg);
	imprimeListaSVG (listaQuadra, arqsvg);
	imprimeListaSVG (listaHid, arqsvg);
	imprimeListaSVG (listaSema, arqsvg);
	imprimeListaSVG (listaRB, arqsvg);
	fprintf (arqsvg, "</svg>\n");

	desalocarLista (listaFormas, freeCircRet);
	desalocarLista (listaHid, freeHidrante);
	desalocarLista (listaQuadra, freeQuadra);
	desalocarLista (listaSema, freeSemaforo);
	desalocarLista (listaRB, freeRadioBase);
}

void geoBB (FILE * nomegeo, FILE * nomesvg, Lista lformas, char * cor)
{
    char tipo[50], barran, texto[500], cor1[24], cor2[24];
	char id[50] ,swc[20], swr[20];
	double x, y, r, w, h, xr, yr, wr, hr, cx, cy, rx, ry;

	//Atribui sw default
	strcpy (swc, "1");
	strcpy (swr, "1");
	
	Circulo circulo;
	Retangulo retangulo;

    fprintf (nomesvg, "<svg>\n");
	rewind (nomegeo);

	//Faz a leitura de todo o .geo 
	//Printa no svg3 o que a consulta "bb" pede
    while (1){
		fscanf (nomegeo, "%s", tipo);

        if (feof(nomegeo)){
			fprintf (nomesvg, "</svg>");
			break;
        }

		else if (strcmp (tipo, "sw") == 0){
			fscanf (nomegeo, "%s", swc);
			fscanf (nomegeo, "%s", swr);

			fscanf (nomegeo, "%c", &barran); //fscanf para pegar "/n"
		}

        if (strcmp (tipo, "c") == 0){
			fscanf (nomegeo, "%s", id);	
			fscanf (nomegeo, "%lf", &r);
			fscanf (nomegeo, "%lf", &x);
			fscanf (nomegeo, "%lf", &y);
			fscanf (nomegeo, "%s", cor1);
			fscanf (nomegeo, "%s", cor2);
			circulo = criaCirculo (id, x, y, r, cor1, cor2, swc);
			
			svgprintcircle(circulo, nomesvg);

			//Calculo da largura, altura, x e y do retangulo "bb"
			hr = 2*getRaioCirc (circulo);
			wr = 2*getRaioCirc (circulo);
			xr = getXCirc (circulo) - getRaioCirc (circulo);
			yr = getYCirc (circulo) - getRaioCirc (circulo);

			svgprintrectBB (xr, yr, wr, hr,cor,  nomesvg);

			fscanf (nomegeo, "%c", &barran); //fscanf para pegar "\n"
		}
		else if (strcmp (tipo, "r") == 0){
			fscanf (nomegeo, "%s", id);
			fscanf (nomegeo, "%lf", &w);	
			fscanf (nomegeo, "%lf", &h);
			fscanf (nomegeo, "%lf", &x);	
			fscanf (nomegeo, "%lf", &y);
			fscanf (nomegeo, "%s", cor1);
			fscanf (nomegeo, "%s", cor2);
			retangulo = criaRetangulo (id, x, y, w, h, cor1, cor2, swr);
			
			svgprintrect(retangulo, nomesvg);

			//Calculo do (centro x, centroy), do raio x e do raio y da elipse "bb"
			cx = getXRet (retangulo) + getWRet (retangulo)/2.0;
			cy = getYRet (retangulo) + getHRet (retangulo)/2.0;
			ry = getHRet (retangulo)/2;
			rx = getWRet (retangulo)/2;

			svgprintellipseBB(cx, cy, rx, ry, cor, nomesvg);

			fscanf (nomegeo, "%c", &barran); //fscanf para pegar  "\n"
        }
    }
}