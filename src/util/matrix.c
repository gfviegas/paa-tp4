/**
 * Utilitário para criar, preencher e manipular matrizes
 *
 * Gustavo Viegas (3026) e Heitor Passeado (3055)
 * @author Gustavo Viegas
 */

#include "matrix.h"

// Aloca a memória para uma matriz de inteiros de tamanho linesAmount x columnsAmount
int** createIntMatrix(int linesAmount, int columnsAmount) {
    int **matrix = (int **) malloc(linesAmount * sizeof(int *));

    for (int i = 0; i < linesAmount; i++)
        matrix[i] = (int *) malloc(columnsAmount * sizeof(int));

	return matrix;
}

// Percorre uma matriz, preenchendo toda posição dela com um valor
void fillIntMatrix(int ***matrix, int linesAmount, int columnsAmount, int value) {
    for (int i = 0; i < linesAmount; i++)
        for (int j = 0; j < columnsAmount; j++)
            (*matrix)[i][j] = value;
}

// Imprime uma linha com o tamanho da matriz, para fazer uma borda, quebrando ou não linhas antes e depois
void printMatrixLine(int size, int brBefore, int brAfter, AvailableColors borderColor) {
    if (brBefore) printf("\n");
    for (int i = 0; i <= size + 1; i++)
        cprintf(borderColor, "---");
    if (brAfter) printf("\n");
}

// Imprime uma matriz entre uma bonita borda
void printIntMatrix(int ***matrix, int linesAmount, int columnsAmount, char* header, AvailableColors borderColor, AvailableColors valueColor) {
	int precision = ((columnsAmount * 1.5) + 2) + ((int) strlen(header) / 2);

	printMatrixLine(columnsAmount, 1, 1, BLUE);
	cprintf(MAGENTA, "%*s", precision, header);
	printMatrixLine(columnsAmount, 1, 1, BLUE);

	for (int i = 0; i < linesAmount; i++) {
		cprintf(borderColor, " | ");
		for (int j = 0; j < columnsAmount; j++)
			cprintf(valueColor, " %d ", (*matrix)[i][j]);
		cprintf(borderColor, " |\n");
	}

	printMatrixLine(columnsAmount, 0 , 1, BLUE);
}
