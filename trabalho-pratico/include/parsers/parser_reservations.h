#ifndef PARSER_RESERVATIONS_H
#define PARSER_RESERVATIONS_H

#include "managers/database.h"

// {- Parser -}

/**
 * @brief Carrega e valida uma linha do dataset das reservas.
 * @param input Linha lida do ficheiro CSV.
 * @param database Base de dados onde o registo será inserido.
 * @return 0 em caso de sucesso. Caso contrário, devolve-se um valor não nulo se ocorrer erro de parsing.
 */
int load_line_reservations (char *input, Database database);



// {- Validations -}

/**
 * @brief Verifica se uma string representa corretamente o identificador de uma reserva.
 * @param string Texto a validar.
 * @return 1 se válido, 0 caso contrário.
 */
int validate_reservation_id (const char *string);

#endif