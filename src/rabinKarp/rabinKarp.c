/**
 * Gerencia e chama as funções relacionadas ao casamento com Rabin-Karp
 * manipulando estruturas de dados, utilizando estratégias estudadas.
 *
 * Gustavo Viegas (3026) e Heitor Passeado (3055)
 * @author Gustavo Viegas
 */

#include "rabinKarp.h"

// Calcula a hash de um número baseado no tamanho do alfabeto e no número primo de referência
int calculateHash(int number) {
	return number % PRIME_NUMBER;
}

// Realiza a busca de padrão exato utilizando Rabin-Karp. Ao fim da execução, imprime as ocorrências
void rabinKarpSearch(char *text, int analysisMode) {
	char pattern[100];
	cprintf(BLUE, "Digite a palavra buscada (máx 100 caracteres): \n");
    prePrompt();
    scanf("%s", pattern);

	int foundWordArray[RKARP_MAX_OCCURRENCES];
	int occurrences = 0;
	int textLength = strlen(text);
	int patternLength = strlen(pattern);
	int i, j;
	int patternHash = 0;
	int textHash = 0;
	int hashFactor = 1;

	clock_t startTime;
	if (analysisMode) startTime = beginBenchmark();

	// hashFactor = ALPHABET_SIZE^(m-1). Não usamos a math.pow porque tava dando erros de compilação.
	for (i = 0; i < patternLength - 1; i++)
		hashFactor = calculateHash(ALPHABET_SIZE * hashFactor);

	// Calcula o hash do padrão e da primeira janela de ocorrência
	for (i = 0; i < patternLength; i++) {
		patternHash = calculateHash(ALPHABET_SIZE * patternHash + pattern[i]);
		textHash = calculateHash(ALPHABET_SIZE * textHash + text[i]);
	}

	// Percorre o texto com o padrão, caracter por caracter
	for (i = 0; i <= textLength - patternLength; i++) {
		// Verifica os valores hash da janela atual do texto e do padrão. Se o hash bater, então só verifica os caracteres um por um.
		if ( patternHash == textHash ) {
			// Verifica os caracteres.
			for (j = 0; j < patternLength; j++) {
				if (text[i + j] != pattern[j]) break;
			}

			// Se achou todos caracteres, quer dizer que achamos!
			if (j == patternLength) {
				foundWordArray[occurrences] = i;
				occurrences++;
			}
		}

		// Calcula o hash pra próxima janela do texto
		if (i < textLength - patternLength) {
			textHash = calculateHash(ALPHABET_SIZE * (textHash - text[i] * hashFactor) + text[i + patternLength]);

			// Se pegarmos algum valor negativo, convertemos ele pra positivo adicionando o numero primo que usamos pra calcular a hash.
			if (textHash < 0) textHash = (textHash + PRIME_NUMBER);
		}
	}

	if (analysisMode) finishBenchmark(startTime, MICROSECONDS);
	printOccurrences(foundWordArray, occurrences, patternLength, text);
}
