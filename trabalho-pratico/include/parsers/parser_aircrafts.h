#ifndef PARSER_AIRCRAFTS_H
#define PARSER_AIRCRAFTS_H

#include "managers/database.h"

// {- Parser -}

/**
 * @brief Carrega e valida uma linha do dataset das aeronaves.
 * @param input Linha lida do ficheiro CSV.
 * @param database Base de dados onde o registo será inserido.
 * @return 0 em caso de sucesso; valor não nulo se ocorrer erro de parsing.
 */