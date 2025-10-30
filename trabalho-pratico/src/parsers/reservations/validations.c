#include "parsers/parser_reservations.h"

#include <ctype.h>
#include <glib.h>

#define NO_VALUE -1

// Verifica se uma string representa corretamente o id de uma reserva
int validate_reservation_id (const char *string) {

    // Verifica se o primeiro caractere não é um R
    if (string [0] != 'R') return NO_VALUE;

    // Verifica se os caracteres seguintes são dígitos
    int i; for (i = 1; i < 10; i++) if (!isdigit (string [i])) return NO_VALUE;

    // Verifica se a string terminou
    return string [i] == 0 ? atoi (string + 1) : NO_VALUE;
}