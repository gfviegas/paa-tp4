#include "bruteForceInterface.h"
#include "bruteForce.h"

void _bruteForceInitial(int analysisMode) {
    char text[10000] = "";
    system("clear");
    cprintf(GREEN,"[MODO FORÇA BRUTA]");
    loadTextFromFile(text);
    _bruteForceMenu(analysisMode, text);
}

void _bruteForceMenu(int analysisMode, char *text) {
    int choice;

    system("clear");
    printLine();

    printf("\n\n");
    cprintf(GREEN, "1 - Buscar palavra\n");
    cprintf(GREEN, "2 - Carregar outro arquivo\n");
    cprintf(GREEN, "3 - Voltar ao menu\n");

    prePrompt();
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            bruteForceSearch(text);
            break;
        case 2:
            return _bruteForceInitial(analysisMode);
            break;
        case 3:
            return printHeader(analysisMode);
            break;
        default:
            cprintf(RED, "Opção inválida!\n");
            pressEnterToContinue();
            break;
    }
    return _bruteForceMenu (analysisMode, text);
}
