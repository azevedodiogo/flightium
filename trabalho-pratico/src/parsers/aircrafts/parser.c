#include "parsers/parser_aircrafts.h"

#include "utils/utility_functions.h"
#include "managers/aircrafts/structure_aircrafts.h"

// Carrega uma linha do dataset das aeronaves
int load_line_aircrafts (char *input, Database database) {

    // Carrega o identificador
    char *identifier = separate_block (&input, '"');

    // Carrega o fabricante
    char *manufacturer = separate_block (&input, '"');