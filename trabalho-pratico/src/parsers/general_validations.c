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