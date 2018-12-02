/**
 * Gerencia e chama as funções relacionadas ao casamento de palavras através do
 * Shift-And, imprimindo e lendo os dados necessários
 *
 * Gustavo Viegas (3026) e Heitor Passeado (3055)
 * @author Gustavo Viegas
 */

#include "rabinKarpInterface.h"
#include "rabinKarp.h"

void _rabinKarpInitial(int analysisMode) {
    char text[10000] = "";
    system("clear");
    cprintf(GREEN,"[MODO RABIN-KARP]");
    loadTextFromFile(text);
    _rabinKarpMenu(analysisMode, text);
}

void _rabinKarpMenu(int analysisMode, char *text) {
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
            rabinKarpSearch(text);
            break;
        case 2:
            return _rabinKarpInitial(analysisMode);
        case 3:
            return printHeader(analysisMode);
        default:
            cprintf(RED, "Opção inválida!\n");
            pressEnterToContinue();
            break;
    }
    return _rabinKarpMenu (analysisMode, text);
}
