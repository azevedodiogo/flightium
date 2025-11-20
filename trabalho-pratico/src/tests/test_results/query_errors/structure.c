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
    storage_query_errors -> data = g_ptr_array_new ();

    // Retorna a estrutura
    return storage_query_errors;
}

// Elimina a estrutura de armazenamento da entidade erro da query
void destroy_storage_query_errors (StorageQueryErrors storage_query_errors) {

    // Elimina os elementos do array
    for (guint i = 0; i < storage_query_errors -> data -> len; i++) destroy_query_error (storage_query_errors -> data -> pdata [i]);

    // Elimina a sub-estrutura
    g_ptr_array_free (storage_query_errors -> data, TRUE);

    // Elimina a estrutura
    g_free (storage_query_errors);
}

// Obtém um erro de uma query pelo índice
QueryError get_query_error_by_index (StorageQueryErrors storage_query_errors, int index) {
    return storage_query_errors -> data -> pdata [index];
}
