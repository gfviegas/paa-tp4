#include "rabinKarp.h"

void rabinKarpInitFile(char *text) {
    char fileName [FILE_BUFFER_SIZE];
    char currentLine [FILE_BUFFER_SIZE];
    FILE *file = NULL;
    cprintf(BLUE,"[CAMINHO] (Exemplo: resources/textoBase.txt)");
    promptFilePath(fileName);
    openFile(&file, fileName);

    while (readLine(file, currentLine)) {
      strcat(text, currentLine);
    }

    cprintf(CYAN, "Texto carregado! \n\n%s\n", text);
    pressEnterToContinue();
}

void rabinKarpSearch(char *text, int analysisMode) {
	char pattern[100];
	cprintf(BLUE, "Digite a palavra : \n");
    prePrompt();
    scanf("%s", pattern);

	int foundWordArray[64];
	int occurrences = 0;
	int textLength = strlen(text);
	int patternLength = strlen(pattern);
	int i, j;
	int patternHash = 0;
	int textHash = 0;
	int hashFactor = 1;

	clock_t startTime;
	if (analysisMode) startTime = beginBenchmark();

	// hashFactor = ALPHABET_SIZE^(m-1)
	for (i = 0; i < patternLength - 1; i++)
		hashFactor = (hashFactor * ALPHABET_SIZE) % PRIME_NUMBER;

	// Calcula o hash do padrão e da primeira janela de ocorrência
	for (i = 0; i < patternLength; i++) {
		patternHash = (ALPHABET_SIZE * patternHash + pattern[i]) % PRIME_NUMBER;
		textHash = (ALPHABET_SIZE * textHash + text[i]) % PRIME_NUMBER;
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
		if ( i < textLength - patternLength) {
			textHash = (ALPHABET_SIZE * (textHash - text[i] * hashFactor) + text[i + patternLength]) % PRIME_NUMBER;

			// Se pegarmos algum valor negativo, convertemos ele pra positivo adicionando o numero primo que usamos pra calcular a hash.
			if (textHash < 0) textHash = (textHash + PRIME_NUMBER);
		}
	}

	if (analysisMode) finishBenchmark(startTime, MICROSECONDS);
	printOcorrences(foundWordArray, occurrences, patternLength, text);
}
