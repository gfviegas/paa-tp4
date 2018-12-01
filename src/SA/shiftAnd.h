/**
 * Gerencia e chama as funções relacionadas ao casamento com Shift-And
 * manipulando estruturas de dados, utilizando estratégias estudadas.
 *
 * Gustavo Viegas (3026) e Heitor Passeado (3055)
 * @author Gustavo Viegas
 */

 #ifndef shiftAnd_h
 #define shiftAnd_h

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

#include "../util/fileReader.h"
#include "../util/logger.h"

void shiftAndInitFile(char *text);

void shiftAndSearch(char *text);

void shiftAndPrintOcorrences(int *foundWordArray, int numberOfOccurrences, int searchSize, char *text);

#endif
