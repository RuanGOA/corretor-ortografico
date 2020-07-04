#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int * verificaFrase(char **palavras, int tamanho_palavras, char **dicionario, int tamanho_dicionario, int *palavras_verificadas) {

    size_t j; int achou;
    for(size_t i = 0; i < tamanho_palavras; i++) {
        printf("--- \n");
        j = 0; achou = 0;
        while(j < tamanho_dicionario && achou == 0) {
            int comp = strcmp(palavras[i], dicionario[j]);
            if(comp == 0) {
                achou = 1;
            }

            j++;
        }

        palavras_verificadas[i] = achou;
    }

    for(int k = 0; k < tamanho_palavras; k++){
        printf("%d - \n", palavras_verificadas[k]);
    }

    return palavras_verificadas;
}

int main(void) {

    char *palavras[3] = {"abobrinha", "abobora", "aboborasso"};
    size_t tamanho_palavras = sizeof(palavras)/sizeof(palavras[0]);
    int palavras_veri[tamanho_palavras];

    char *dicionario[1] = {"abobora"};  
    size_t tamanho_dicionario = sizeof(dicionario)/sizeof(dicionario[0]);

    verificaFrase(palavras, tamanho_palavras, dicionario, tamanho_dicionario, palavras_veri);

    printf("%d \n", palavras_veri[0]);
    printf("%d \n", palavras_veri[1]);
    printf("%d \n", palavras_veri[2]);

    return 0;
}
