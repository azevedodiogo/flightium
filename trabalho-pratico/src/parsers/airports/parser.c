#include "parsers/parser_airports.h"

#include "utils/utility_functions.h"
#include "parsers/general_validations.h"
#include "managers/airports/structure_airports.h"

// Carrega uma linha do dataset dos aeroportos
int load_line_airports (char *input, Database database) {

    // Carrega o código
    char *code = separate_block (&input, '"');
    if (validate_code (code)) return EXIT_FAILURE;

    // Carrega o nome
    char *name = separate_block (&input, '"');
