#include "parsers/parser_airports.h"

#include <glib.h>
#include <ctype.h>

// Verifica se uma string representa corretamente uma latitude
int validate_latitude (const char *string) {
