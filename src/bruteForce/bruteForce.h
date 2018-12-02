/**
 * Realiza a busca no texto por meio do processo bruteForce
 */
 #ifndef bruteForce_h
 #define bruteForce_h

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

#include "../util/fileReader.h"
#include "../util/logger.h"
#include "../util/interface.h"
#include "../util/benchmark.h"

void loadTextFromFile(char *text);

void bruteForceSearch(char *text, int analysisMode);

#endif
