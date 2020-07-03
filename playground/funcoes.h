#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define comprimentoDaLista 256
#define comprimentoDasPalavras 21
#define QUANT_MAX_CARACTERES 240

char **pegaPalavras (FILE *fp, int *n);
char **pegaFrases (FILE *fp, int *n);
void pegaTexto(FILE *arquivo, int *nPalavras, char **destino);


void liberaArray (char **palavras, int linhas);
void agrupaFrases(char **frases, int nFrases, char *stringDestino);
int tokenizaTexto(char *texto, char **destino);
int *buscaNoDicionario(char **palavras, int nPalavras , char **dicionario, int tamanhoDicionario);
int buscaBinariaString(char *palavra, char **dicionario, int *inicioDicionario, int *fimDicionario);

#endif
