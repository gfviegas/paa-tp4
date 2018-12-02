/**
 * Gerencia e chama as funções relacionadas ao casamento de palavras através do
 * Shift-And, imprimindo e lendo os dados necessários
 *
 * Gustavo Viegas (3026) e Heitor Passeado (3055)
 * @author Gustavo Viegas
 */

#ifndef rabinKarpInterface_h
#define rabinKarpInterface_h

#define WORD_MAX_LENGTH 250

#include <stdio.h>

#include "../util/interface.h"
#include "../util/logger.h"
#include "rabinKarp.h"


void _rabinKarpInitial(int analysisMode);

void _rabinKarpMenu(int analysisMode, char *text);


#endif /* rabinKarpInterface_h */
