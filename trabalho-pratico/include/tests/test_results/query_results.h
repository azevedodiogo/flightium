#ifndef QUERY_RESULTS_H
#define QUERY_RESULTS_H

/** @brief Estrutura da entidade resultado da query. */
typedef struct query_result *QueryResult;

/** @brief Estrutura de armazenamento da entidade resultado de query. */
typedef struct storage_query_results *StorageQueryResults;



// {- Entity -}

/**
 * @brief Cria um registo de resultado de query.
 * @return Nova entidade resultado ou NULL em caso de falha.
 */
QueryResult create_query_result ();

/**
 * @brief Liberta a memória associada a um resultado de query.
 * @param query_result Entidade a destruir.
 */
void destroy_query_result (QueryResult query_result);