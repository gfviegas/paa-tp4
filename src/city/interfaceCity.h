/**
 * Gerencia e chama as funções relacionadas ao problema de obras na ciade,
 * imprimindo e lendo os dados necessários
 *
 * Gustavo Viegas (3026) e Heitor Passeado (3055)dd
 * @author Gustavo Viegas
 */

#ifndef interfaceCity_h
#define interfaceCity_h

#define WORD_MAX_LENGTH 250

#include <stdio.h>

#include "../util/interface.h"
#include "../util/logger.h"
#include "direction.h"
#include "construction.h"
#include "road.h"

/**
 * Imprime as opções do programa e solicita o usuário a funcionalidade desejada
 * @param matrix            Matriz que representa o problema da cidade
 * @param linesAmount       Quantidade de linhas da matriz
 * @param columnsAmount     Quantidade de colunas da matriz
 * @param origin            Coordenadas da origem do trajeto
 * @param destination       Coordenadas do destino do trajeto
 * @param constructionsList Lista de construções da cidade
 * @param analysisMode      Flag se está no modo análise (1) ou não (0)
 */
void _promptAction(int **matrix, int *linesAmount, int *columnsAmount, CoordinatesPointer origin, CoordinatesPointer destination, ConstructionPointer constructionsList, int analysisMode);

/**
 * Exibe o menu para resolver o problema da cidade
 * @param analysisMode Flag se está no modo análise (1) ou não (0)
 */
void _cityMenu(int analysisMode);

#endif /* interfaceCity_h */
