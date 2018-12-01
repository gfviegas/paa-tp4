#include "pyramid.h"
#include "string.h"
void loadPyramidMatrix(int ***matrix, int *size) {
    char fileName [FILE_BUFFER_SIZE];
    char currentLine [FILE_BUFFER_SIZE];
    int i=0,j=0;
    (*size) = 0;
    FILE *file = NULL;
    if (*matrix != NULL) free(*matrix);

    cprintf(BLUE,"[CAMINHO] (Exemplo: resources/pyramid/pyramid.txt)");
    promptFilePath(fileName);
    openFile(&file, fileName);

    while (readLine(file, currentLine)) {
        (*size)++;
    }
    fclose(file);
    (*matrix) = createIntMatrix((*size), (*size));
    fillIntMatrix( matrix, (*size), (*size), 0 );

    openFile (&file, fileName);
    while (i < (*size)) {
        for (j = 0; j <= i; j++) {
            (j == i) ? fscanf(file, "%d\n", &(*matrix)[i][j]) : fscanf(file, "%d ", &(*matrix)[i][j]);
        }
        i++;
    }
    cprintf(GREEN, "Arquivo carregado!");
    pressEnterToContinue();
    fclose(file);
}

void solvePyramidRecursive(int ***matrix, int size, int analysisMode) {
	clock_t startTime;
	if (analysisMode) startTime = beginBenchmark();

    Movements path[size];
    int calls = 0, i;
    int result = pyramidRecursive(matrix, size - 1, 0, 0, path, &calls);

    system("clear");
    printIntMatrix(matrix, size, size, "Pirâmide", CYAN, YELLOW);
    cprintf(YELLOW, "O maior caminho encontrado foi --> %d\n", result);
    cprintf(YELLOW, "O caminho foi -->  ");
    for(i=0; i<size-1; i++) {
        cprintf(CYAN, "%s ", getMovementName(path[i]));
    }
    printf("\n");

    if (analysisMode) {
		cprintf(RED, "\t[STATS] Quantidade de chamadas: %d\n", calls);
		finishBenchmark(startTime, MILISECONDS);
    }

    pressEnterToContinue();
}


int pyramidRecursive(int ***matrix, int size, int i, int j, Movements *path, int *calls) {
    (*calls)++;
    int right;
    int result;
    if (i == size) return (*matrix)[i][j];

    result = (*matrix)[i][j] + max(pyramidRecursive(matrix, size, i + 1, j, path, calls), pyramidRecursive(matrix, size, i + 1, j + 1, path, calls), &right);

    if (right) path[i] = RIGHT;
    else path[i] = LEFT;

    return result;
}

void solvePyramidMemoization(int ***matrix, int size, int analysisMode) {
	clock_t startTime;
	if (analysisMode) startTime = beginBenchmark();

    int **memoization;
    memoization = createIntMatrix(size,size);
    fillIntMatrix(&memoization, size, size, 0);

    Movements path[size];
    int calls = 0, i;
    int result = pyramidMemoization(matrix, size - 1, 0, 0, path, &memoization, &calls);

    system("clear");
    printIntMatrix(matrix, size, size, "Pirâmide", CYAN, YELLOW);
    cprintf(YELLOW, "O maior caminho encontrado foi --> %d\n", result);
    cprintf(YELLOW, "O caminho foi -->  ");
    for ( i = 0; i < size-1; i++) {
        cprintf(CYAN, "%s ", getMovementName(path[i]));
    }
    printf("\n");

	if (analysisMode) {
		cprintf(RED, "\t[STATS] Quantidade de chamadas: %d\n", calls);
		finishBenchmark(startTime, MILISECONDS);
    }

    pressEnterToContinue();
}

int pyramidMemoization(int ***matrix, int size, int i, int j, Movements *path, int ***results, int *calls) {
    (*calls)++;
    int right;//determina se o caminho foi p direita ou esquerda
    //Se chegou na base da pirâmide retorna
    if (i == size)  return (*matrix)[i][j];
    //Se possui resultado armazenado retorna
    if ((*results)[i][j] != 0)  return(*results)[i][j];
    //Armazena resultado
    (*results)[i][j] = (*matrix)[i][j] + max(pyramidMemoization(matrix, size, i + 1, j, path, results, calls),//parametro 1
                                             pyramidMemoization(matrix, size, i + 1, j + 1, path, results, calls),//parametro 2
                                             &right);//parametro 3
    //Verifica o caminho tomado
    if (right) path[i] = RIGHT;
    else  path[i] = LEFT;

    return (*results)[i][j];
}

void solvePyramidPD(int ***matrix, int size, int analysisMode) {
	clock_t startTime;
	if (analysisMode) startTime = beginBenchmark();

    int **memoization;
    memoization = createIntMatrix(size,size);
    fillIntMatrix(&memoization, size, size, 0);

    Movements path[size];
    int calls = 0, i;
    int result = pyramidPD(*matrix, size - 1, path, &memoization, &calls);

    system("clear");
    printIntMatrix(matrix, size, size, "Pirâmide Original", CYAN, YELLOW);
    printIntMatrix(&memoization, size, size, "Pirâmide Resultado", CYAN, YELLOW);
    cprintf(YELLOW,"O maior caminho encontrado foi --> %d\n", result);
    cprintf(YELLOW, "O caminho foi -->  ");
    for (i = 0; i < size-1; i++) {
        cprintf(CYAN, "%s ", getMovementName(path[i]));
    }
    printf("\n");

	if (analysisMode) {
		cprintf(RED, "\t[STATS] Quantidade de operações: %d\n", calls);
		finishBenchmark(startTime, MILISECONDS);
    }

    pressEnterToContinue();
}

int pyramidPD(int **matrix, int size, Movements *path, int ***results, int *calls) {
    int i, j, winner;
    for(i = size; i >= 0; i--) {
        for (j = 0; j <= i; j++) {;
            (*calls)++;
            //Se esta na base da piramede
            if ( i == size)
                (*results)[i][j] = matrix[i][j];
            else
                (*results)[i][j] = matrix[i][j] + max((*results)[i+1][j], (*results)[i+1][j+1], &winner);
        }
    }
    j = 0;
    //Verificando o caminho tomado
    for(i = 0; i < size; i++) {
        max((*results)[i+1][j], (*results)[i+1][j+1], &winner);
        if (winner) {
            path[i] = RIGHT;
            j++;
        }
        else {
            path[i] = LEFT;
        }

    }
    return (*results)[0][0];
}

int max(int a, int b, int *winner) {
    if (a > b) {
        (*winner) = 0;
        return a;
    }
    (*winner) = 1;
    return b;
}

const char* getMovementName(Movements move) {
    if (move == LEFT) return "esquerda ";
    return "direita ";
}
