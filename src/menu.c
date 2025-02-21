#include "menu.h"
#include "constantes.h"


char **recebeTexto(void)
{
    /*
    char *texto[QUANT_MAX_CARACTERES];

    printf(BLUE_BACKGROUND  "Digite o seu texto:" RESET "\n" );
    fgets(texto, QUANT_MAX_CARACTERES, stdin);

    return texto;
    */
}


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
        printf("[1] - %s \n", sugestoes[0]);
        printf("[2] - %s \n", sugestoes[1]);
        printf("[3] - %s \n", sugestoes[2]);
        printf("[0] - Manter a palavra original (%s) \n", palavraOriginal);
        printf("Digite o número da sua escolha: \n");
        printf("> ");
        scanf("%d", &indiceSubstituicao);
        printf("\n");
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
/*
int main (void)
{
    char *palavras[3] = {"sugest1", "sugest2", "sugest3"};

    char *correcao = exibeMenuSelecao("Original",palavras);
    // Não sei o que é esse % que aparece na saída, 
    // mas parece que não tem nada a ver com a palavra
    // então está funcionando normal
    printf("%s ", correcao); 
}
*/
