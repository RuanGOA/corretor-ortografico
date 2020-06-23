#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define comprimentoDaLista 256
#define comprimentoDasPalavras 21

char **pegaPalavras (FILE *fp, int *n);
char **pegaFrases (FILE *fp, int *n);
void liberaArray (char** palavras, int linhas);

#endif