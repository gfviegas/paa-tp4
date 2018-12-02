/**
 * Gerencia e chama as funções relacionadas ao casamento de palavras através da
 * força bruta, imprimindo e lendo os dados necessários
 *
 * Gustavo Viegas (3026) e Heitor Passeado (3055)
 * @author Heitor Passeado
 */

#include "bruteForceInterface.h"

// Tela inicial da busca de padrão com força bruta
void _bruteForceInitial(int analysisMode) {
    char text[FILE_MAX_SIZE] = "";
    system("clear");
    cprintf(GREEN,"[MODO FORÇA BRUTA]");
    parseFileInString(text);
    _bruteForceMenu(analysisMode, text);
}

// Exibe o menu para fazer busca com força bruta
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
            bruteForceSearch(text, analysisMode);
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
