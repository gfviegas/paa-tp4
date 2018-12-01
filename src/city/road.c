/**
 * Gerencia e chama as funções relacionadas ao problema de "Obras na Estrada"
 * manipulando estruturas de dados, utilizando de Programação Dinâmica
 *
 * Gustavo Viegas (3026) e Heitor Passeado (3055)
 * @author Gustavo Viegas
 */

#include "road.h"

// Converte uma coordenada X para o seu índice na matriz
int XtoArrayIndex(int x) {
	return x - 1;
}

// Converte uma coordenada Y para o seu índice na matriz
int YtoArrayIndex(int y, int linesAmount) {
	return linesAmount - y;
}

// Converte um índice da matriz onde X está representado para sua coordenada X
int arrayIndexToX(int j) {
	return j + 1;
}

// Converte um índice da matriz onde Y está representado para sua coordenada Y
int arrayIndexToY(int i, int linesAmount) {
	return linesAmount - i;
}

// A partir de um arquivo de descrição do problema que o usuário fornece, cria e preenche a matriz com seus dados
void loadRoadMatrix(int ***matrix, int *linesAmount, int *columnsAmount, CoordinatesPointer origin, CoordinatesPointer destination, ConstructionPointer *constructionsList) {
	char currentLine[FILE_BUFFER_SIZE];
    char fileName[FILE_BUFFER_SIZE];
    FILE *file = NULL;

	int x, y;

    if (*matrix != NULL) free(*matrix);

	cprintf(BLUE,"[CAMINHO] (Exemplo: resources/city/city.txt)");
    promptFilePath(fileName);
    openFile(&file, fileName);

    fscanf(file, "%d %d\n", linesAmount, columnsAmount);

	fscanf(file, "%d %d\n", &x, &y);
	origin->x = x;
	origin->y = y;

    fscanf(file, "%d %d\n", &x, &y);
	destination->x = x;
	destination->y = y;

    *matrix = createIntMatrix(*linesAmount, *columnsAmount);
	fillIntMatrix(matrix, *linesAmount, *columnsAmount, 0);
	clearConstructionList(constructionsList);

    while (readLine(file, currentLine)) {
		Coordinates position;
		Direction direction;
		char directionLabel;

		sscanf(currentLine, "%d %d %c", &(position.x), &(position.y), &directionLabel);
		direction = labelToDirection(directionLabel);

		if (direction == NONE) continue;
		addConstruction(constructionsList, position, direction);
    }

	cprintf(BLUE, "[INFO] Arquivo lido com sucesso!\n");
    fclose(file);
}

// Resolve o problema das obras na cidade a partir dos dados fornecidos
boolean solve(int ***matrix, int linesAmount, int columnsAmount, CoordinatesPointer origin, CoordinatesPointer destination, ConstructionPointer constructionsList, int analysisMode) {
	clock_t startTime;
	if (analysisMode) startTime = beginBenchmark();

	cprintf(YELLOW, "[INFO] Origem: (%d, %d) \n", origin->x, origin->y);
	cprintf(YELLOW, "[INFO] Destino: (%d, %d) \n", destination->x, destination->y);

	fillIntMatrix(matrix, linesAmount, columnsAmount, 0);
	(*matrix)[YtoArrayIndex(destination->y, linesAmount)][XtoArrayIndex(destination->x)] = 1;

	for (int y = destination->y; y >= origin->y; y--) {
		for (int x = destination->x; x >= origin->x; x--) {
			Coordinates currentPosition = {x, y};
			int cpArrayY = YtoArrayIndex(y, linesAmount);
			int cpArrayX = XtoArrayIndex(x);

			if (y < columnsAmount && !checkConstruction(constructionsList, currentPosition, NORTH)) {
				int cpArrayY2 = YtoArrayIndex(y + 1, linesAmount);
				(*matrix)[cpArrayY][cpArrayX] += (*matrix)[cpArrayY2][cpArrayX];
			}

			if (x < linesAmount && !checkConstruction(constructionsList, currentPosition, EAST)) {
				int cpArrayX2 = XtoArrayIndex(x + 1);
				(*matrix)[cpArrayY][cpArrayX] += (*matrix)[cpArrayY][cpArrayX2];
			}
		}
	}

	if (analysisMode) finishBenchmark(startTime, MICROSECONDS);
	printCity(matrix, linesAmount, columnsAmount, "Solução", constructionsList, FALSE, origin);
	return ((*matrix)[YtoArrayIndex(destination->y, linesAmount)][XtoArrayIndex(destination->x)] > 0);
}

