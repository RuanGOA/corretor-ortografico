#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Verifica se palavras tokenizadas de uma frase
    pertencem ou não a um dicionário. Retornando um array
    com a mesma quantidade de posições que a lista de tokens
    possui. Para cada posição representando uma palavra, os seguintes dados:
        1 - a palavra existe no dicionario
        2 - a palavra nao existe no dicionario
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

///////////////////////////////
//TESTE
///////////////////////////////
int main(void) {

    char *palavras[3] = {"abobrinha", "abobora", "aboborasso"};
    size_t tamanho_palavras = sizeof(palavras)/sizeof(palavras[0]);
    int palavras_veri[tamanho_palavras];

    const char *dicionario[1] = {"abobora"};  
    size_t tamanho_dicionario = sizeof(dicionario)/sizeof(dicionario[0]);

    verificaFrase(palavras, tamanho_palavras, dicionario, tamanho_dicionario, palavras_veri);

    printf("%d \n", palavras_veri[0]);
    printf("%d \n", palavras_veri[1]);
    printf("%d \n", palavras_veri[2]);

    return 0;
}
