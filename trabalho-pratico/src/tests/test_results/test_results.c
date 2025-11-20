#include "tests/test_results/test_results.h"

#include "tests/test_results/load_timer.h"
#include "tests/test_results/query_errors.h"
#include "tests/test_results/query_results.h"

// Estrutura de armazenamento dos testes
typedef struct tests {
    LoadTimer load_timer;
    StorageQueryErrors errors;
    StorageQueryResults results;
} TESTS, *Tests;



// Cria a estrutura de armazenamento dos testes
Tests create_tests (char *expected_results) {

    // Aloca memória para a estrutura
    Tests tests = g_malloc (sizeof (TESTS));

    // Cria as sub-estruturas
    tests -> load_timer = create_load_timer ();
    tests -> errors = create_storage_query_errors ();
    tests -> results = create_storage_query_results (expected_results);

    // Retorna a estrutura
    return tests;
}

// Elimina a estrutura de armazenamento dos testes
void destroy_tests (Tests tests) {