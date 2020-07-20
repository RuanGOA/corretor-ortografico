#include "preProcessamento.h"

/*Funções que manipulam o texto recebido*/


/* Usa essa funcao quando for ler o texto */
char **pegaFrases (FILE *fp, int *n) {

    char **palavras = NULL;
    char buf[COMP_MAX_PALAVRA + 1] = {0};
    int maxlen = comprimentoDaLista > 0 ? comprimentoDaLista : 1;

    if (!(palavras = calloc (maxlen, sizeof *palavras))) {
        fprintf (stderr, "pegaPalavras() erro: memória virtual exaurida.\n");
        return NULL;
    }

    while (fgets (buf, COMP_MAX_PALAVRA + 1, fp)) {

        size_t wordlen = strlen (buf);  
       
        palavras[(*n)++] = strdup (buf);

        if (*n == maxlen) {
            void *tmp = realloc (palavras, maxlen * 2 * sizeof *palavras);
            if (!tmp) {
                fprintf (stderr, "pegaPalavras() realloc: memória exaurida.\n");
                return palavras;
            }
            palavras = tmp;
            memset (palavras + maxlen, 0, maxlen * sizeof *palavras);
            maxlen *= 2;
        }
    }

    return palavras;
}


/*
    Recebe um array de strings, concatena essas strings em um buffer
    e faz uma cópia na string destino
*/
void agrupaFrases(char **frases, int nFrases, char *stringDestino)
{
    char buffer[comprimentoDaLista] = "";

    for (int i = 0; i < nFrases; i++)
    {
        strcat(buffer, frases[i]);
    }
    strcpy(stringDestino, buffer);    
}


/*
    Recebe uma string com texto e a divide em palavras
    As palavras são salvas em um array passado como parâmetro
    Retorna a quantidade de palavras
*/
int tokenizaTexto(char *texto, char **destino)
{
    const char separadores[8] = " ,:!?.\n";
    char *token = strtok(texto, separadores);
    
    
    size_t nPalavras = 0;
    while(token != NULL) {
        destino[nPalavras++] = token;
        token = strtok(NULL, separadores);
    }

    return nPalavras;
}