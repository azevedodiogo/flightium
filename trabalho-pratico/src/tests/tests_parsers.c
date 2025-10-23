#include "tests/tests_parsers.h"

#include "parsers/parser_main.h"
#include "managers/database.h"
#include "tests/test_results/test_results.h"
#include "tests/test_results/load_timer.h"
#include "tests/tests_utils.h"
#include "parsers/parser_definitions.h"

#include <glib.h>

#define BUFFER 1024

// Funções de carregamento dos datasets
static int (*load_line [N_DATASETS]) (char *, Database) = {load_line_aircrafts, load_line_airports, load_line_passengers, load_line_flights, load_line_reservations};



// Testa as funções de parsers
int test_load_datasets (Database database, const char *directory, Tests tests) {

    // Declara os ficheiros
    FILE *read_files [N_DATASETS], *write_files [N_DATASETS];

    // Abre os ficheiros
    if (open_dataset_files (read_files, write_files, directory)) {
        destroy_database (database); destroy_tests (tests);
        return EXIT_FAILURE;
    }

    // Declara variáveis auxiliares