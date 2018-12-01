/**
 * TAD de Construções. Define uma lista encadeada de construções na cidade
 *
 * Gustavo Viegas (3026) e Heitor Passeado (3055)
 * @author Gustavo Viegas
 */

#ifndef construction_h
#define construction_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../util/logger.h"
#include "../util/boolean.h"
#include "direction.h"

typedef struct Construction* ConstructionPointer;
typedef struct Construction {
	boolean active; // Se a obra está ou não ativa
	Coordinates position; // Posição (X,Y) da obra
	Direction direction; // Direção da obra
	ConstructionPointer next; // Próximo item da lista encadeada
} Construction;

/**
 * Verifica se uma construção é vazia
 * @param  construction
 * @return boolean representando se ela é ou não vazia
 */
boolean isConstructionEmpty(ConstructionPointer construction);

/**
 * Aloca espaço para uma construção
 * @param  position  Posição que ela possuiŕa
 * @param  direction Direção que ela teŕa
 * @return           Construção criada
 */
ConstructionPointer createConstruction(Coordinates position, Direction direction);

/**
 * Adiciona uma construção na Lista Encadeada
 * @param  constructionsList Lista de construções
 * @param  position          Posição que ela conterá
 * @param  direction         Direção que ela terá
 * @return                   Boolean representando se ela foi ou não adicionada
 */
boolean addConstruction(ConstructionPointer *constructionsList, Coordinates position, Direction direction);

/**
 * Limpa a lista de construções
 * @param constructionsList Lista de construções a ser verificada
 */
void clearConstructionList(ConstructionPointer *constructionsList);

/**
 * Checa se uma determinada construção está na Lista
 * @param  constructionsList Lista de construções a ser verificada
 * @param  position          Posição da construção a ser verificada
 * @param  direction         Direção da construção a ser verificada
 * @return                   Boolean representando se ela foi ou não encontrada
 */
boolean checkConstruction(ConstructionPointer constructionsList, Coordinates position, Direction direction);

/**
 * Exibe construção, se ela é ativa, sua posição, direção e código
 * @param construction construção a ser exibida
 */
void printConstruction(Construction construction);

/**
 * Imprime todas as construções na Lista
 * @param constructionsList Lista a ser verificada
 */
void printAllConstructions(ConstructionPointer constructionsList);


#endif
