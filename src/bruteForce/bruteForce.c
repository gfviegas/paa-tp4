#include "bruteForce.h"

void loadTextFromFile(char *text){
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

void bruteForceSearch(char *text){
    char search[100];
    cprintf(BLUE, "Digite a palavra : \n");
    prePrompt();
    scanf("%s", search);
    int textSize = strlen(text);
    int searchSize = strlen(search);
    int i, j, k;
    int foundWordArray[64], Occurrences = 0;

    for(i = 0; i<= (textSize - searchSize + 1); i++){
        k = i;
        j = 1;
        while(text[k-1] == search[j-1] && j <= searchSize) {
            j++;
            k++;
        }
        if( j > searchSize ) {
            foundWordArray[Occurrences] = i - 1;
            Occurrences++;
        }
    }
    printLine();
    cprintf(CYAN, "Texto com as ocorrências em destaque: ");
    printOcorrences(foundWordArray, Occurrences, searchSize, text);
    pressEnterToContinue();
}
