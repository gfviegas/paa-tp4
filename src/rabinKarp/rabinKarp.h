/**
 * Gerencia e chama as funções relacionadas ao casamento com Shift-And
 * manipulando estruturas de dados, utilizando estratégias estudadas.
 *
 * Gustavo Viegas (3026) e Heitor Passeado (3055)
 * @author Gustavo Viegas
 */

#ifndef rabinKarp_h
#define rabinKarp_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../util/fileReader.h"
#include "../util/logger.h"
#include "../util/interface.h"

#define ALPHABET_SIZE 	256
#define PRIME_NUMBER 	101

void rabinKarpInitFile(char *text);

void rabinKarpSearch(char *text);

#endif
