#include "parsers/parser_aircrafts.h"

#include <ctype.h>
#include <glib.h>

// Verifica se uma string representa corretamente um ano
int validate_year (const char *string) {