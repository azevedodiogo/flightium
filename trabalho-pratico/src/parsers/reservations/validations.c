#include "parsers/parser_reservations.h"

#include <ctype.h>
#include <glib.h>

#define NO_VALUE -1

// Verifica se uma string representa corretamente o id de uma reserva
int validate_reservation_id (const char *string) {

    // Verifica se o primeiro caractere não é um R
    if (string [0] != 'R') return NO_VALUE;