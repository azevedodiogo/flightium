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

