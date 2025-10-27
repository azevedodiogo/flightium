#define _POSIX_C_SOURCE 199309L

#include "queries/queries.h"
#include "utils/utility_functions.h"
#include "tests/test_results/test_results.h"
#include "tests/tests_parsers.h"
#include "tests/tests_queries.h"
#include "tests/tests_utils.h"

#include <sys/resource.h>
#include <stdio.h>

// Função principal
int main (int argc, char **argv) {

    // Declara variáveis de teste
    struct timespec start_time, end_time, prepare_start, prepare_end; struct rusage r_usage;

    // Inicia os testes
    clock_gettime (CLOCK_REALTIME, &start_time);

    // Verifica se não foram dados três argumentos
    if (argc != 4) {
        fprintf (stderr, "Error: There should be three arguments\n");