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