#include "managers/database.h"
#include "parsers/parser_main.h"
#include "queries/queries.h"
#include "utils/utility_functions.h"

// Função principal
int main (int argc, char **argv) {

    // Verifica se não foram dados dois argumentos
    if (argc != 3) {
        fprintf (stderr, "Error: There should be two arguments\n");
        return EXIT_FAILURE;
    } int dataset;

    // Determina qual é o tipo de dataset
    if (determine_dataset (argv [1], &dataset)) {
        fprintf (stderr, "Error: invalid directory\n");
        return EXIT_FAILURE;
    }

    // Cria a base de dados
    Database database = create_database (dataset);

    // Carrega os datasets
    if (load_datasets (database, argv [1])) return EXIT_FAILURE;

    // Prepara a base de dados para as queries
    prepare_database (database);

    // Executa as queries