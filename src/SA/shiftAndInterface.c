/**
 * Gerencia e chama as funções relacionadas ao casamento de palavras através do
 * Shift-And, imprimindo e lendo os dados necessários
 *
 * Gustavo Viegas (3026) e Heitor Passeado (3055)
 * @author Gustavo Viegas
 */

#include "shiftAndInterface.h"
#include "shiftAnd.h"

void _shiftAndInitial(int analysisMode) {
    char text[10000] = "";
    system("clear");
    cprintf(GREEN,"[MODO SHIFT AND]");
    loadTextFromFile(text);
    _shiftAndMenu(analysisMode, text);
}

void _shiftAndMenu(int analysisMode, char *text) {
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
            shiftAndSearch(text);
            break;
        case 2:
            return _shiftAndInitial(analysisMode);
        case 3:
            return printHeader(analysisMode);
        default:
            cprintf(RED, "Opção inválida!\n");
            pressEnterToContinue();
            break;
    }
    return _shiftAndMenu (analysisMode, text);
}
