#include "tests/test_results/query_results.h"

#include <glib.h>

// Estrutura da entidade resultado da query
typedef struct query_result {
    int number_correct;
    int number_executed;
    double total_time;
} QUERY_RESULT, *QueryResult;



// Cria um registo da entidade resultado da query
QueryResult create_query_result () {

    // Aloca memória para o registo
    QueryResult query_result = g_malloc0 (sizeof (QUERY_RESULT));

    // Retorna o registo
    return query_result;
}
