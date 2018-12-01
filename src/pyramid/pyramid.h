/**
 * Realiza as funções para resolver o problema da pirâmede
 * Gustavo Viegas (3026) e Heitor Passeado (3055)
 * @author Heitor Passeado
 */
 #ifndef pyramid_h
 #define pyramid_h

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 #include "../util/fileReader.h"
 #include "../util/matrix.h"
 #include "../util/logger.h"

typedef enum Movements{
    LEFT,RIGHT
} Movements;

 /**
  * Lê de um arquivo e carrega uma matriz no modelo do problema de pirâmede
  * @param matrix Matriz que armazanará
  * @param size Variável que receberá o tamanho da matriz lida
  */
 void loadPyramidMatrix(int ***matrix, int *size);

 /**
  * Função que encapsula variáveis que são usadas na pyramidRecursive e exibe os resultados
  * @param matrix       Matriz a ser resolvida
  * @param size         Tamanho da matriz
  * @param analysisMode Se está ou não no modo análise
  */
 void solvePyramidRecursive(int ***matrix, int size, int analysisMode);
/**
 * Função que resolve o problema das pirâmides por recursão básica
 * @param  matrix Matriz a ser resolvida
 * @param  size   Tamanho da matriz
 * @param  i      índice das linhas(começa no 0)
 * @param  j      índice das colunas(começa no 0)
 * @param  path   Vetor com os caminhos percorridos: esquerda ou direita
 * @param  calls  Quantas chamadas foram feitas
 * @return        Valor do caminho máximo
 */
 int pyramidRecursive(int ***matrix, int size, int i, int j, Movements *path, int *calls);

 /**
 * Encapsula variáveis da pyramidMemoization e exibe os resultados
 * @param matrix       Matriz a ser resolvida
 * @param size         Tamanho da matriz
 * @param analysisMode Se está ou não no modo análise
 */
 void solvePyramidMemoization(int ***matrix, int size, int analysisMode);

 /**
  * Resolve o problema das pirâmedes com recursão e memoization, exibe os resultados
  * @param  matrix  Matriz que contém os resultados
  * @param  size    Tamanho da matriz
  * @param  i       Índice das linhas(começa com 0)
  * @param  j       Índice das colunas(começa com 0)
  * @param  path    Vetor com as direções tomadas, esquerda ou direita
  * @param  results Matriz que contém os resultados gravados
  * @param  calls   Ponteiro que armazanará quantas chamadas foram feitas
  * @return         Tamanho do caminho máximo
  */
 int pyramidMemoization(int ***matrix, int size, int i, int j, Movements *path, int ***results, int *calls);

 /**
 * Encapsula variáveis da pyramidPD e exibe os resultados
 * @param matrix       Matriz a ser resolvida
 * @param size         Tamanho da matriz
 * @param analysisMode Se está ou não no modo análise
 */
 void solvePyramidPD(int ***matrix, int size, int analysisMode);

 /**
  * Resolve o problema da pirâmede com programação dinânimca de trás pra frente
  * @param  matrix  Matriz que contém a pirâmede
  * @param  size    Tamanho da matriz
  * @param  path    Vetor com as direões tomadas
  * @param  results Matriz que conterá o resultado, utilizando o método de ir de trás p frente
  * @param  calls   Ponteiro que armazanará quantas operações foram feitas
  * @return         Tamanho do caminho máximo
  */
 int pyramidPD(int **matrix, int size, Movements *path, int ***results, int *calls);

 /**
  * Pega o nome do movimento
  * @param  move
  * @return string contendo esquerda ou direita dependendo do move
  */
 const char* getMovementName(Movements move);

 /**
  * Retorna o máximo entre dois números
  * @param  a      Número 1
  * @param  b      Número 2
  * @param  winner Ponteiro que armazena 0 caso o primeiro ganhe e 1 caso contrário
  * @return        Maior entre os 2 números;
  */
 int max(int a, int b, int *winner);

 #endif
