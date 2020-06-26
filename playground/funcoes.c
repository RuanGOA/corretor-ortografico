#include "funcoes.h"

/* Usa essa funcao quando for ler o texto*/
char **pegaFrases (FILE *fp, int *n) {

    char **palavras = NULL;
    char buf[comprimentoDasPalavras + 1] = {0};
    int maxlen = comprimentoDaLista > 0 ? comprimentoDaLista : 1;

    if (!(palavras = calloc (maxlen, sizeof *palavras))) {
        fprintf (stderr, "pegaPalavras() erro: memória virtual exaurida.\n");
        return NULL;
    }

    while (fgets (buf, comprimentoDasPalavras + 1, fp)) {

        size_t wordlen = strlen (buf);  
        /*
        if (buf[wordlen - 1] == '\n')  
            buf[--wordlen] = '\x20';
        */
       
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
/* Usa essa funcao quando for ler o dicionário*/
char **pegaPalavras (FILE *fp, int *n) {

    char **palavras = NULL;
    char buf[comprimentoDasPalavras + 1] = {0};
    int maxlen = comprimentoDaLista > 0 ? comprimentoDaLista : 1;

    if (!(palavras = calloc (maxlen, sizeof *palavras))) {
        fprintf (stderr, "pegaPalavras() erro: memória virtual exaurida.\n");
        return NULL;
    }

    while (fgets (buf, comprimentoDasPalavras + 1, fp)) {

        size_t wordlen = strlen (buf);  

        if (buf[wordlen - 1] == '\n')  
            buf[--wordlen] = 0;

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

void liberaArray (char **words, int rows){

    int i;
    for (i = 0; i < rows; i++){
        free (words[i]);
    }
    free(words);
}

/*
    Recebe um array de strings, concatena essas strings em um buffer
    e faz uma cópia na string destino
*/
void agrupaFrases(char **frases, int nFrases, char *stringDestino)
{
    char buffer[comprimentoDaLista] = "";

    for (size_t i = 0; i < nFrases; i++)
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







