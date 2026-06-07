#include "interactive_program/input_queries.h"
#include "interactive_program/interactive_utils.h"
#include "interactive_program/graphics.h"

#include <stdlib.h>

#define BUFFER 1024



// Função principal
int main (int argc, char **argv) {

    // Verifica se foram dados argumentos
    if (argc != 1) {
        fprintf (stderr, "Error: There should be no arguments\n");
        return EXIT_FAILURE;
    } 
    // Ignora o argv
    (void) argv;

    // Inicializa o ncurses
    initscr(); start_color(); use_default_colors(); cbreak(); noecho(); keypad(stdscr, TRUE);

    // Define as cores
    init_pair(1, COLOR_WHITE, -1);
    init_pair(2, COLOR_CYAN, -1);

    // Obtém dimensões do terminal
    int max_y, max_x; getmaxyx(stdscr, max_y, max_x);

    // Apresenta uma mensagem inicial
    draw_plane_with_clouds ();
    modal_start ("Welcome to Travel Database", "START", 40, max_y, max_x);

    clear(); refresh();

    // Cria e carrega a base de dados
    Database database = setup_database (max_y, max_x);

    if (!database) {
        endwin(); return EXIT_FAILURE;
    }

    while (1) {

        clear(); refresh();

        // Apresenta o menu das queries e retorna a escolha do utilizador
        int choice = menu_select_queries (max_y, max_x);

        // Se o utilizador carregar no ESC, encerra o programa
        if (choice == 0) {
            destroy_database (database); endwin (); return EXIT_FAILURE;
        }
        // Apresenta o menu dos delimiters e retorna a escolha do utilizador
        int delimiter = menu_select_delimiters (max_y, max_x);

        // Se o utilizador carregar no ESC, encerra o programa
        if (delimiter == -1) {
            destroy_database (database); endwin (); return EXIT_FAILURE;
        }

        // Buffer para armazenar os argumentos da query
        char query_arguments [BUFFER] = {0};

        // Lê os argumentos da query selecionada
        int result = get_query_arguments (choice, query_arguments, max_y, max_x);

        // Se houve erro ao ler argumentos, encerra o programa
        if (result == EXIT_FAILURE) {
            destroy_database (database); endwin (); return EXIT_FAILURE;
        }
        // Executa a query 
        execute_query (choice, delimiter, database, query_arguments, max_y, max_x);
    }
    // Elimina a base de dados
    destroy_database (database);

    // Finaliza o ncurses
    endwin();

    // Termina o programa
    return EXIT_SUCCESS;
}