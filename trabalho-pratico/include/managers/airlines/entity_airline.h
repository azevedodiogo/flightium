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