#ifndef ENTITY_PASSENGER_H
#define ENTITY_PASSENGER_H

#include "utils/date_functions.h"

#include <glib.h>

/** @brief Entidade que representa um passageiro. */
typedef struct entity_passenger *EntityPassenger;   // Protege-se assim a estrutura interna, ou seja, o utilizador não a vê diretamente.


/**
 * @brief Cria um registo com a informação do passageiro.
 * @param first_name Primeiro nome.
 * @param last_name Último nome.
 * @param nationality Nacionalidade.