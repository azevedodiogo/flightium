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