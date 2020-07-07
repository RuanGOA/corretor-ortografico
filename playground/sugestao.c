#include "funcoes.h"
#include "levenshtein.c"

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

            menor = pos_menor_valor(coef_sugestoes, 3);
        }
    }

    return sugestoes;
}

/*
    Função auxiliar. Verifica  num array de floats passado como parametro,
    a posição do menor valor, e retorna-o.
*/
int pos_menor_valor(float *arr, int tamanho) {
    int pos_menor = 0;
    for(size_t i = 0; i < tamanho; i++) {
        if(arr[pos_menor] > arr[i]) {
            pos_menor = i;
        }
    }

    return pos_menor;
}

///////////////////////////////
//TESTE
///////////////////////////////
/*
int main(void) {

    char *palavras[10] = {"seu", "joao", "foi", "na", "feira", "e", "trouxe", "a", "maior", "batata"};
    size_t tamanho_palavras = sizeof(palavras)/sizeof(palavras[0]);

    char *dicionario[9] = {"sua", "zeh", "joaninha", "feira", "a", "e", "mais", "joao", "joaozinho"};  
    size_t tamanho_dicionario = sizeof(dicionario)/sizeof(dicionario[0]);

    char **sugs = sugerePalavras(palavras[1], dicionario, tamanho_dicionario);

    printf("%s \n", sugs[0]);

    return 0;
}*/