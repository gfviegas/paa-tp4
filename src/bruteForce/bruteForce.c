#include "bruteForce.h"

// Realiza a busca de padrão exato utilizando Força Bruta. Ao fim da execução, imprime as ocorrências
void bruteForceSearch(char *text, int analysisMode) {
    char search[100];
    cprintf(BLUE, "Digite a palavra buscada (máx 100 caracteres): \n");
    prePrompt();
    scanf("%s", search);

    int textSize = strlen(text);
    int searchSize = strlen(search);
    int foundWordArray[BFORCE_MAX_OCCURRENCES];
	int occurrences = 0;

	clock_t startTime;
	if (analysisMode) startTime = beginBenchmark();

    for (int i = 0; i <= (textSize - searchSize + 1); i++) {
    	int k = i;
        int j = 1;

        while (text[k - 1] == search[j - 1] && j <= searchSize) {
            j++;
            k++;
        }

        if (j > searchSize) {
            foundWordArray[occurrences] = i - 1;
            occurrences++;
        }
    }

	if (analysisMode) finishBenchmark(startTime, MICROSECONDS);
    printOccurrences(foundWordArray, occurrences, searchSize, text);
}
