/**
 * Define TAD de direções e coordenadas
 *
 * Gustavo Viegas (3026) e Heitor Passeado (3055)
 * @author Gustavo Viegas
 */

#ifndef direction_h
#define direction_h

#include <stdlib.h>

/**
* Direções disponíveis para percorrer a cidade.
*/
typedef enum Direction {
	NONE, // Nenhuma
	EAST, // Leste
	NORTH // Norte
} Direction;

typedef struct Coordinates* CoordinatesPointer;
typedef struct Coordinates {
	int x;
	int y;
} Coordinates;

/**
 * Converte uma direção em um caracter que o representa
 * @param  direction Direção a ser representada
 * @return           Caracter representando a direção (L ou N)
 */
char directionToLabel(Direction direction);

/**
 * Converte um caracter que representa uma direção em uma struct Direction
 * @param  label Caracter que representa uma direção
 * @return       Struct Direction que foi convertida do caracter passado
 */
Direction labelToDirection(char label);

#endif
