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


        liberaArray (texto, nPalavras);
        printf("\n" RED_BACKGROUND "String com todo o texto junto" RESET "\n");
        printf("Arquivo com %li caracteres completo: \n%s \n", strlen(arquivoCompleto),arquivoCompleto);
        /*
        char *palavras[82]; 
        *(palavras) = "palavra1";
        *(palavras+1) = "pal2";
        
        for(size_t i = 0; i < 2; i++){
            printf("%s \n", *(palavras+i)); 
        }
        */
        
        //Parte que tokeniza o texto       
        printf("\n" RED_BACKGROUND "Testes com tokenização" RESET "\n");

        // Essas duas linhas vao ser necessárias no teste 
        // de armazenar as palavras do texto em um array
        char textoTeste[strlen(arquivoCompleto)];
        strcpy(textoTeste,arquivoCompleto);
        
        char *token = "";
        token = strtok(textoCompilado," \n");
        size_t contadorDePalavras = 0;
        size_t tamanhoMaiorPalavra = 0;

        while( token != NULL ) {
            if(strlen(token) > tamanhoMaiorPalavra){
                tamanhoMaiorPalavra = strlen(token);
            }
            printf( "token: %s\n", token);
            token = strtok(NULL, " \n");
            contadorDePalavras++;

        }
        char textoTokenizado[contadorDePalavras+1][tamanhoMaiorPalavra+1];

        printf("O strtok altera a string original: %s \n", textoCompilado); // por isso o textoTeste lá emcima
        printf("Ultimo token: %s \n", token);

        // Esse é o teste de armazenar as palavras do texto em um array
        printf("\n" RED_BACKGROUND "Testes tentando criar um array com as palavras do texto" RESET "\n");

        token = strtok(textoTeste," ");// reiniciando o token
        printf("Reiniciando o token: %s\n", token);
        
        //Inserindo as coisas manualmente
        strcpy(textoTokenizado[0], token);
        printf("txtTokenizado: %s\n", textoTokenizado[0]);
        
        token = strtok(NULL," \n");
        strcpy(textoTokenizado[1], token);
        printf("txtTokenizado: %s\n", textoTokenizado[1]);

        
        printf("\n" RED_BACKGROUND "Essa é a parte que não funciona" RESET "\n");

        //Vendo esses 2 blocos de código em cima, esse aqui deveria funcionar
        size_t j = 2;
        while( token != NULL ) {   
            token = strtok(NULL, " \n");
            strcpy(textoTokenizado[j], token);
            printf("txtTokenizado: %s\n", textoTokenizado[j]);
            j++;
        }

       
    }else{
        char texto[LIMITE_MAX_DO_TEXTO] = "";
        printf(BLUE_BACKGROUND "Digite o seu texto:" RESET "\n" );
        fgets(texto, LIMITE_MAX_DO_TEXTO, stdin);
        printf("%s", texto);
    }

    return EXIT_SUCCESS;
}

