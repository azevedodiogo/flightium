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
        case 2: if (get_query2_arguments(max_y, max_x, input)) return EXIT_FAILURE; break;
        case 3: if (get_query3_arguments(max_y, max_x, input)) return EXIT_FAILURE; break;
        case 4: if (get_query4_arguments(max_y, max_x, input)) return EXIT_FAILURE; break;
        case 5: if (get_query5_arguments(max_y, max_x, input)) return EXIT_FAILURE; break;
        case 6: if (get_query6_arguments(max_y, max_x, input)) return EXIT_FAILURE; break;
    }
    // Retorna o número da query
    return EXIT_SUCCESS;
}

// Função de validação das datas
static int validate_date_no_datetime (const char *s) {
    return !validate_date (s, 0);
}

// Função de validação da query 4
static int validate_args_query4 (const char *s) {
    return s [0] != 0 && !validate_date (s, 0); 
}

// Estrutura auxiliar
typedef struct arg_controler {
    char *arg;
    int buffer;