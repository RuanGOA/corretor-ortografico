#include "funcoes.h"

#define NAO_ENCONTRADO -1
#define ENCONTRADO 1


void pegaTexto(FILE *arquivo, int *nPalavras, char **destino)
{
    char palavrasDoTexto[comprimentoDasPalavras];
    int i = 0;
    
    while (fscanf(arquivo, "%s", palavrasDoTexto) != EOF){
        destino[i++] = palavrasDoTexto;
        printf("dest: %s | palavr: %s \n", destino[i-1], palavrasDoTexto);
    }

    *nPalavras = i;
}


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
        
        //if (buf[wordlen - 1] == '\n')  
         //   buf[--wordlen] = '\x20';
        
       
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

/*
	Compara um array de palavras com as palavras de um dicionário.
	Retorna um array com 0 na mesma posição de palavras que não foram
	encontradas no dicionário e 1 para para as palavras encontradas
*/
void buscaNoDicionario(char **palavras, int nPalavras , char **dicionario, int tamanhoDicionario, int *resultado)
{
    int inicio = 0;
	int *resultadoDasBuscas;

	//implementar busca binária
	//strcmp(str1,str2)  1 para str1 > str2 | -1 para str1 < str2z
    
	for(size_t i = 0; i < nPalavras; ++i)
	{  
        printf("pal: %s, dic: %s, tamD: %d \n", *(palavras + i), *dicionario, tamanhoDicionario);

		if(buscaBinariaString(*(palavras + i), dicionario, inicio, tamanhoDicionario) == NAO_ENCONTRADO)
		{
			resultadoDasBuscas[i] = ENCONTRADO;
		} 
	}

}

int buscaBinariaString(char *palavra, char **dicionario, int inicioDicionario, int fimDicionario)
{
	int metadeDoDicionario =  (fimDicionario/2) ;
    int resultado = -1;

    printf("iniDic: %d | metDict: %d | fimDict: %d \n", inicioDicionario, metadeDoDicionario, fimDicionario);
    printf("palavra: %s , dict: %s , comp: %d \n \n", palavra, dicionario[metadeDoDicionario], strcmp(palavra, dicionario[metadeDoDicionario]));

    if(strcmp(palavra, dicionario[metadeDoDicionario]) < 0)
    {
        resultado =  buscaBinariaString(palavra, dicionario, inicioDicionario,  metadeDoDicionario - 1);
        return resultado;
    }


    if(strcmp(palavra, dicionario[metadeDoDicionario]) > 0)
	{
		resultado = buscaBinariaString(palavra, dicionario,  metadeDoDicionario + 1, fimDicionario);
        return resultado;
	}
    

	if(strcmp(palavra, dicionario[metadeDoDicionario]) == 0)
	{
		return metadeDoDicionario;
	}

	return resultado;
}



