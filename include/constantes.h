/*
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
*/

/* Link com todas as cores de texto e background
   https://gist.github.com/RabaDabaDoba/145049536f815903c79944599c6f952a
*/
#define BLUE_BACKGROUND "\e[44m"
#define RED_BACKGROUND "\e[41m"
#define RED_TEXT "\e[0;31m"
#define RESET "\e[0m"
#define QUANT_MAX_PALAVRAS 50

#define comprimentoDaLista 256
#define COMP_MAX_PALAVRA 21
#define QUANT_MAX_CARACTERES 240

#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))
