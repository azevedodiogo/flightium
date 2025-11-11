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