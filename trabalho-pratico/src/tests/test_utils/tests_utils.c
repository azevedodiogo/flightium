#include "tests/tests_utils.h"

#include "tests/test_results/load_timer.h"
#include "tests/test_results/query_errors.h"
#include "tests/test_results/query_results.h"

#include <stdio.h>

#define N_DATASETS 5
#define N_QUERIES 6

// Nomes dos datasets
const char *dataset_names [N_DATASETS] = {"Aircrafts", "Airports", "Passengers", "Flights", "Reservations"};



// Imprime o texto de início dos testes dos datasets
void print_start_text_parsers () {
    printf ("\n=== DATASET LOADING STARTED ===\n\n");
}

// Imprime o texto de fim dos testes dos datasets
void print_end_text_parsers (double total_load_time) {

    // Imprime o tempo total
    fprintf (stderr, "Total loading time: %.3f s\n", total_load_time);

    // Imprime o texto de fim
    printf ("\n=== DATASET LOADING COMPLETED ===\n\n");
}

// Atualiza o temporizador
double update_load_timer (LoadTimer load_timer, int index, double elapsed) {

    // Define o tempo de processamento do dataset
    set_dataset_time (load_timer, index, elapsed);

    // Imprime o tempo do processamento do dataset
    fprintf (stderr, "Dataset %s: %.3f s\n", dataset_names [index], get_dataset_time (load_timer, index));

    // Retorna o tempo de processamento do dataset
    return elapsed;
}

// Imprime o tempo de execução da preparação da base de dados
void print_prepare_time (struct timespec start_time, struct timespec end_time) {
    printf ("Preparing database time: %.3f ms\n", 1000.0f * (double) ((end_time.tv_sec - start_time.tv_sec) + (end_time.tv_nsec - start_time.tv_nsec) / 1e9));
}

// Imprime o resumo dos testes
void print_test_summary (struct timespec start_time, struct timespec end_time, struct rusage r_usage) {
    printf("\n=== SUMMARY ===\n");
    printf ("Total run time: %.6f s\n", (double) ((end_time.tv_sec - start_time.tv_sec) + (end_time.tv_nsec - start_time.tv_nsec) / 1e9));
    printf ("Memory usage: %.3f MB\n\n", r_usage.ru_maxrss / 1024.0);
}

// Atualiza estatísticas da query
void update_query_timing (StorageQueryResults stats, int index, struct timespec start, struct timespec end, double *total_query_time, int *total_queries) {
    
    // Calcula tempo decorrido em segundos
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    
    // Atualiza as estatísticas
    update_query_result (get_query_result_by_index (stats, index), elapsed);

    // Atualiza o total
    *total_query_time += elapsed;
    (*total_queries)++;
}

// Imprime o texto de início dos testes das queries
void print_start_text_queries () {
    printf ("\n=== QUERY EXECUTION STARTED ===\n\n");
}

// Imprime o testo de fim dos testes das queries
void print_end_test_queries (StorageQueryResults stats, StorageQueryErrors errors, int total_queries, double total_query_time) {
    print_query_stats (stats, total_queries, total_query_time);
    print_query_errors (errors);
}

// Imprime os resultados das queries
void print_query_stats (StorageQueryResults stats, int total_queries, double total_query_time) {

    // Variáveis auxiliares
    int total_correct_sum = 0;
    double total_query_ms = total_query_time * 1000;
    double avg_query_ms = total_queries > 0 ? total_query_ms / total_queries : 0.0f;

    // Imprime o cabeçalho inicial
    printf("Query  Executions  Correct  Total Time (ms)  Average (ms)\n");
    printf("-----  ----------  -------  ---------------  ------------\n");
    
    // Imprime os resultados de cada query
    for (int i = 0; i < N_QUERIES; i++) {
        QueryResult result = get_query_result_by_index (stats, i);
        double total_ms = get_query_result_total_time (result) * 1000, avg_ms = total_ms / get_query_result_executed (result);
        total_correct_sum += get_query_result_correct (result);
        printf ("Q%-2d    %10d     %3d    %14.3f  %12.3f\n", i + 1, get_query_result_executed (result), get_query_result_correct (result), total_ms, avg_ms);
    }

    // Imprime o cabeçalho final
    printf("-----  ----------  -------  ---------------  ------------\n");
    printf("Total  %10d     %3d    %14.3f  %12.3f (avg)\n", total_queries, total_correct_sum, total_query_ms, avg_query_ms);
}

// Imprime os erros das queries
void print_query_errors (StorageQueryErrors errors) {

    // Obtém o número de erros
    int count = get_number_errors (errors);

    // Verifica se não houve nenhum erro
    if (count == 0) return;
    
    // Imprime o cabeçalho
    printf ("\n\n=== QUERY ERRORS (%d) ===\n\n", count);
    
    // Imprime cada erro
    for (int i = 0; i < count; i++) {
        QueryError error = get_query_error_by_index (errors, i);
        printf ("Query %d (command%d) differs on line %d\n", get_query_error_number (error), get_query_error_command (error), get_query_error_line (error)); 
        printf ("Expected: %s || Actual: %s\n\n", get_query_error_expected (error), get_query_error_actual (error)); 
    }
}