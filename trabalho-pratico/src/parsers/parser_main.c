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
        if (read_files [i] == NULL) {
            while (i--) fclose (read_files [i]);
            // fprintf (stderr, "Error: invalid directory\n");
            return EXIT_FAILURE;
        }
    }

    // Abre os ficheiros de escrita
    write_files [N_AIRCRAFT] = fopen ("resultados/aircrafts_errors.csv", "w");
    write_files [N_AIRPORT] = fopen ("resultados/airports_errors.csv", "w");
    write_files [N_PASSENGER] = fopen ("resultados/passengers_errors.csv", "w");
    write_files [N_FLIGHT] = fopen ("resultados/flights_errors.csv", "w");
    write_files [N_RESERVATION] = fopen ("resultados/reservations_errors.csv", "w");

    // Indica que os ficheiros foram abertos corretamente
    return EXIT_SUCCESS;
}

// Carrega os datasets
int load_datasets (Database database, const char *directory) {

    // Declara os ficheiros
    FILE *read_files [N_DATASETS], *write_files [N_DATASETS];

    // Abre os ficheiros
    if (open_dataset_files (read_files, write_files, directory)) {
        destroy_database (database);
        return EXIT_FAILURE;
    }

    // Declara o input
    char input [BUFFER];

    // Processa cada dataset
    for (int i = 0; i < N_DATASETS; i++) {

        // Processa o dataset
        generic_load_dataset (read_files [i], write_files [i], input, database, load_line [i]);

        // Fecha os ficheiros
        fclose (read_files [i]); fclose (write_files [i]);
    }

    // Indica que a função correu corretamente
    return EXIT_SUCCESS;
}

// Carrega um dataset genérico
void generic_load_dataset (FILE *read_file, FILE *write_file, char *input, Database database, int (*load_line) (char *, Database)) {

    // Lê a primeira linha
    if (fgets (input, BUFFER * sizeof (char), read_file)) fprintf (write_file, "%s", input);

    // Lê o ficheiro linha a linha
    while (fgets (input, BUFFER * sizeof (char), read_file)) {
        