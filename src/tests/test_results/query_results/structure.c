#include "tests/test_results/query_results.h"

#include <glib.h>

#define NUMBER_QUERIES 6

// Estrutura de armazenamento da entidade resultado de query
typedef struct storage_query_results {
    QueryResult results [NUMBER_QUERIES];
    char *expected_results;
} STORAGE_QUERY_RESULTS, *StorageQueryResults;



// Cria a estrutura de armazenamento da entidade resultado de query
StorageQueryResults create_storage_query_results (char *expected_results) {

    // Aloca memória para a estrutura
    StorageQueryResults storage_query_results = g_malloc0 (sizeof (STORAGE_QUERY_RESULTS));

    // Define as componentes da estrutura
    for (int i = 0; i < NUMBER_QUERIES; i++) storage_query_results -> results [i] = create_query_result ();
    storage_query_results -> expected_results = g_strdup (expected_results);

    // Retorna a estrutura
    return storage_query_results;
}

// Elimina a estrutura de armazenamento da entidade resultado de query
void destroy_storage_query_results (StorageQueryResults storage_query_results) {

    // Elimina as componentes da estrutura
    for (int i = 0; i < NUMBER_QUERIES; i++) destroy_query_result (storage_query_results -> results [i]);
    g_free (storage_query_results -> expected_results);

    // Elimina a estrutura
    g_free (storage_query_results);
}

// Devolve o ficheiro de resultados esperados
const char *get_expected_results (StorageQueryResults storage_query_results) {
    return storage_query_results -> expected_results;
}

// Obtém os resultados de uma query pelo índice
QueryResult get_query_result_by_index (StorageQueryResults storage_query_results, int index) {
    return storage_query_results -> results [index];
}