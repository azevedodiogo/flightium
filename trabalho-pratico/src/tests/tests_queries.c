#define _POSIX_C_SOURCE 199309L

#include "tests/tests_queries.h"

#include "tests/tests_utils.h"
#include "tests/test_results/test_results.h"
#include "managers/database.h"
#include "queries/queries.h"

#include <stdio.h>
#include <sys/resource.h>

#define BUFFER 1024
#define LARGE_BUFFER 4096

// Executa as queries dadas
int test_execute_queries (Database database, const char *directory, Tests tests) {

    // Declara o ficheiro
    FILE *read_file;

    // Abre o ficheiro
    if (open_input_file (&read_file, directory)) {
        destroy_database (database); destroy_tests (tests);
        return EXIT_FAILURE;
    }

    // Inicializa variáveis auxiliares
    double total_query_time = 0.0f; int total_queries = 0;

    // Indica o início da execução
    print_start_text_queries ();