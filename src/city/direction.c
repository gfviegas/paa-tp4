/**
 * Define TAD de direções e coordenadas
 *
 * Gustavo Viegas (3026) e Heitor Passeado (3055)
 * @author Gustavo Viegas
 */

#include "direction.h"

// Converte uma direção em um caracter que o representa
char directionToLabel(Direction direction) {
	char label = (direction == EAST) ? 'L' : (direction == NORTH) ? 'N' : '-';
	return label;
}

// Converte um caracter que representa uma direção em uma struct Direction
Direction labelToDirection(char label) {
	Direction direction = (label == 'L') ? EAST : (label == 'N') ? NORTH : NONE;
	return direction;
}
