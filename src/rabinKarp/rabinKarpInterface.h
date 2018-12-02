/**
 * Gerencia e chama as funções relacionadas ao casamento de palavras através do
 * Rabin-Karp, imprimindo e lendo os dados necessários
 *
 * Gustavo Viegas (3026) e Heitor Passeado (3055)
 * @author Gustavo Viegas
 */

#ifndef rabinKarpInterface_h
#define rabinKarpInterface_h

#include <stdio.h>

#include "../util/interface.h"
#include "../util/logger.h"
#include "rabinKarp.h"

#define WORD_MAX_LENGTH 250

/**
 * Tela inicial da busca de padrão com Rabin-Karp
 * @param analysisMode Flag se está no modo análise (1) ou não (0)
 */
void _rabinKarpInitial(int analysisMode);

/**
 * Exibe o menu para fazer busca com Rabin-Karp
 * @param analysisMode Flag se está no modo análise (1) ou não (0)
 */
void _rabinKarpMenu(int analysisMode, char *text);

#endif /* rabinKarpInterface_h */
