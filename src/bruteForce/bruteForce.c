#include "bruteForce.h"

// A partir de um arquivo que o usuário fornece, lê e interpreta o seu texto para ter seu texto buscado
void loadTextFromFile(char *text){
    char fileName[FILE_BUFFER_SIZE];
    char currentLine[FILE_BUFFER_SIZE];
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

// Realiza a busca de padrão exato utilizando Força Bruta. Ao fim da execução, imprime as ocorrências
void bruteForceSearch(char *text, int analysisMode) {
    char search[100];
    cprintf(BLUE, "Digite a palavra : \n");
    prePrompt();
    scanf("%s", search);

    int textSize = strlen(text);
    int searchSize = strlen(search);
    int foundWordArray[64];
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
    printOcorrences(foundWordArray, occurrences, searchSize, text);
}
