#ifndef ENTITY_AIRLINE_H
#define ENTITY_AIRLINE_H

#include <glib.h>

/** @brief Entidade que representa uma companhia aérea. */
typedef struct entity_airline *EntityAirline;



/**
 * @brief Cria um registo de companhia aérea.
 * @param name Nome da companhia.
 * @param delay Valor inicial de atraso (em minutos).
 * @return Nova entidade.
 */
EntityAirline create_airline (const char *name, int delay);

/**
 * @brief Liberta a memória associada a uma companhia aérea.
 * @param airline Ponteiro para a entidade.
 */
void destroy_airline (gpointer airline);

/**
 * @brief Obtém o nome da companhia.
 * @param airline Registo alvo.
 * @return String com o nome da companhia.
 */
const char *get_airline_name (const struct entity_airline *airline);