#include "funcoes.h"


/*  
    Verifica se cada token em uma lista de token está ou não em uma
    lista de palavras(dicionario). Retorna um array de mesmo tamanho
    do array de tokens, populado com:
        1 - se o token está no dicionario
        0 - se o token não está no dicionario
*/
int * verificaFrase(char **palavras, int tamanho_palavras, char const **dicionario, int tamanho_dicionario, int *palavras_verificadas) {

    int achou;
    for(size_t i = 0; i < tamanho_palavras; i++) {

        achou = verificaPalavra(palavras[i], dicionario, tamanho_dicionario);

        palavras_verificadas[i] = achou;
    }

    return palavras_verificadas;
}

/*
    Função auxiliar. Verifica se uma palavra está ou não em um dicionario.
        1 - a palavra existe no dicionario
        2 - a palavra nao existe no dicionario
*/
int verificaPalavra(char *palavra, char const **dicionario, int tamanho_dicionario) {

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