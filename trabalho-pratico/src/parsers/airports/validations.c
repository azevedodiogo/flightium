#include "parsers/parser_airports.h"

#include <glib.h>
#include <ctype.h>

// Verifica se uma string representa corretamente uma latitude
int validate_latitude (const char *string) {

    // Verifica se é negativo
    if (string [0] == '-') string++;

    // Verifica se o primeiro caractere não é um dígito
    if (!isdigit (string [0])) return EXIT_FAILURE;

    // Verifica se o formato não é válido (antes do ponto)
    int i; for (i = 1; string [i] && string [i] != '.'; i++) if (i == 2 || !isdigit (string [i])) return EXIT_FAILURE;

    // Verifica se a string terminou
    if (string [i] == 0) return EXIT_FAILURE;

    // Verifica se o formato não é válido (depois do ponto)
    for (int j = 1; string [i + j]; j++) if (j == 9 || !isdigit (string [i + j])) return EXIT_FAILURE;

    // Verifica a validade do valor
    return atof (string) > 90 ? EXIT_FAILURE : EXIT_SUCCESS;
}

// Verifica se uma string representa corretamente uma longitude
int validate_longitude (const char *string) {

    // Verifica se é negativo
    if (string [0] == '-') string++;

    // Verifica se o primeiro caractere não é um dígito
    if (!isdigit (string [0])) return EXIT_FAILURE;

    // Verifica se o formato não é válido (antes do ponto)
    int i; for (i = 1; string [i] && string [i] != '.'; i++) if (i == 3 || !isdigit (string [i])) return EXIT_FAILURE;

    // Verifica se a string terminou