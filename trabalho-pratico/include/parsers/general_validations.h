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
int validate_code (const char *string);

/**
 * @brief Valida a representação textual de um número de documento.
 * @param string Texto a validar.
 * @return 1 se válido, 0 caso contrário.
 */
int validate_document_number (const char *string);

/**
 * @brief Valida o identificador de um voo.
 * @param string Texto a validar.
 * @return EXIT_SUCCESS quando o identificador é válido. EXIT_FAILURE em caso contrário.
 */
int validate_flight_id (const char *string);
