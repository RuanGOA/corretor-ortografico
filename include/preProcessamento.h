#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "constantes.h"

/*Funções que manipulam o texto recebido*/


char **pegaFrases (FILE *fp, int *n);

void agrupaFrases(char **frases, int nFrases, char *stringDestino);

int tokenizaTexto(char *texto, char **destino);
