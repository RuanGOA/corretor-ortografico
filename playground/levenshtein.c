#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

/*
 * Retorna um coeficiente da semelhança de palavras usando o algoritmo
 * "distancia de Levenshtein", e fazendo calculo de porcentagem.
 */
float levenshtein(const char *palavra1, const char *palavra2) {

  const int tamanho_palavra1 = strlen(palavra1), tamanho_palavra2 = strlen(palavra2);

  float ldist = levenshteinDist(palavra1, tamanho_palavra1, palavra2, tamanho_palavra2);

  float lcoeff = ((tamanho_palavra1 + tamanho_palavra2) - ldist)/(tamanho_palavra1 + tamanho_palavra2);

  return lcoeff;
}

/*
 * Função auxiliar que retorna um numero inteiro resultante da distancia de levenshtein.
 */
int levenshteinDist(const char *s, const int ls, const char *t, const int lt) {

	int d[ls + 1][lt + 1];
 
	for (int i = 0; i <= ls; i++)
		for (int j = 0; j <= lt; j++)
			d[i][j] = -1;
 
	int dist(int i, int j) {
		if (d[i][j] >= 0) return d[i][j];
 
		int x;
		if (i == ls)
			x = lt - j;
		else if (j == lt)
			x = ls - i;
		else if (s[i] == t[j])
			x = dist(i + 1, j + 1);
		else {
			x = dist(i + 1, j + 1);
 
			int y;
			if ((y = dist(i, j + 1)) < x) x = y;
			if ((y = dist(i + 1, j)) < x) x = y;
			x++;
		}
		return d[i][j] = x;
	}
	return dist(0, 0);
}


//////////////////
// TESTE
//////////////////
int main(void) {
	char word1[10];
	scanf("%s", word1);
	char word2[10];
	scanf("%s", word2);

	double res = levenshtein(word1, word2);

	printf("%f \n", res);
}
