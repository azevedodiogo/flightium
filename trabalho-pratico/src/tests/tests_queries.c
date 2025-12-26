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

    // Declara o input da leitura
    char input [BUFFER], write_file_name [BUFFER] = "resultados/command";

    // Lê o ficheiro linha a linha
    for (int i = 1; fgets (input, BUFFER * sizeof (char), read_file); i++) {

        // Remove o '\n' no final do input
        input [strcspn (input, "\n")] = 0;

        // Define o nome do ficheiro
        sprintf (write_file_name + 18, "%d_output.txt", i);

        // Abre o ficheiro de escrita
        FILE *write_file = fopen (write_file_name, "w");

        // Resultado da query
        char output [LARGE_BUFFER] = "\n", delimiter = input [1] == 'S' ? '=' : ';', skips = 2 + (input [1] == 'S');

        // Inicializa a contabilização para a query
        struct timespec start, end; clock_gettime (CLOCK_REALTIME, &start);

        // Realiza a query
        switch (input [0]) {
            case '1': execute_query1 (database, input + skips, output, delimiter); break;
            case '2': execute_query2 (database, input + skips, output, delimiter); break;
            case '3': execute_query3 (database, input + skips, output, delimiter); break;
            case '4': execute_query4 (database, input + skips, output, delimiter); break;
            case '5': execute_query5 (database, input + skips, output, delimiter); break;
            case '6': execute_query6 (database, input + skips, output, delimiter); break;
        }

        // Atualiza o tempo de execução da query