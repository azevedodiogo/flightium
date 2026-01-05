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
 * @brief Obtém o tempo total de execução registado.
 * @param query_result Entidade alvo.
 * @return Tempo total em segundos.
 */
double get_query_result_total_time (QueryResult query_result);

/**
 * @brief Define o número de queries corretas.
 * @param query_result Entidade alvo.
 * @param number_correct Valor a definir.
 */
void set_query_result_correct (QueryResult query_result, int number_correct);



// {- Structure -}

/**
 * @brief Cria a estrutura de armazenamento de resultados de query.
 * @param expected_results Caminho para o ficheiro de resultados esperados.
 * @return Estrutura inicializada ou NULL em caso de falha.
 */
StorageQueryResults create_storage_query_results (char *expected_results);

/**
 * @brief Liberta todos os recursos associados à estrutura de resultados.
 * @param storage_query_results Estrutura a eliminar.
 */
void destroy_storage_query_results (StorageQueryResults storage_query_results);

/**
 * @brief Obtém o caminho do ficheiro de resultados esperados.
 * @param storage_query_results Estrutura de resultados.
 * @return String com o caminho configurado.
 */
const char *get_expected_results (StorageQueryResults storage_query_results);

/**
 * @brief Obtém os resultados de uma query pelo índice.
 * @param storage_query_results Estrutura de armazenamento.
 * @param index Índice pretendido.
 * @return Registo correspondente ou NULL se fora dos limites.
 */
QueryResult get_query_result_by_index (StorageQueryResults storage_query_results, int index);



// {- Utils -}

/**
 * @brief Atualiza um resultado de query com o tempo decorrido.
 * @param query_result Entidade alvo.
 * @param elapsed Tempo decorrido a adicionar.
 */
void update_query_result (QueryResult query_result, double elapsed);

#endif