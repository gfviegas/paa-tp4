/**
 * Gerencia e chama as funções relacionadas ao casamento de palavras através da
 * força bruta, imprimindo e lendo os dados necessários
 *
 * Gustavo Viegas (3026) e Heitor Passeado (3055)
 * @author Heitor Passeado
 */

#ifndef bruteForceInterface_h
#define bruteForceInterface_h

#define WORD_MAX_LENGTH 250

#include <stdio.h>

#include "../util/interface.h"
#include "../util/logger.h"
#include "../util/fileReader.h"
#include "bruteForce.h"

/**
 * Tela inicial da busca de padrão com força bruta
 * @param analysisMode Flag se está no modo análise (1) ou não (0)
 */
void _bruteForceInitial(int analysisMode);

/**
 * Exibe o menu para fazer busca com força bruta
 * @param analysisMode Flag se está no modo análise (1) ou não (0)
 */
void _bruteForceMenu(int analysisMode, char *text);

#endif /* bruteForceInterface_h */
