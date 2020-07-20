#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Usa essa funcao quando for ler o dicionário */
char **pegaPalavras (FILE *fp, int *n);

/*
    Verifica num dicionario passado como parametro, as 3 palavras
    mais similares a um token também passado como parametro. Retorna
    um array contendo essas 3 palavras.
*/
char ** sugerePalavras(char *token, char **dicionario, int tamanho_dicionario);

/*
    Função auxiliar. Verifica num array de floats passado como parametro,
    a posição do menor valor, e retorna-o.
*/
int posMenorValor(float *arr, int tamanho);


/*  
    Verifica se cada token em uma lista de token está ou não em uma
    lista de palavras(dicionario). Retorna um array de mesmo tamanho
    do array de tokens, populado com:
        1 - se o token está no dicionario
        0 - se o token não está no dicionario
*/
int * verificaFrase(char **palavras, int tamanho_palavras, char **dicionario, int tamanho_dicionario);

/*
    Função auxiliar. Verifica se uma palavra está ou não em um dicionario.
        1 - a palavra existe no dicionario
        2 - a palavra nao existe no dicionario
*/
int verificaPalavra(char *palavra, char **dicionario, int tamanho_dicionario);
