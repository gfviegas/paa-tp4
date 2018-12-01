#include "interfacePyramid.h"


void _pyramidInitial(int analysisMode) {
    int **matrix = NULL;
    int size;
    system("clear");
    cprintf(GREEN,"[MODO PIRÂMIDE]");
    loadPyramidMatrix(&matrix, &size);
    _pyramidMenu(analysisMode, &matrix, size);
}

void _pyramidMenu(int analysisMode, int ***matrix, int size) {
    int choice;


    system("clear");
    printLine();

    printf("\n\n");
    cprintf(GREEN, "1 - Solucionar recursivamente\n");
    cprintf(GREEN, "2 - Solucionar recursivamente com memoization\n");
    cprintf(GREEN, "3 - Solucionar de trás pra frente\n");
    cprintf(GREEN, "4 - Carregar outra pirâmide\n");
    cprintf(GREEN, "5 - Voltar ao menu\n");

    prePrompt();
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            solvePyramidRecursive(matrix, size, analysisMode);
            break;
        case 2:
            solvePyramidMemoization(matrix, size, analysisMode);
            break;
        case 3:
            solvePyramidPD(matrix, size, analysisMode);
            break;
        case 4:
            return _pyramidInitial(analysisMode);
            break;
        case 5:
            return printHeader(analysisMode);
        default:
            cprintf(RED, "Opção inválida!\n");
            pressEnterToContinue();
            break;
    }
    return _pyramidMenu (analysisMode, matrix, size);
}
