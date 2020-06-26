#include "funcoes.h"
#include <string.h>

/* Link com todas as cores de texto e background
   https://gist.github.com/RabaDabaDoba/145049536f815903c79944599c6f952a
*/
#define BLUE_BACKGROUND "\e[44m"
#define RED_BACKGROUND "\e[41m"
#define MAGENTA_BACKGROUND "\e[45m"
#define RED_TEXT "\e[0;31m"
#define RESET "\e[0m"


int main(int argc, char *argv[]){
    char textoCompleto[comprimentoDaLista];

    if(argc > 1){
        //Prepara variáveis para usar a função de Eanes modificada
        FILE *arquivo = fopen (argv[1], "r");
        /* Colocar verificações para ver se deu erro na leitura do arquivo */

        
        int nPalavras = 0;
        char **texto = NULL;
        texto = pegaFrases(arquivo, &nPalavras);
        fclose(arquivo);
        
        /* Vê que a função estabelece um tamanho máximo para as palavras/linhas  */
        printf(RED_BACKGROUND "Coisas Lidas pela funçao de Eanes" RESET "\n");

        printf("Quantidade de Linhas: %d\n", nPalavras);

        for (int i = 0; i < nPalavras; i++) {
            printf("%s \n", texto[i]);
        }

        agrupaFrases(texto, nPalavras, textoCompleto);
        liberaArray(texto, nPalavras); 

    }else{
        printf(BLUE_BACKGROUND  "Digite o seu texto:" RESET "\n" );
        fgets(textoCompleto, comprimentoDaLista, stdin);
    }

    /* Tokenizar texto */
    char *palavras[50];
    int quantPalavras = tokenizaTexto(textoCompleto, palavras);

    printf("\n" RED_BACKGROUND "Texto tokenizado" RESET "\n");
    for(size_t j = 0; j < quantPalavras; j++) {
        printf("%s\n", palavras[j]);
    }

    return EXIT_SUCCESS;
}

