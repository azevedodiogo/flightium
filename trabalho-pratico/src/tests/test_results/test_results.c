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

    // Verifica se os testes existem
    if (tests == NULL) return;

    // Elimina as sub-estruturas
    destroy_load_timer (tests -> load_timer);
    destroy_storage_query_errors (tests -> errors);
    destroy_storage_query_results (tests -> results);

    // Elimina a estrutura
    g_free (tests);
}

// Devolve a estrutura dos tempos de leitura
LoadTimer get_tests_load_timer (Tests tests) {
    return tests -> load_timer;
}

// Devolve a estrutura dos erros das queries
StorageQueryErrors get_tests_query_errors (Tests tests) {
    return tests -> errors;
}

// Devolve a estrutura dos resultados das queries
StorageQueryResults get_tests_query_results (Tests tests) {
    return tests -> results;
}

// Devolve o ficheiro de resultados esperados dos testes
const char *get_tests_expected_results (Tests tests) {
    return get_expected_results (tests -> results);
}