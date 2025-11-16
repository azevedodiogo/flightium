#ifndef ENTITY_AIRPORT_H
#define ENTITY_AIRPORT_H

#include <glib.h>

/** @brief Entidade que representa um aeroporto. */
typedef struct entity_airport *EntityAirport;



/**
 * @brief Cria um registo de aeroporto.
 * @param code Código IATA/ICAO do aeroporto.
 * @param name Nome completo.
 * @param city Cidade onde se insere.
 * @param type Tipo de aeroporto. Tipo pode ser "large_airport", "medium_airport", "small_airport", etc.
 * @param country País associado.
 * @return Nova entidade aeroporto.
 */
EntityAirport create_airport (const char *code, const char *name, const char *city, const char *type, const char *country);

/**
 * @brief Liberta a memória associada a um aeroporto.
 * @param airport Ponteiro para a entidade.
 */
void destroy_airport (gpointer airport);

/**
 * @brief Obtém o código do aeroporto.
 * @param airport Registo alvo.
 * @return String com o código.
 */