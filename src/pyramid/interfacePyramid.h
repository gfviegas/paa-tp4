#ifndef interfacePyramid_h
#define interfacePyramid_h

#define WORD_MAX_LENGTH 250

#include <stdio.h>

#include "../util/interface.h"
#include "../util/logger.h"
#include "pyramid.h"


/**
 * Menu depois que a matriz foi carregada
 * @param analysisMode 1 Se esta em modo análise, 0 caso contrário
 * @param matrix       Matriz com a pirâmide carregada
 * @param size         Tamanho da matriz
 */
void _pyramidMenu(int analysisMode, int ***matrix, int size);
/**
 * Exibe o menu para carregar um Arquivo
 * @param analysisMode  1 Se esta em modo análise, 0 caso contrário
 */
void _pyramidInitial(int analysisMode);
#endif /* interfacePyramid_h */
