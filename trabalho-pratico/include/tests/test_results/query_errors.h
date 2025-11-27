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