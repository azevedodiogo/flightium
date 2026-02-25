#ifndef TEST_RESULT_H
#define TEST_RESULT_H

#include <glib.h>

/** @brief Estrutura de armazenamento dos testes e respetivos resultados. */
typedef struct tests *Tests;

/** @brief Estrutura para medir os tempos de leitura. */
typedef struct load_timer *LoadTimer;

/** @brief Estrutura de armazenamento da entidade erro da query. */
typedef struct storage_query_errors *StorageQueryErrors;

/** @brief Estrutura de armazenamento da entidade resultado de query. */
typedef struct storage_query_results *StorageQueryResults;



/**
 * @brief Cria a estrutura agregadora de resultados de testes.
 * @param expected_results Caminho para o ficheiro de resultados esperados.
 * @return Estrutura inicializada ou NULL em caso de falha.
 */
Tests create_tests (char *expected_results);

/**
 * @brief Liberta todos os recursos associados à estrutura de testes.
 * @param tests Estrutura a eliminar.
 */
void destroy_tests (Tests tests);

/**
 * @brief Obtém a estrutura de temporização de carregamento.
 * @param tests Estrutura agregadora.
 * @return Ponteiro para `LoadTimer` associado.
 */
LoadTimer get_tests_load_timer (Tests tests);

/**
 * @brief Obtém a estrutura de erros das queries.
 * @param tests Estrutura agregadora.
 * @return Ponteiro para `StorageQueryErrors` associado.
 */
StorageQueryErrors get_tests_query_errors (Tests tests);

/**
 * @brief Obtém a estrutura de resultados das queries.
 * @param tests Estrutura agregadora.
 * @return Ponteiro para `StorageQueryResults` associado.
 */
StorageQueryResults get_tests_query_results (Tests tests);

/**
 * @brief Obtém o caminho do ficheiro de resultados esperados.
 * @param tests Estrutura agregadora.
 * @return String com o caminho configurado.
 */
const char *get_tests_expected_results (Tests tests);

#endif