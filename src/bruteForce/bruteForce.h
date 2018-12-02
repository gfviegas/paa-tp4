/**
 * Gerencia e chama as funções relacionadas ao casamento com Força Bruta
 * manipulando estruturas de dados, utilizando estratégias estudadas.
 *
 * Gustavo Viegas (3026) e Heitor Passeado (3055)
 * @author Gustavo Viegas
 */

#ifndef bruteForce_h
#define bruteForce_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../util/fileReader.h"
#include "../util/logger.h"
#include "../util/interface.h"
#include "../util/benchmark.h"

// Máximo de ocorrencias que podemos achar com forca bruta nesse programa
#define BFORCE_MAX_OCCURRENCES 	150

/**
 * Realiza a busca de padrão exato utilizando Força Bruta. Ao fim da execução, imprime as ocorrências
 * @param text         String com o texto a ser buscado
 * @param analysisMode Flag se está (1) ou não (0) no modo de análise
 */
void bruteForceSearch(char *text, int analysisMode);

#endif
