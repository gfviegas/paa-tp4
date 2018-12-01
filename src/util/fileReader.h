/**
 * Gerencia e chama as funções relacionadas ao sudoku, imprimindo e lendo
 * os dados necessários
 *
 * Gustavo Viegas (3026) e Heitor Passeado (3055)
 * @author Gustavo Viegas
 */

#ifndef fileReader_h
#define fileReader_h

#include <stdio.h>
#include "logger.h"
#include "interface.h"
#include "string.h"

#define FILE_PATH_BUFFER_SIZE 150
#define FILE_BUFFER_SIZE 255

void promptFilePath(char* filePath);

void openFile(FILE** file, char* filePath);

char* readLine(FILE* file, char* buffer);

#endif /* fileReader_h */
