#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void liberaArray (char **words, int rows);

/*
 * Retorna um coeficiente da semelhança de palavras usando o algoritmo
 * "distancia de Levenshtein", e fazendo calculo de porcentagem.
 */
float levenshtein(char *palavra1, char *palavra2);


/*
 * Função auxiliar que retorna um numero inteiro resultante da distancia de levenshtein.
 */
int levenshteinDist(char *s1, int s1len, char *s2, int s2len);
