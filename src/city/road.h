/**
 * Gerencia e chama as funções relacionadas ao problema de "Obras na Estrada"
 * manipulando estruturas de dados, utilizando de Programação Dinâmica
 *
 * Gustavo Viegas (3026) e Heitor Passeado (3055)
 * @author Gustavo Viegas
 */

#ifndef road_h
#define road_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../util/boolean.h"
#include "../util/fileReader.h"
#include "../util/matrix.h"
#include "../util/logger.h"
#include "../util/benchmark.h"
#include "construction.h"
#include "direction.h"

/**
 * Converte uma coordenada X para o seu índice na matriz
 * @param  x Coordenada X a ter seu valor convertido
 * @return   Índice da posição da matriz onde X está representado
 */
int XtoArrayIndex(int x);

/**
 * Converte uma coordenada Y para o seu índice na matriz
 * @param  y 			Coordenada Y a ter seu valor convertido
 * @param  linesAmount 	Quantidade de linhas da matriz
 * @return   			Índice da posição da matriz onde Y está representado
 */
int YtoArrayIndex(int y, int linesAmount);

/**
 * Converte um índice da matriz onde X está representado para sua coordenada X
 * @param  j Índice da matriz onde X está representado
 * @return   Valor referente a coordenada X
 */
int arrayIndexToX(int j);

/**
 * Converte um índice da matriz onde Y está representado para sua coordenada Y
 * @param  i           Índice da matriz onde Y está representado
 * @param  linesAmount Quantidade de linhas da matriz
 * @return             Valor referente a coordenada Y
 */
int arrayIndexToY(int i, int linesAmount);

/**
* A partir de um arquivo de descrição do problema que o usuário fornece, cria e preenche a matriz com seus dados
* @param matrix        Ponteiro para a matriz de inteiros a ser criada
* @param linesAmount   Ponteiro da quantidade de linhas da matriz
* @param columnsAmount Ponteiro da quantidade de colunas da matriz
*/
void loadRoadMatrix(int ***matrix, int *linesAmount, int *columnsAmount, CoordinatesPointer origin, CoordinatesPointer destination, ConstructionPointer *constructionsList);

/**
 * Resolve o problema das obras na cidade a partir dos dados fornecidos
 * @param  matrix            Ponteiro para a matriz de inteiros representando o problema
 * @param  linesAmount       Quantidade de linhas da matriz
 * @param  columnsAmount     Quantidade de colunas da matriz
 * @param  origin            Coordenadas da origem do trajeto
 * @param  destination       Coordenadas do destino do trajeto
 * @param  constructionsList Lista de construções na cidade
 * @param  analysisMode      Flag se está no modo análise ou não
 * @return                   Valor booleano indicando se o problema tem ou não solução
 */
boolean solve(int ***matrix, int linesAmount, int columnsAmount, CoordinatesPointer origin, CoordinatesPointer destination, ConstructionPointer constructionsList, int analysisMode);

/**
 * Imprime um caminho válido depois de resolvido o problema de obras na cidade
 * @param matrix            Ponteiro para a matriz de inteiros representando o resultado do problema
 * @param linesAmount       Quantidade de linhas da matriz
 * @param columnsAmount     Quantidade de colunas da matriz
 * @param origin            Coordenadas da origem do trajeto
 * @param destination       Coordenadas do destino do trajeto
 * @param constructionsList Lista de construções na cidade
 */
void printSolutionPath(int ***matrix, int linesAmount, int columnsAmount, CoordinatesPointer origin, CoordinatesPointer destination, ConstructionPointer constructionsList);

/**
 * Imprime uma representação da cidade, mostrando suas obras e quantidade de caminhos possíveis até o destino a partir de cada posição
 * @param matrix            Ponteiro para a matriz de inteiros representando o resultado do problema
 * @param linesAmount       Quantidade de linhas da matriz
 * @param columnsAmount     Quantidade de colunas da matriz
 * @param header            Cabeçalho para imprimir a matriz
 * @param constructionsList Lista de construções na cidade
 * @param printPath         Flag indicando se é para imprimir um trajeto, mudando os inteiros para setas de direção, ou não
 * @param origin            Coordenadas da origem do trajeto
 */
void printCity(int ***matrix, int linesAmount, int columnsAmount, char* header, ConstructionPointer constructionsList, boolean printPath, CoordinatesPointer origin);
#endif /* road_h */
