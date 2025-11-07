#include "interactive_program/input_queries.h"

#include "parsers/general_validations.h"
#include "interactive_program/graphics.h"

#include <stdlib.h>
#include <string.h>

#define BUFFER 1024

// Obtém os argumentos para a query
int get_query_arguments (int query_number, char *input, int max_y, int max_x) {

    // Seleciona a função de acordo com o número da query
    switch (query_number) {
        case 1: if (get_query1_arguments(max_y, max_x, input)) return EXIT_FAILURE; break;