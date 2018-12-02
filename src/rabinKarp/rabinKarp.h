/**
 * Gerencia e chama as funções relacionadas ao casamento com Rabin-Karp
 * manipulando estruturas de dados, utilizando estratégias estudadas.
 *
 * Gustavo Viegas (3026) e Heitor Passeado (3055)
 * @author Gustavo Viegas
 */

#ifndef rabinKarp_h
#define rabinKarp_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../util/fileReader.h"
#include "../util/logger.h"
#include "../util/interface.h"
#include "../util/benchmark.h"

// Quantidade de caracteres do alfabeto
#define ALPHABET_SIZE 			256
// Um número primo qualquer pra ser fator de hashing
#define PRIME_NUMBER 			101
// Máximo de ocorrencias que podemos achar com rabinKarp nesse programa
#define RKARP_MAX_OCCURRENCES 	300

/**
 * Calcula a hash de um número baseado no tamanho do alfabeto e no número primo de referência
 * @param  number Número a ter sua hash calculada
 * @return        Valor hash calculado
 */
int calculateHash(int number);

/**
 * Realiza a busca de padrão exato utilizando Rabin-Karp. Ao fim da execução, imprime as ocorrências
 * @param text         String com o texto a ser buscado
 * @param analysisMode Flag se está (1) ou não (0) no modo de análise
 */
void rabinKarpSearch(char *text, int analysisMode);

#endif
