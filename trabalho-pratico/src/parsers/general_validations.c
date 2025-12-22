#include "parsers/general_validations.h"

#include <ctype.h>
#include <glib.h>

#define NO_VALUE -1

// Verifica se uma string representa corretamente um código
int validate_code (const char *string) {
    return isupper (string [0]) && isupper (string [1]) && isupper (string [2]) && string [3] == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}

// Verifica se uma string representa corretamente um número de documento
int validate_document_number (const char *string) {

    // Verifica se o formato é válido
    for (int i = 0; i < 9; i++) if (!isdigit (string [i])) return NO_VALUE;

    // Verifica se a string terminou
    return string [9] ? NO_VALUE : atoi (string);
}

// Verifica se uma string representa corretamente o identificador de um voo
int validate_flight_id (const char *string) {

    // Verifica se os dois primeiros caracteres não são letras maiúsculas
    if (!isupper (string [0]) || !isupper (string [1])) return EXIT_FAILURE;

    // Conta o número de dígitos
    int i = 2; while (isdigit (string [i])) i++;

    // Verifica se existem 5 ou 6 dígitos
    if (i != 7 && i != 8) return EXIT_FAILURE;

    // Verifica o resto da string
    return string [i] == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}

// Verifica se uma string representa um tempo
inline static int validate_time (const char *string) {

    // Verifica se a hora não está bem representada
    if (!isdigit (string [0]) || !isdigit (string [1]) || string [2] != ':') return EXIT_FAILURE;

    // Verifica se o minuto não está bem representado
    return !isdigit (string [3]) || !isdigit (string [4]) || string [5] ? EXIT_FAILURE : EXIT_SUCCESS;
}

// Verifica se uma string representa corretamente uma data
date validate_date (const char *string, int datetime) {

    // Verifica se o ano não está bem representado
    if (!isdigit (string [0]) || !isdigit (string [1]) || !isdigit (string [2]) || !isdigit (string [3]) || string [4] != '-') return INVALID_DATE;

    // Verifica se o mês não está bem representado
    if (!isdigit (string [5]) || !isdigit (string [6]) || string [7] != '-') return INVALID_DATE;

    // Verifica se o dia não está bem representado
    if (!isdigit (string [8]) || !isdigit (string [9]) || (datetime == 0 && string [10]) || (datetime && string [10] != ' ')) return INVALID_DATE;

    // Verifica se o tempo está bem definido
    if (datetime && validate_time (string + 11)) return INVALID_DATE;

    // Calcula as componentes da data
    int year = (string [0] - '0') * 1000 + (string [1] - '0') * 100 + (string [2] - '0') * 10 + (string [3] - '0') * 1;
    int month = (string [5] - '0') * 10 + (string [6] - '0') * 1;
    int day = (string [8] - '0') * 10 + (string [9] - '0') * 1;

    // Verifica se a data é válida
    if (year > 2025 || (year == 2025 && month > 9) || (year == 2025 && month == 9 && day > 30)) return INVALID_DATE;
    if (month == 0 || month > 12 || day == 0 || day > 31) return INVALID_DATE;

    // Retorna a data
    return datetime ? convert_datetime (year, month, day, atoi (string + 11), atoi (string + 14)) : convert_date (year, month, day);
}

// Verifica se um input só contém digitos
int validate_digits (const char *string) {
