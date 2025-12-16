#include "queries/queries.h"

#include <glib.h>

#define BUFFER 1024
#define LARGE_BUFFER 4096

// Abre o ficheiro do input
int open_input_file (FILE **read_file, const char *read_file_name) {

    // Abre o ficheiro
    *read_file = fopen (read_file_name, "r");

    // Verifica se o ficheiro não existe
    if (*read_file == NULL) {
        fprintf (stderr, "Error: invalid file\n");
        return EXIT_FAILURE;
    }

    // Indica que o ficheiro foi aberto corretamente
    return EXIT_SUCCESS;
}

// Executa as queries dadas
int execute_queries (Database database, const char *directory) {

    // Declara o ficheiro
    FILE *read_file;

    // Abre o ficheiro
    if (open_input_file (&read_file, directory)) {
        destroy_database (database);
        return EXIT_FAILURE;
    }

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

        // Realiza a query
        switch (input [0]) {
            case '1': execute_query1 (database, input + skips, output, delimiter); break;
            case '2': execute_query2 (database, input + skips, output, delimiter); break;
            case '3': execute_query3 (database, input + skips, output, delimiter); break;
            case '4': execute_query4 (database, input + skips, output, delimiter); break;
            case '5': execute_query5 (database, input + skips, output, delimiter); break;