// Imprime um caminho válido depois de resolvido o problema de obras na cidade
void printSolutionPath(int ***matrix, int linesAmount, int columnsAmount, CoordinatesPointer origin, CoordinatesPointer destination, ConstructionPointer constructionsList) {
	int **pathMatrix = NULL;
	pathMatrix = createIntMatrix(linesAmount, columnsAmount);
	fillIntMatrix(&pathMatrix, linesAmount, columnsAmount, NONE);

	Coordinates currentPosition = *origin;
	int cpArrayY, cpArrayX;

	pathMatrix[YtoArrayIndex(destination->y, linesAmount)][XtoArrayIndex(destination->x)] = -1;

	while (currentPosition.x != destination->x || currentPosition.y != destination->y) {
		cpArrayY = YtoArrayIndex(currentPosition.y, linesAmount);
		cpArrayX = XtoArrayIndex(currentPosition.x);

		int cpArrayYAux = YtoArrayIndex(currentPosition.y + 1, linesAmount);
		int cpArrayXAux = XtoArrayIndex(currentPosition.x + 1);

		if (currentPosition.y < linesAmount && (*matrix)[cpArrayYAux][cpArrayX] > 0 && !checkConstruction(constructionsList, currentPosition, NORTH)) {
			pathMatrix[cpArrayY][cpArrayX] = NORTH;
			currentPosition.y += 1;
			continue;
		}
		if (currentPosition.x < columnsAmount && (*matrix)[cpArrayY][cpArrayXAux] > 0 && !checkConstruction(constructionsList, currentPosition, EAST)) {
			pathMatrix[cpArrayY][cpArrayX] = EAST;
			currentPosition.x += 1;
			continue;
		}

		cprintf(RED, "Erro inesperado em (%d, %d). Tente mais tarde. \n", currentPosition.x, currentPosition.y);
		return;
	}

	printCity(&(pathMatrix), linesAmount, columnsAmount, "Caminho Válido", constructionsList, TRUE, origin);
	free(pathMatrix);
}

// Imprime uma representação da cidade, mostrando suas obras e quantidade de caminhos possíveis até o destino a partir de cada posição
void printCity(int ***matrix, int linesAmount, int columnsAmount, char* header, ConstructionPointer constructionsList, boolean printPath, CoordinatesPointer origin) {
	int precision = ((columnsAmount*1.25 * 1.5) + 2) + ((int) strlen(header) / 2);

	printMatrixLine(columnsAmount*1.25, 1, 1, BLUE);
	cprintf(MAGENTA, "%*s", precision, header);
	printMatrixLine(columnsAmount*1.25, 1, 1, BLUE);

	for (int i = 0; i < linesAmount; i++) {
		if (i > 0) {
			cprintf(CYAN, " | ");
			for (int j = 0; j < columnsAmount; j++) {
				Coordinates currentPosition = {arrayIndexToX(j), arrayIndexToY(i, linesAmount)};
				AvailableColors colorRoad = (checkConstruction(constructionsList, currentPosition, NORTH)) ? RED : GREEN;

				cprintf(colorRoad, "==");
				if (j < columnsAmount - 1) printf("  ");
			}
			cprintf(CYAN, " |\n");
		}

		cprintf(CYAN, " | ");
		for (int j = 0; j < columnsAmount; j++) {
			Coordinates currentPosition = {arrayIndexToX(j), arrayIndexToY(i, linesAmount)};
			AvailableColors colorRoad = (checkConstruction(constructionsList, currentPosition, EAST)) ? RED : GREEN;
			AvailableColors colorDirection = (currentPosition.x == origin->x && currentPosition.y == origin->y) ? BLUE : YELLOW;

			if (!printPath) {
				cprintf(YELLOW, "%.2d", (*matrix)[i][j]);
			} else if ((*matrix)[i][j] == NORTH) {
				cprintf(colorDirection, "/\\");
			} else if ((*matrix)[i][j] == EAST) {
				cprintf(colorDirection, "->");
			} else if ((*matrix)[i][j] == -1) {
				cprintf(BLUE, "**");
			} else {
				cprintf(YELLOW, "  ");
			}

			if (j < columnsAmount - 1) cprintf(colorRoad, "||");
		}
		cprintf(CYAN, " |\n");
	}

	printMatrixLine(columnsAmount*1.25, 1, 1, BLUE);
}
