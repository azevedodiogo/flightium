#ifndef QUERIES_H
#define QUERIES_H

#include "managers/database.h"

#include <stdio.h>

/**
 * @brief Abre o ficheiro de entrada que contém as queries a executar.
 * @param read_file Ponteiro onde é devolvido o identificador do ficheiro aberto.
 * @param read_file_name Caminho completo para o ficheiro de input.
 * @return EXIT_SUCCESS em caso de abertura bem-sucedida. EXIT_FAILURE em caso contrário.
 * @warning O ficheiro permanece aberto após o retorno.  O chamador assume a responsabilidade por o fechar.
 */
int open_input_file (FILE **read_file, const char *read_file_name);

/**
 * @brief Executa sequencialmente todas as queries descritas no ficheiro de entrada.
 * @param database Base de dados previamente carregada e preparada.
 * @param directory Caminho para o ficheiro que contém as instruções das queries.
 * @return EXIT_SUCCESS em caso de processamento sem erros. EXIT_FAILURE em caso contrário.
 * @warning Escreve os resultados em `resultados/commandN_output.txt`.
 */