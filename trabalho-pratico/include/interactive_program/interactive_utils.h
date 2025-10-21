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
