#include "parsers/parser_main.h"

#include "utils/utility_functions.h"
#include "parsers/parser_definitions.h"

#define BUFFER 1024

// Funções de carregamento dos datasets
static int (*load_line [N_DATASETS]) (char *, Database) = {load_line_aircrafts, load_line_airports, load_line_passengers, load_line_flights, load_line_reservations};



// Abre os ficheiros dos datasets
int open_dataset_files (FILE *read_files [], FILE *write_files [], const char *directory) {

    // Declara os nomes dos ficheiros de leitura