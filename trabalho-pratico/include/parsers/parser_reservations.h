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