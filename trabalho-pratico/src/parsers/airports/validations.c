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