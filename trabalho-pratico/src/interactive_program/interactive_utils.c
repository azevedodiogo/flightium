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