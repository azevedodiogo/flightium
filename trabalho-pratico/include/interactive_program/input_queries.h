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
 * @param max_y Altura disponível do ecrã.
 * @param max_x Largura disponível do ecrã.
 * @param input Área de memória onde é colocado o argumento recolhido.
 * @return EXIT_SUCCESS se a validação for concluída. EXIT_FAILURE se o utilizador cancelar.
 */
int get_query1_arguments (int max_y, int max_x, char *input);

/**
 * @brief Solicita o número de aeronaves e o fabricante para a query 2.
 * @param max_y Altura disponível do ecrã.
 * @param max_x Largura disponível do ecrã.
 * @param input Área de memória onde são colocados os argumentos concatenados.
 * @return EXIT_SUCCESS se a validação for concluída. EXIT_FAILURE se o utilizador cancelar.
 * @warning O fabricante é opcional; o número de aeronaves é obrigatório e validado como dígitos.
 */
int get_query2_arguments (int max_y, int max_x, char *input);

/**
 * @brief Solicita um intervalo de datas (formato yyyy-mm-dd) para a query 3.
 * @param max_y Altura disponível do ecrã.
 * @param max_x Largura disponível do ecrã.
 * @param input Área de memória onde são colocados os argumentos concatenados.
 * @return EXIT_SUCCESS se a validação for concluída. EXIT_FAILURE se o utilizador cancelar.
 */
int get_query3_arguments (int max_y, int max_x, char *input);

/**
 * @brief Solicita a data inicial e, opcionalmente, a data final para a query 4.
 * @param max_y Altura disponível do ecrã.
 * @param max_x Largura disponível do ecrã.
 * @param input Área de memória onde são colocados os argumentos concatenados.
 * @return EXIT_SUCCESS se a validação for concluída. EXIT_FAILURE se o utilizador cancelar.
 * @warning A data inicial pode ser deixada vazia; caso seja preenchida, torna-se obrigatório indicar a data final.
 */
int get_query4_arguments (int max_y, int max_x, char *input);

/**
 * @brief Solicita o número de companhias aéreas para a query 5.
 * @param max_y Altura disponível do ecrã.
 * @param max_x Largura disponível do ecrã.
 * @param input Área de memória onde é colocado o argumento.
 * @return EXIT_SUCCESS se a validação for concluída. EXIT_FAILURE se o utilizador cancelar.
 */
int get_query5_arguments (int max_y, int max_x, char *input);

/**
 * @brief Solicita a nacionalidade para a query 6.
 * @param max_y Altura disponível do ecrã.
 * @param max_x Largura disponível do ecrã.
 * @param input Área de memória onde é colocado o argumento.
 * @return EXIT_SUCCESS se a validação for concluída. EXIT_FAILURE se o utilizador cancelar.
 */
int get_query6_arguments (int max_y, int max_x, char *input);

#endif