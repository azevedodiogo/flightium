#ifndef TESTS_UTILS_H
#define TESTS_UTILS_H

#include <glib.h>
#include <sys/resource.h>

/** @brief Estrutura para medir os tempos de leitura. */
typedef struct load_timer *LoadTimer;

/** @brief Estrutura de armazenamento da entidade erro da query. */
typedef struct storage_query_errors *StorageQueryErrors;

/** @brief Estrutura de armazenamento da entidade resultado de query. */
typedef struct storage_query_results *StorageQueryResults;



/**
 * @brief Imprime o cabeçalho inicial dos testes de parsing.
 */
void print_start_text_parsers ();

/**
 * @brief Imprime o texto final dos testes de parsing.
 * @param total_load_time Tempo total gasto no carregamento dos datasets.
 */
void print_end_text_parsers (double total_load_time);

/**
 * @brief Atualiza o temporizador de leitura para um dataset.
 * @param load_timer Estrutura de temporização.
 * @param index Índice do dataset.
 * @param elapsed Tempo decorrido a registar.
 * @return Tempo total acumulado após a atualização.
 */
double update_load_timer (LoadTimer load_timer, int index, double elapsed);

/**
 * @brief Imprime o tempo de execução da preparação da base de dados.
 * @param start_time Instante inicial medido.
 * @param end_time Instante final medido.
 */
void print_prepare_time (struct timespec start_time, struct timespec end_time);

/**
 * @brief Imprime o resumo global dos testes (tempo e memória).
 * @param start_time Instante inicial.
 * @param end_time Instante final.
 * @param r_usage Estatísticas de recursos obtidas via `getrusage`.
 */
void print_test_summary (struct timespec start_time, struct timespec end_time, struct rusage r_usage);

/**
 * @brief Atualiza estatísticas temporais de uma query.
 * @param stats Estrutura de resultados.
 * @param index Índice da query.
 * @param start Instante de início.
 * @param end Instante de fim.
 * @param total_query_time Acumulador de tempo total de queries.
 * @param total_queries Contador de queries executadas.
 */
void update_query_timing (StorageQueryResults stats, int index, struct timespec start, struct timespec end, double *total_query_time, int *total_queries);

/**
 * @brief Imprime o cabeçalho inicial dos testes das queries.
 */
void print_start_text_queries ();

/**
 * @brief Imprime o texto final dos testes das queries.
 * @param stats Estrutura de resultados das queries.
 * @param errors Estrutura com erros encontrados.