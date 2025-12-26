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

/**
 * @brief Obtém o número de queries corretas registado.
 * @param query_result Entidade alvo.
 * @return Número de queries corretas.
 */
int get_query_result_correct (QueryResult query_result);

/**
 * @brief Obtém o número de queries executadas registado.
 * @param query_result Entidade alvo.
 * @return Número de queries executadas.
 */
int get_query_result_executed (QueryResult query_result);

/**