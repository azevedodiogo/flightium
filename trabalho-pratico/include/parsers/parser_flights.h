#ifndef PARSER_FLIGHTS_H
#define PARSER_FLIGHTS_H

#include "utils/date_functions.h"
#include "managers/database.h"

// {- Parser -}

/**
 * @brief Carrega e valida uma linha do dataset dos voos.
 * @param input Linha lida do ficheiro CSV.
 * @param database Base de dados onde o registo será inserido.
 * @return 0 em caso de sucesso. Caso contrário, devolve-se um valor não nulo se ocorrer erro de parsing.
 */
int load_line_flights (char *input, Database database);



// {- Validations -}

/**
 * @brief Valida se a string corresponde à entrada 'N/A'.
 * @param string Texto a validar.