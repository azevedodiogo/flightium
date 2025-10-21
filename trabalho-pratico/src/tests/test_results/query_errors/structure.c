#include "tests/test_results/query_errors.h"

// Estrutura de armazenamento da entidade erro da query
typedef struct storage_query_errors {
    GPtrArray *data;
} STORAGE_QUERY_ERRORS, *StorageQueryErrors;



// Cria a estrutura de armazenamento da entidade erro da query
StorageQueryErrors create_storage_query_errors () {

    // Aloca memória para a estrutura
    StorageQueryErrors storage_query_errors = g_malloc (sizeof (STORAGE_QUERY_ERRORS));

    // Cria a sub-estrutura