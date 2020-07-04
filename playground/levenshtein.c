#include <string.h>
#include <stdlib.h>
#include <stdint.h>

/*
 * Retorna o inteiro que representa a diferenca entre uma palavra e, e uma palavra b
 * Veja <https://en.wikipedia.org/wiki/Levenshtein_distance> para mais informações.
 */
size_t levenshteinCalc(const char *a, const size_t aLen, const char *b, const size_t bLen) {
  // otimizações
  if (a == b) {
    return 0;
  }

  if (aLen == 0) {
    return bLen;
  }

  if (bLen == 0) {
    return aLen;
  }

  size_t *cache = calloc(aLen, sizeof(size_t));
  size_t aIndex = 0;
  size_t bIndex = 0;
  size_t aDist;
  size_t bDist;
  size_t res;
  char code;

  // initialize the vector.
  while (aIndex < aLen) {
    cache[aIndex] = aIndex + 1;
    aIndex++;
  }

  // Loop.
  while (bIndex < bLen) {
    code = b[bIndex];
    res = aDist = bIndex++;
    aIndex = SIZE_MAX;

    while (++aIndex < aLen) {
      bDist = code == a[aIndex] ? aDist : aDist + 1;
      aDist = cache[aIndex];

      cache[aIndex] = res = aDist > res ?
				bDist > res ? res + 1 : bDist
        :
				bDist > aDist ? aDist + 1 : bDist;
    }
  }

  free(cache);

  return res;
}

double levenshtein(const char *a, const char *b) {
  const size_t aLen = strlen(a);
  const size_t bLen = strlen(b);
	
	const size_t levenshteinDist = levenshteinCalc(a, aLen, b, bLen);

	float maiorTamanho = max(bLen, aLen);

  return (maiorTamanho - levenshteinDist)/maiorTamanho;
}

int max(int n1, int n2) {
	int res = 0;
	if(n1 > n2) {
		res = n1;
	} else {
		res = n2;
	}

	return res;
}

int main(void) {
	char word1[10];
	scanf("%s", word1);
	char word2[10];
	scanf("%s", word2);

	double res = levenshtein(word1, word2);

	printf("%f \n", res);
}
