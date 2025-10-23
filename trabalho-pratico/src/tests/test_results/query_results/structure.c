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
