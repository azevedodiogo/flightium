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