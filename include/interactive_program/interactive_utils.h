#ifndef INTERACTIVE_UTILS_H
#define INTERACTIVE_UTILS_H

#include "managers/database.h"

/**
 * @brief Prepara a base de dados a partir de um caminho fornecido no modo interativo.
 * @param max_y Altura disponível.
 * @param max_x Largura disponível.
 * @return Ponteiro para `Database` pronto para queries. NULL se o utilizador cancelar.
 * @warning Requer que a biblioteca ncurses esteja inicializada. Bloqueia até a leitura/validação do caminho e carregamento dos datasets.
 */
Database setup_database (int max_y, int max_x);

/**
 * @brief Apresenta o menu das queries e devolve a escolha.
 * @param max_y Altura do ecrã.
 * @param max_x Largura do ecrã.
 * @return Número da query (1-6) ou 0 se cancelado.
 */
int menu_select_queries (int max_y, int max_x);

/**
 * @brief Apresenta o menu de delimitadores possíveis para output.
 * @param max_y Altura do ecrã.
 * @param max_x Largura do ecrã.
 * @return 0 para ';', 1 para '='; devolve -1 se cancelado.
 */
int menu_select_delimiters (int max_y, int max_x); 

/**
 * @brief Executa a query selecionada e mostra o resultado num modo navegável.
 * @param query_number Número da query (1-6).
 * @param delimiter Índice do delimitador escolhido (0 -> ';', 1 -> '=').
 * @param database Base de dados já preparada.
 * @param input Argumentos formatados para a query.
 * @param max_y Altura do ecrã.
 * @param max_x Largura do ecrã.
 * @return EXIT_SUCCESS em caso de execução. EXIT_FAILURE em caso de erro.
 * @warning Espera que a base de dados esteja carregada e que `input` seja válido. Bloqueia até o utilizador fechar o output.
 */
int execute_query (int query_number, int delimiter, Database database, char *input, int max_y, int max_x); 

#endif