#include "parsers/parser_passengers.h"

#include <ctype.h>

#include <glib.h>

// Verifica se uma string representa corretamente o género de um passageiro
int validate_gender (const char *string) {
    return (string [0] == 'M' || string [0] == 'F' || string [0] == 'O') && string [1] == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}

// Verifica se uma string representa corretamente um email
int validate_email (const char *string) {
