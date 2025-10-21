#ifndef PARSER_AIRPORTS_H
#define PARSER_AIRPORTS_H

#include "managers/database.h"

// {- Parser -}

/**
 * @brief Carrega e valida uma linha do dataset dos aeroportos.
 * @param input Linha lida do ficheiro CSV.
 * @param database Base de dados onde o registo será inserido.
 * @return 0 em caso de sucesso. Caso contrário, devolve-se um valor não nulo se ocorrer erro de parsing.
 */
int load_line_airports (char *input, Database database);



// {- Validations -}

/**
 * @brief Valida uma latitude no formato textual.
 * @param string Texto a validar.
 * @return 1 se válido, 0 caso contrário.
 */
int validate_latitude (const char *string);

/**
 * @brief Valida uma longitude no formato textual.
 * @param string Texto a validar.
 * @return 1 se válido, 0 caso contrário.
 */
int validate_longitude (const char *string);