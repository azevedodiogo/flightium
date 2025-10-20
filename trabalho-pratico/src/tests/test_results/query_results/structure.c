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