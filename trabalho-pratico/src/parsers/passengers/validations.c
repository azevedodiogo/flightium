#include "parsers/parser_passengers.h"

#include <ctype.h>

#include <glib.h>

// Verifica se uma string representa corretamente o género de um passageiro
int validate_gender (const char *string) {
    return (string [0] == 'M' || string [0] == 'F' || string [0] == 'O') && string [1] == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}

// Verifica se uma string representa corretamente um email
int validate_email (const char *string) {

    // Verifica se o username é válido
    int i; for (i = 0; string [i] && string [i] != '@'; i++)
        if (!isdigit (string [i]) && !islower (string [i]) && string [i] != '.') return EXIT_FAILURE;

    // Verifica se a string terminou
    if (i == 0 || string [i++] == 0) return EXIT_FAILURE;
