/**
 * Gerencia e chama as funções relacionadas as tarefas, imprimindo e lendo
 * os dados necessários
 *
 * Gustavo Viegas (3026) e Heitor Passeado (3055)
 * @author Heitor Passeado
 */

#ifndef interface_h
#define interface_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "logger.h"
#include "../bruteForce/bruteForceInterface.h"
#include "../rabinKarp/rabinKarpInterface.h"
/**
 * Imprime uma mensagem de aguardando e aguarda a entrada do usuário para continuar a execução do programa
 */
void pressEnterToContinue(void);

/**
 * Imprime uma flag que indica a leitura de um dado do usuário
 */
void prePrompt(void);

/**
* Imprime o cabeçalho do programa
* @param analysisMode Flag se o modo análise está ativo ou não
*/
void printHeader(int analysisMode);

/**
 * Inicializa o programa imprimindo o menu inicial
 * @param analysisMode Flag se o modo análise está ativo ou não
 */
void printMenu(int analysisMode);

void printOcorrences(int *foundWordArray, int numberOfOccurrences, int searchSize, char *text);

#endif
