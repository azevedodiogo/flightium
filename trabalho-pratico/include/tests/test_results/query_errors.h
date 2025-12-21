#ifndef QUERY_ERRORS_H
#define QUERY_ERRORS_H

#include <glib.h>

/** @brief Estrutura da entidade erro da query. */
typedef struct query_error *QueryError;

/** @brief Estrutura de armazenamento da entidade erro da query. */
typedef struct storage_query_errors *StorageQueryErrors;



// {- Entity -}

/**
 * @brief Cria um registo de erro de query.
 * @param query_num Número da query.
 * @param command_num Número sequencial do comando.
 * @return Nova entidade erro ou NULL em caso de falha.
 */
QueryError create_query_error (int query_num, int command_num);

/**
 * @brief Liberta a memória associada a um erro de query.
 * @param query_error Entidade a destruir.
 */
void destroy_query_error (QueryError query_error);

/**
 * @brief Obtém o número da query a que o erro pertence.
 * @param query_error Entidade alvo.
 * @return Número da query.
 */
int get_query_error_number (QueryError query_error);

/**
 * @brief Obtém o número do comando em erro.
 * @param query_error Entidade alvo.
 * @return Número do comando.
 */
int get_query_error_command (QueryError query_error);

/**
 * @brief Obtém o número da linha do ficheiro de resultados.
 * @param query_error Entidade alvo.
 * @return Número da linha.
 */
int get_query_error_line (QueryError query_error);

/**
 * @brief Obtém a linha esperada registada para o erro.
 * @param query_error Entidade alvo.
 * @return String com a linha esperada.
 */