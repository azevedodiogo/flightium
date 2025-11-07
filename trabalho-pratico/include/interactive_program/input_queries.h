#ifndef INPUT_QUERIES
#define INPUT_QUERIES

/**
 * @brief Direciona a recolha de argumentos para a query selecionada.
 * @param query_number Número identificador da query (1 a 6).
 * @param input Área onde é devolvido o texto formatado com os argumentos.
 * @param max_y Altura disponível do ecrã ncurses, utilizada para centralização.
 * @param max_x Largura disponível do ecrã ncurses, utilizada para centralização.
 * @return EXIT_SUCCESS em caso de sucesso. EXIT_FAILURE se o utilizador cancelar.
 */
int get_query_arguments (int query_number, char *input, int max_y, int max_x);

/**
 * @brief Solicita o código do aeroporto para a query 1.