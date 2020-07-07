#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLUE_BACKGROUND "\e[44m"
#define RED_BACKGROUND "\e[41m"

#define RESET "\e[0m"
#define RED_TEXT "\e[0;31m"

/*
    Recebe um array de quatro palavras
    Pede pro usuário digitar um número
    de 0 a 3 e retorna a palavra contida
    nessa posição do array
    
    Parâmetros
    sugestoes[0] - para a palavra original
    sugestoes[1:3] - para as sugestões de 
                     substituição
*/
char *exibeMenuSelecao(char *palavraOriginal,char **sugestoes)
{
    int indiceSubstituicao = -1;
    while(indiceSubstituicao < 0 || indiceSubstituicao > 3)
    {
        printf("Esta palavra parece estar incorreta: " RED_TEXT  "%s\n" RESET, palavraOriginal);
        printf("Deseja substituí-la por:\n");
        printf("[1] - %s ou\n", sugestoes[0]);
        printf("[2] - %s ou\n", sugestoes[1]);
        printf("[3] - %s ?\n", sugestoes[2]);
        printf("Digite 0 para manter a palavra original (%s) \n", palavraOriginal);
        printf("> ");
        scanf("%d", &indiceSubstituicao);
    }
    if(indiceSubstituicao == 0)
    {
        return palavraOriginal;
    }else
    {
        return sugestoes[indiceSubstituicao - 1];
    }
    
    
}

/* Teste */
int main (void)
{
    char *palavras[3] = {"sugest1", "sugest2", "sugest3"};

    char *correcao = exibeMenuSelecao("Original",palavras);
    // Não sei o que é esse % que aparece na saída, 
    // mas parece que não tem nada a ver com a palavra
    // então está funcionando normal
    printf("%s ", correcao); 
}

