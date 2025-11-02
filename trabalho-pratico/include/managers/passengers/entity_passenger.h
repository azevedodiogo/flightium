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
 * @param document_number Número do documento de identificação.
 * @param dob Data de nascimento (formato `date`). O formato está declarado em 'common_types.h'.
 * @return Nova entidade passageiro.
 */
EntityPassenger create_passenger (const char *first_name, const char *last_name, const char *nationality, int document_number, date dob);

/**
 * @brief Liberta a memória associada a um passageiro.
 * @param passenger Ponteiro para a entidade.
 */
void destroy_passenger (gpointer passenger);

/**
 * @brief Obtém o primeiro nome do passageiro.
 * @param passenger Registo alvo.
 * @return String com o primeiro nome.