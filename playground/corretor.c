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
#define QUANT_MAX_PALAVRAS 50

int main(int argc, char *argv[]){

    char textoCompleto[QUANT_MAX_CARACTERES];

    if(argc > 1){

        FILE *arqTexto = fopen (argv[1], "r");
        int nLinhas = 0;
        char **texto;

        if (!arqTexto) { /* valida a abertura do arquivo */
            fprintf (stderr, "erro: abertura do arquivo falhou.\n");
            return 1;
        }

        if (!(texto = pegaFrases (arqTexto, &nLinhas))) {
            fprintf (stderr, "erro: pegaPalavras retornou NULL.\n");
            return 1;
        }
        
        fclose(arqTexto);
        
        agrupaFrases(texto, nLinhas, textoCompleto);
        liberaArray(texto, nLinhas);

    }else{
        printf(BLUE_BACKGROUND  "Digite o seu texto:" RESET "\n" );
        fgets(textoCompleto, comprimentoDaLista, stdin);
    }

    /* Tokenizar texto */
    char *palavras[QUANT_MAX_PALAVRAS];
    int quantPalavras = tokenizaTexto(textoCompleto, palavras);


    /* Ler dicionário  */  
    FILE *arqDicionario = fopen(argv[2], "r");
    char **dicionario;
    int nPalavrasDic = 0;


    if (!arqDicionario) { /* valida a abertura do arquivo */
        fprintf (stderr, "erro: abertura do arquivo falhou.\n");
        return 1;
    }

    if (!(dicionario = pegaPalavras (arqDicionario, &nPalavrasDic))) {
        fprintf (stderr, "erro: pegaPalavras retornou NULL.\n");
        return 1;
    }

    printf("\n" RED_BACKGROUND "Tamanho do Dicionário: %d" RESET "\n", nPalavrasDic);
    printf("%s \n", dicionario[0]); 
    printf("%s \n", dicionario[1]);
    printf("%s \n", dicionario[2]);  
  
    int resultadoBuscaDic[QUANT_MAX_PALAVRAS] = {0}; 
    buscaNoDicionario(palavras, quantPalavras, dicionario, nPalavrasDic, resultadoBuscaDic);

    fclose(arqDicionario);    
    liberaArray(dicionario,nPalavrasDic);


    return EXIT_SUCCESS;
}

