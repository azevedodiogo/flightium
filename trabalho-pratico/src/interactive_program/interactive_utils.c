#include "interactive_program/interactive_utils.h"

#include "parsers/parser_main.h"
#include "queries/queries.h"
#include "interactive_program/graphics.h"

#include <stdlib.h>
#include <string.h>

#define DEFAULT_PATH1 "../dataset-fase-1/com_erros/"
#define DEFAULT_PATH2 "../dataset-fase-2/com_erros/"
#define ERROR -1
#define NUM_QUERIES 6
#define BUFFER 1024
#define LARGE_BUFFER 4096

// Prepara a base de dados
Database setup_database (int max_y, int max_x) {

    // Posições centralizadas da janela de input
    int pos_y = max_y / 2;
    int pos_x = max_x / 2 - 30;

    // Buffer para o caminho
    char input_directory [BUFFER] = {0};

    // Cria a estrutura para armazenar a base de dados
    Database database = NULL;

    // Indica se o input é válido
    int valid_input = 0;

    while (!valid_input) {

        clear ();

        // Reseta o input
        memset (input_directory, 0, sizeof(input_directory));

        // Pede ao utilizador para escrever o caminho
        int cancelled = text_input_box (pos_y, pos_x, 60, BUFFER, "Enter path to data files:", input_directory, 1);

        // Se o utilizador carregar no ESC, a janela fecha
        if (cancelled) {
            modal_start ("Operation cancelled!", "OK", 40, max_y, max_x); return NULL;
        }
        // Se o utilizador não digitar nada, usa o caminho default
        if (strlen(input_directory) == 0) strcpy (input_directory, DEFAULT_PATH1);

        // Cria a base de dados
        database = create_database (0);

        clear(); refresh();

        draw_clock ();

        // Carrega os datasets
        if (load_datasets (database, input_directory)) {
            clear (); modal_start ("Error: invalid path.", "RETRY", 50, max_y, max_x); continue;  
        }
        // Valida o input
        valid_input = 1;
    }
    // Prepara a base de dados para as queries
    if (database) prepare_database (database);

    // Devolve a base de dados 
    return database;  
}

// Apresenta o menu das queries e retorna a escolha do utilizador
int menu_select_queries(int max_y, int max_x) {