#include "parsers/parser_aircrafts.h"

#include <ctype.h>
#include <glib.h>

// Verifica se uma string representa corretamente um ano
int validate_year (const char *string) {
    
    // Verifica se o formato é válido
    if (!isdigit (string [0]) || !isdigit (string [1]) || !isdigit (string [2]) || !isdigit (string [3]) || string [4]) return EXIT_FAILURE;

    // Verifica se o ano é válido
    return atoi (string) < 2026 ? EXIT_SUCCESS : EXIT_FAILURE;
}