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