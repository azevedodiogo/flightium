#include "tests/test_results/query_results.h"

// Estrutura da entidade resultado da query
typedef struct query_result {
    int number_correct;
    int number_executed;
    double total_time;
} QUERY_RESULT, *QueryResult;



// Atualiza um resultado de query
void update_query_result (QueryResult query_result, double elapsed) {

    // Incrementa o número de queries executadas
    query_result -> number_executed++;

    // Atualiza o tempo total de execução
    query_result -> total_time += elapsed;
}