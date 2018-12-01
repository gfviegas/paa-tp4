/**
 * Gerencia e chama as funções relacionadas ao casamento de palavras através do
 * Shift-And, imprimindo e lendo os dados necessários
 *
 * Gustavo Viegas (3026) e Heitor Passeado (3055)
 * @author Gustavo Viegas
 */

#ifndef shiftAndInterface_h
#define shiftAndInterface_h

#define WORD_MAX_LENGTH 250

#include <stdio.h>

#include "../util/interface.h"
#include "../util/logger.h"
#include "shiftAnd.h"


void _shiftAndInitial(int analysisMode);

void _shiftAndMenu(int analysisMode, char *text);


#endif /* shiftAndInterface_h */
