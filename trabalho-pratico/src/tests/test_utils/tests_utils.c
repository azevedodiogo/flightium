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