#ifndef GENERAL_VALIDATIONS_H
#define GENERAL_VALIDATIONS_H

#include "utils/date_functions.h"

/**
 * @brief Valor de retorno que sinaliza uma data inválida.
 */
#define INVALID_DATE 0

/**
 * @brief Valida se a cadeia de caracteres representa um código genérico (aeroporto, companhia, etc.).
 * @param string Texto a validar, terminado em '\0'.
 * @return EXIT_SUCCESS quando o código é válido. EXIT_FAILURE em caso contrário.
 */