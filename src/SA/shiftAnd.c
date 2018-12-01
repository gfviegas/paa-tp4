#include "shiftAnd.h"

void shiftAndInitFile(char *text){
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

void shiftAndSearch(char *text){
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
    shiftAndPrintOcorrences(foundWordArray, Occurrences, searchSize, text);
    pressEnterToContinue();
}

void shiftAndPrintOcorrences(int *foundWordArray, int numberOfOccurrences, int searchSize, char *text){
    printLine();
    int textSize = strlen(text);
    int i, j, k;
    for(i = 0; i < textSize; i++){
        for(j = 0; j < numberOfOccurrences; j++){
            if(foundWordArray[j] == i) {
                for(k = i; k < searchSize + i; k++){
                    cprintf(BLUE, "%c", text[k]);
                }
                i += searchSize;
            }
        }
        printf("%c", text[i]);
    }
}
