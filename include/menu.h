#include <stdio.h>

char **recebeTexto(void);

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
char *exibeMenuSelecao(char *palavraOriginal,char **sugestoes);
