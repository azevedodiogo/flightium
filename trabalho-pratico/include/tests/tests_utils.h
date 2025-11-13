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