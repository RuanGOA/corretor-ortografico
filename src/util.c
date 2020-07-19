#include "util.h"
#include "constantes.h"

void liberaArray (char **words, int rows){

    int i;
    for (i = 0; i < rows; i++){
        free(words[i]);
    }
    free(words);
}


/*
 * Retorna um coeficiente da semelhança de palavras usando o algoritmo
 * "distancia de Levenshtein", e fazendo calculo de porcentagem.
 */
float levenshtein(char *palavra1, char *palavra2) {

  const int tamanho_palavra1 = strlen(palavra1), tamanho_palavra2 = strlen(palavra2);

  float ldist = levenshteinDist(palavra1, tamanho_palavra1, palavra2, tamanho_palavra2);

  float lcoeff = ((tamanho_palavra1 + tamanho_palavra2) - ldist)/(tamanho_palavra1 + tamanho_palavra2);

  return lcoeff;
}


/*
 * Função auxiliar que retorna um numero inteiro resultante da distancia de levenshtein.
 */
int levenshteinDist(char *s1, int s1len, char *s2, int s2len) {
	int x, y, lastdiag, olddiag;

    unsigned int column[s1len+1];

    for (y = 1; y <= s1len; y++){
        column[y] = y;
	}

    for (x = 1; x <= s2len; x++) {
        column[0] = x;

        for (y = 1, lastdiag = x-1; y <= s1len; y++) {
            olddiag = column[y];
            column[y] = MIN3(column[y] + 1, column[y-1] + 1, lastdiag + (s1[y-1] == s2[x-1] ? 0 : 1));

            lastdiag = olddiag;
        }
    }

    return(column[s1len]);
}
