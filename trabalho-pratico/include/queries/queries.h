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
int execute_queries (Database database, const char *directory);

/**
 * @brief Executa a query 1 e escreve o resultado formatado.
 * @param database Base de dados utilizada pela query.
 * @param input Linha de argumentos recebida (sem newline).
 * @param output Área de memória onde é construído o resultado.
 * @param del Delimitador de campos a aplicar à saída.
 * @warning `output` deve dispor de espaço suficiente para toda a resposta e terminar em '\0'.
 */
void execute_query1 (Database database, char *input, char *output, char del);

/**
 * @brief Executa a query 2 e escreve o resultado formatado.
 * @param database Base de dados utilizada pela query.
 * @param input Linha de argumentos recebida (sem newline).
 * @param output Área de memória onde é construído o resultado.
 * @param del Delimitador de campos a aplicar à saída.
 * @warning `output` deve ser alocado de forma a comportar todas as linhas de resposta produzidas.
 */
void execute_query2 (Database database, char *input, char *output, char del);

/**
 * @brief Executa a query 3 e escreve o resultado formatado.
 * @param database Base de dados utilizada pela query.
 * @param input Linha de argumentos recebida (sem newline).
 * @param output Área de memória onde é construído o resultado.
 * @param del Delimitador de campos a aplicar à saída.
 * @warning Se `output` for reutilizado entre chamadas, deve ser limpo pelo chamador antes de cada invocação.
 */
void execute_query3 (Database database, char *input, char *output, char del);

/**
 * @brief Executa a query 4 e escreve o resultado formatado.
 * @param database Base de dados utilizada pela query.
 * @param input Linha de argumentos recebida (sem newline).
 * @param output Área de memória onde é construído o resultado.
 * @param del Delimitador de campos a aplicar à saída.
 * @warning `output` deve suportar múltiplas linhas. O delimitador influencia o formato final.