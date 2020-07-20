#include "constantes.h"
#include "dicionario.h"
#include "menu.h"
#include "preProcessamento.h"
#include "util.h"

int main(int argc, char *argv[]){

    char textoCompleto[QUANT_MAX_CARACTERES];

    /* Ler dos dados */
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

    printf("Texto recebido:\n%s\n", textoCompleto);
    

    /* Tokenizar texto */
    char *palavras[QUANT_MAX_PALAVRAS];
    int quantPalavras = tokenizaTexto(textoCompleto, palavras);


    /* Ler dicionário  */  
    FILE *arqDicionario = fopen(argv[2], "r");
    char **dicionario;
    int nPalavrasDic = 0;

    /* valida a abertura do arquivo */
    if (!arqDicionario) { 
        fprintf (stderr, "erro: abertura do arquivo falhou.\n");
        return 1;
    }

    if (!(dicionario = pegaPalavras (arqDicionario, &nPalavrasDic))) {
        fprintf (stderr, "erro: pegaPalavras retornou NULL.\n");
        return 1;
    }

    printf("\n" RED_BACKGROUND "Tamanho do Dicionário: %d" RESET "\n", nPalavrasDic);
    printf(RED_BACKGROUND "Exemplos do dicionário: " RESET "\n");
    printf("%s \n", dicionario[243]); 
    printf("%s \n", dicionario[69692]);
    printf("%s \n", dicionario[2345]);  
    printf("\n---------------------\n\n");
  
    //int resultadoBuscaDic[QUANT_MAX_PALAVRAS] = {0};  

    char resultado[300];
    strcpy(resultado, "");

    char **sugestoesCache;
    char *escolhaCache;
    int *estaoNoDic = verificaFrase(palavras, quantPalavras, dicionario, nPalavrasDic);
    for(size_t i = 0; i < quantPalavras; i++) {

        if(estaoNoDic[i] == 1) {
            sugestoesCache = sugerePalavras(palavras[i], dicionario, nPalavrasDic);
            
            escolhaCache = exibeMenuSelecao(palavras[i], sugestoesCache);

        } else {
            escolhaCache = palavras[i];

        }
        
        strcat(resultado, escolhaCache);
        strcat(resultado, " ");
    }

    printf(RED_BACKGROUND "Resultado: " RESET RED_TEXT "\n%s\n\n" RESET, resultado);

    fclose(arqDicionario);    
    liberaArray(dicionario,nPalavrasDic);


    return 0;
}

