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