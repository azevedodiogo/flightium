#ifndef ENTITY_FLIGHT_H
#define ENTITY_FLIGHT_H

#include "utils/date_functions.h"

#include <glib.h>

/** @brief Entidade que representa um voo agregado por semana e estado. */
typedef struct entity_flight *EntityFlight;



/**
 * @brief Cria um registo de voo.
 * @param origin Código do aeroporto de origem.
 * @param destination Código do aeroporto de destino.
 * @param week Semana do ano a que o voo pertence.
 * @param status Estado do voo (por exemplo, cancelado, realizado).
 * @return Nova entidade voo.
 */
EntityFlight create_flight (const char *origin, const char *destination, week_index week, char status);

/**
 * @brief Liberta a memória associada a um voo.