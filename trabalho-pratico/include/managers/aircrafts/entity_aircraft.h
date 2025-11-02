#ifndef ENTITY_AIRCRAFT_H
#define ENTITY_AIRCRAFT_H

#include <glib.h>

/**
 * @brief Entidade que representa uma aeronave identificada pelo seu código.
 */
typedef struct entity_aircraft *EntityAircraft;



/**
 * @brief Cria um registo de aeronave.
 * @param identifier Código único da aeronave.