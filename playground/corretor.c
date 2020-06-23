#include "funcoes.h"
#include <string.h>

/* Link com todas as cores de texto e background
   https://gist.github.com/RabaDabaDoba/145049536f815903c79944599c6f952a
*/
#define LIMITE_MAX_DO_TEXTO 280
#define BLUE_BACKGROUND "\e[44m"
#define RED_BACKGROUND "\e[41m"
#define RED_TEXT "\e[0;31m"
#define RESET "\e[0m"


int main(int argc, char *argv[]){

    if(argc > 1){
        //Prepara variáveis para usar a função de Eanes modificada
        FILE *arquivo = fopen (argv[1], "r");
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

        /* Junta todas as linhas em uma só string*/
        char arquivoCompleto[] = "";

        for (size_t i = 0; i < nPalavras; i++)
        {
            strcat(arquivoCompleto, texto[i]);
        }
        /*
            Faz a cópia dessa string que contém todo o texto para outra variável
            porque quando libera o array com o texto lido do arquivo (ainda separado)
            o conteúdo dessa string compilada é perdido
        */
        char textoCompilado[strlen(arquivoCompleto)];
        

        strcpy(textoCompilado,arquivoCompleto);

////////////////////	
				char *token = strtok(textoCompilado," ");

        char stringzona[strlen(arquivoCompleto)];
        strcpy(stringzona,arquivoCompleto);

				char *words[50], sep[4] = " .\n";

				token = strtok(stringzona, sep);

				size_t i = 0;
				while(token != NULL) {
					words[i++] = token;
					token = strtok(NULL, sep);
				}

				printf("\n" RED_BACKGROUND "Texto tokenizado" RESET "\n");
				for(size_t j = 0; j < i; j++) {
					printf("%s\n", words[j]);
				}
       
    }else{
        char texto[LIMITE_MAX_DO_TEXTO] = "";
        printf(BLUE_BACKGROUND "Digite o seu texto:" RESET "\n" );
        fgets(texto, LIMITE_MAX_DO_TEXTO, stdin);
        printf("%s", texto);
    }

    return EXIT_SUCCESS;
}

