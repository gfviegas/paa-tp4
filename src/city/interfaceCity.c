/**
 * Gerencia e chama as funções relacionadas ao problema de obras na ciade,
 * imprimindo e lendo os dados necessários
 *
 * Gustavo Viegas (3026) e Heitor Passeado (3055)
 * @author Gustavo Viegas
 */

#include "interfaceCity.h"

// Imprime as opções do programa e solicita o usuário a funcionalidade desejada
void _promptAction(int **matrix, int *linesAmount, int *columnsAmount, CoordinatesPointer origin, CoordinatesPointer destination, ConstructionPointer constructionsList, int analysisMode) {
    int choice;

    system("clear");
    printLine();

    printf("\n\n");
    cprintf(GREEN, "Escolha uma ação: \n\n");
    cprintf(GREEN, "1 - Carregar arquivo\n");
    cprintf(GREEN, "2 - Solucionar\n");
    cprintf(GREEN, "3 - Sair\n");

    prePrompt();
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            loadRoadMatrix(&matrix, linesAmount, columnsAmount, origin, destination, &constructionsList);
            break;
        case 2:
            if (solve(&matrix, *linesAmount, *columnsAmount, origin, destination, constructionsList, analysisMode)) {
				printSolutionPath(&matrix, *linesAmount, *columnsAmount, origin, destination, constructionsList);
			} else {
				cprintf(RED, "Não existe nenhum caminho válido!");
			}
            break;
        case 3:
            return printHeader(analysisMode);
        default:
            cprintf(RED, "Opção inválida!\n");
            break;
    }

	pressEnterToContinue();
    return _promptAction(matrix, linesAmount, columnsAmount, origin, destination, constructionsList, analysisMode);
}

// Exibe o menu para resolver o problema da cidade
void _cityMenu(int analysisMode) {
    int **matrix = NULL;
    int linesAmount, columnsAmount;
	Coordinates origin;
	Coordinates destination;
	ConstructionPointer constructions = NULL;

    _promptAction(matrix, &linesAmount, &columnsAmount, &origin, &destination, constructions, analysisMode);
}
