#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define comprimentoDaLista 256
#define COMP_MAX_PALAVRA 21
#define QUANT_MAX_CARACTERES 240

#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))


char **pegaPalavras (FILE *fp, int *n);
char **pegaFrases (FILE *fp, int *n);
void pegaTexto(FILE *arquivo, int *nPalavras, char **destino);

int * verificaFrase(char **palavras, int tamanho_palavras, char const **dicionario, int tamanho_dicionario, int *palavras_verificadas);
int verificaPalavra(char *palavra, char const **dicionario, int tamanho_dicionario);

void liberaArray (char **palavras, int linhas);
void agrupaFrases(char **frases, int nFrases, char *stringDestino);
int tokenizaTexto(char *texto, char **destino);
void buscaNoDicionario(char **palavras, int nPalavras , char **dicionario, int tamanhoDicionario, int *resultado);
int buscaBinariaString(char *palavra, char **dicionario, int inicioDicionario, int fimDicionario);

int levenshteinDist(char *s1, int s1len, char *s2, int s2len);
float levenshtein(char *palavra1, char *palavra2);

#endif
