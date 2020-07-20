#include "dicionario.h"
#include "constantes.h"
#include "util.h"

/* Usa essa funcao quando for ler o dicionário */
char **pegaPalavras (FILE *fp, int *n) {

    char **palavras = NULL;
    char buf[COMP_MAX_PALAVRA + 1] = {0};
    int maxlen = comprimentoDaLista > 0 ? comprimentoDaLista : 1;

    if (!(palavras = calloc (maxlen, sizeof *palavras))) {
        fprintf (stderr, "pegaPalavras() erro: memória virtual exaurida.\n");
        return NULL;
    }

    while (fgets (buf, COMP_MAX_PALAVRA + 1, fp)) {

        size_t wordlen = strlen (buf);  

        if (buf[wordlen - 1] == '\n')  
            buf[--wordlen] = 0;

        palavras[(*n)++] = strdup (buf);   

        if (*n == maxlen) { 
            void *tmp = realloc (palavras, maxlen * 2 * sizeof *palavras);
            if (!tmp) {
                fprintf (stderr, "pegaPalavras() realloc: memória exaurida.\n");
                return palavras;
            }
            palavras = tmp;
            memset (palavras + maxlen, 0, maxlen * sizeof *palavras);
            maxlen *= 2;
        }
    }

    return palavras;
}


/*
    Verifica num dicionario passado como parametro, as 3 palavras
    mais similares a um token também passado como parametro. Retorna
    um array contendo essas 3 palavras.
*/
char ** sugerePalavras(char *token, char **dicionario, int tamanho_dicionario) {

    char **sugestoes = malloc(sizeof(char) * 3);
    float coef_sugestoes[3] = {-1, -1, -1};
    int menor = 0;

    float coef = 0;
    for(size_t i = 0; i < tamanho_dicionario; i++) {
        coef = levenshtein(token, dicionario[i]);

        if(coef_sugestoes[menor] < coef) {
            *(sugestoes + menor) = dicionario[i];
            coef_sugestoes[menor] = coef;

            coef = 0;

            menor = posMenorValor(coef_sugestoes, 3);
        }
    }

    return sugestoes;
}


/*
    Função auxiliar. Verifica num array de floats passado como parametro,
    a posição do menor valor, e retorna-o.
*/
int posMenorValor(float *arr, int tamanho) {
    int pos_menor = 0;
    for(size_t i = 0; i < tamanho; i++) {
        if(arr[pos_menor] > arr[i]) {
            pos_menor = i;
        }
    }

    return pos_menor;
}


/*  
    Verifica se cada token em uma lista de token está ou não em uma
    lista de palavras(dicionario). Retorna um array de mesmo tamanho
    do array de tokens, populado com:
        1 - se o token está no dicionario
        0 - se o token não está no dicionario
*/
int * verificaFrase(char **palavras, int tamanho_palavras, char **dicionario, int tamanho_dicionario) {

    int *tokens_verificados = malloc(sizeof(int) * tamanho_palavras);

    int achou;
    for(size_t i = 0; i < tamanho_palavras; i++) {

        achou = verificaPalavra(palavras[i], dicionario, tamanho_dicionario);

        tokens_verificados[i] = achou;
    }

    return tokens_verificados;
}


/*
    Função auxiliar. Verifica se uma palavra está ou não em um dicionario.
        1 - a palavra existe no dicionario
        2 - a palavra nao existe no dicionario
*/
int verificaPalavra(char *palavra, char **dicionario, int tamanho_dicionario) {

    size_t j = 0, achou = 0;
    while(j < tamanho_dicionario && achou == 0) {
        int comp = strcmp(palavra, dicionario[j]);
        if(comp == 0) {
            achou = 1;
        }

        j++;
    }

    return achou;
}
