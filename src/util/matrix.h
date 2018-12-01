/**
 * Utilitário para criar, preencher e manipular matrizes
 *
 * Gustavo Viegas (3026) e Heitor Passeado (3055)
 * @author Gustavo Viegas
 */

#ifndef matrix_h
#define matrix_h

#include <stdlib.h>
#include <string.h>

#include "logger.h"

/**
 * Aloca a memória para uma matriz de de inteiros tamanho linesAmount x columnsAmount
 * @param  linesAmount   Quantidade de linhas da matriz
 * @param  columnsAmount Quantidade de colunas da matriz
 * @return Ponteiro para a matriz alocada
 */
int** createIntMatrix(int linesAmount, int columnsAmount);

/**
* Percorre uma matriz, preenchendo toda posição dela com um valor
* @param matrix        Ponteiro para a matriz de inteiros a ser preenchida
* @param linesAmount   Quantidade de linhas da matriz
* @param columnsAmount Quantidade de colunas da matriz
* @param value         Valor para preencher toda a matriz
*/
void fillIntMatrix(int ***matrix, int linesAmount, int columnsAmount, int value);

/**
 * Imprime uma linha com o tamanho da matriz, para fazer uma borda, quebrando ou não linhas antes e depois
 * @param size        Tamanho da linha
 * @param brBefore    Se é para quebrar a linha antes
 * @param brAfter     Se é pra quebrar a linha depois
 * @param borderColor Cor da borda
 */
void printMatrixLine(int size, int brBefore, int brAfter, AvailableColors borderColor);

/**
* Imprime uma matriz entre uma bonita borda
* @param matrix        Ponteiro para a matriz de inteiros a ser impressa
* @param linesAmount   Quantidade de linhas da matriz
* @param columnsAmount Quantidade de colunas da matriz
* @param header        Mensagem a ser impressa no cabeçalho da borda
* @param borderColor   Cor da borda
* @param valueColor    Cor dos valores
*/
void printIntMatrix(int ***matrix, int linesAmount, int columnsAmount, char* header, AvailableColors borderColor, AvailableColors valueColor);

#endif
