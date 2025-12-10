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
        return EXIT_FAILURE;
    } int dataset;

    // Determina qual é o tipo de dataset
    if (determine_dataset (argv [1], &dataset)) {
        fprintf (stderr, "Error: invalid directory\n");
        return EXIT_FAILURE;
    }

    // Cria as estruturas
    Database database = create_database (dataset); Tests tests = create_tests (argv [3]);

    // Carrega os datasets
    if (test_load_datasets (database, argv [1], tests)) return EXIT_FAILURE;

    // Inicia a contabilização do tempo da preparação da base de dados
    clock_gettime (CLOCK_REALTIME, &prepare_start);

    // Prepara a base de dados para as queries
    prepare_database (database); 
    
    // Termina a contabilização do tempo da preparação da base de dados
    clock_gettime (CLOCK_REALTIME, &prepare_end);

    // Imprime o tempo de execução da preparação da base de dados
    print_prepare_time (prepare_start, prepare_end);

    // Executa as queries
    if (test_execute_queries (database, argv [2], tests)) return EXIT_FAILURE;

    // Elimina a base de dados
    destroy_database (database); destroy_tests (tests);
