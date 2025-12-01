#include "parsers/parser_main.h"

#include "utils/utility_functions.h"
#include "parsers/parser_definitions.h"

#define BUFFER 1024

// Funções de carregamento dos datasets
static int (*load_line [N_DATASETS]) (char *, Database) = {load_line_aircrafts, load_line_airports, load_line_passengers, load_line_flights, load_line_reservations};



// Abre os ficheiros dos datasets
int open_dataset_files (FILE *read_files [], FILE *write_files [], const char *directory) {

    // Declara os nomes dos ficheiros de leitura
    char read_file_names [N_DATASETS][BUFFER];

    // Define os nomes dos ficheiros de leitura
    sprintf (read_file_names [N_AIRCRAFT], "%s/aircrafts.csv", directory);
    sprintf (read_file_names [N_AIRPORT], "%s/airports.csv", directory);
    sprintf (read_file_names [N_PASSENGER], "%s/passengers.csv", directory);
    sprintf (read_file_names [N_FLIGHT], "%s/flights.csv", directory);
    sprintf (read_file_names [N_RESERVATION], "%s/reservations.csv", directory);

    // Percorre o array de ficheiros de leitura
    for (int i = 0; i < N_DATASETS; i++) {

        // Abre o ficheiro
        read_files [i] = fopen (read_file_names [i], "r");

        // Verifica se o ficheiro não existe