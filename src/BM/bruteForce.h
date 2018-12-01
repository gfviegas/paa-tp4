/**
 * Realiza a busca no texto por meio do processo BM
 */
 #ifndef bruteForce_h
 #define bruteForce_h

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

#include "../util/fileReader.h"
#include "../util/logger.h"

void loadTextFromFile(char *text);

void bruteForceSearch(char *text);

void printSearchedText(int *foundWordArray, int numberOfOccurrences, int searchSize, char *text);

#endif
