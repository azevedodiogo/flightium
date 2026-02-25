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

// Elimina um registo da entidade resultado da query
void destroy_query_result (QueryResult query_result) {
    g_free (query_result);
}

// Devolve o número de queries corretas de um resultado de query
int get_query_result_correct (QueryResult query_result) {
    return query_result -> number_correct;
}

// Devolve o número de queries executadas de um resultado de query
int get_query_result_executed (QueryResult query_result) {
    return query_result -> number_executed;
}

// Devolve o tempo total de execução de um resultado de query
double get_query_result_total_time (QueryResult query_result) {
    return query_result -> total_time;
}

// Define o número de queries corretas de um resultado de query
void set_query_result_correct (QueryResult query_result, int number_correct) {
    query_result -> number_correct = number_correct;
}