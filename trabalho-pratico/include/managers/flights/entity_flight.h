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
 * @param flight Ponteiro para a entidade.
 */
void destroy_flight (gpointer flight);

/**
 * @brief Obtém o aeroporto de origem.
 * @param flight Registo alvo.
 * @return String com o código de origem.
 */
const char *get_flight_origin (const struct entity_flight *flight);

/**
 * @brief Obtém o aeroporto de destino.
 * @param flight Registo alvo.
 * @return String com o código de destino.
 */
const char *get_flight_destination (const struct entity_flight *flight);

/**
 * @brief Devolve a semana em que o voo ocorreu.
 * @param flight Registo alvo.
 * @return Índice da semana.
 */
week_index get_flight_week (const struct entity_flight *flight);