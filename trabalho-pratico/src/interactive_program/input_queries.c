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
    const char *arg_name;
    int (*validate_func) (const char *);
    char text1 [BUFFER];
    char text2 [BUFFER];
} ArgControler;

// Obtém um argumento obrigatório
static int get_argument (int n_args, ArgControler ac [], int max_x, int max_y) {

    // Define as medidas da janela
    int width = 60, pos_y = max_y / 2, pos_x = max_x / 2 - width / 2, i = 0;

    // Cria os textos
    for (int i = 0; i < n_args; i++) {
        sprintf (ac [i].text1, "Enter the %s:", ac [i].arg_name);
        sprintf (ac [i].text2, "Invalid %s!", ac [i].arg_name);
    }

    // Mantém o pedido
    while (i < n_args) {

        // Pede ao utilizador para inserir o argumento
        int cancelled = text_input_box(pos_y, pos_x, width, ac [i].buffer * sizeof (char), ac [i].text1, ac [i].arg, 2);
