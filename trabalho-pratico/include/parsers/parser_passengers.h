#ifndef PARSER_PASSENGERS_H
#define PARSER_PASSENGERS_H

#include "managers/database.h"

// {- Parser -}

/**
 * @brief Carrega e valida uma linha do dataset dos passageiros.
 * @param input Linha lida do ficheiro CSV.
 * @param database Base de dados onde o registo será inserido.
 * @return 0 em caso de sucesso. Caso contrário, devolve-se um valor não nulo se ocorrer erro de parsing.
 */
int load_line_passengers (char *input, Database database);



// {- Validations -}

/**
 * @brief Valida o género de um passageiro.
 * @param string Texto a validar.
 * @return 1 se válido, 0 caso contrário.
 */
int validate_gender (const char *string);

/**
 * @brief Valida o endereço de email de um passageiro.
 * @param string Texto a validar.
 * @return 1 se válido, 0 caso contrário.
 */
int validate_email (const char *string);

#endif