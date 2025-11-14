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
 * @param manufacturer Fabricante.
 * @param model Modelo específico.
 * @return Nova entidade aeronave.
 */
EntityAircraft create_aircraft (const char *identifier, const char *manufacturer, const char *model);

/**
 * @brief Liberta a memória associada a uma aeronave.