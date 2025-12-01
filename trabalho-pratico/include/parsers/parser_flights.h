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
 * @return 1 se corresponder, 0 caso contrário.
 */
int validate_not_applicable (const char *string);

/**
 * @brief Valida coerência temporal das datas de um voo.
 * @param status Estado do voo.
 * @param departure Data/hora de partida programada.
 * @param actual_departure Data/hora de partida real.
 * @param arrival Data/hora de chegada programada.
 * @param actual_arrival Data/hora de chegada real.
 * @return 1 se todas as datas forem consistentes, 0 caso contrário.
 */
int validate_flight_dates (const char status, date departure, date actual_departure, date arrival, date actual_arrival);

#endif