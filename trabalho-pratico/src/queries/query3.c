#include "queries/queries.h"

#include "utils/date_functions.h"
#include "managers/airports/entity_airport.h"
#include "managers/airports/structure_airports.h"

#define NO_VALUE -1
#define LARGE_BUFFER 4096

// Determina os argumentos do input da query 3
static void determine_arguments_query3 (char *input, int min_date [3], int max_date [3]) {
    min_date [0] = atoi (input);
    min_date [1] = atoi (input + 5);
    min_date [2] = atoi (input + 8);
    max_date [0] = atoi (input + 11);
    max_date [1] = atoi (input + 16);
    max_date [2] = atoi (input + 19);
}

// Executa a query 3
void execute_query3 (Database database, char *input, char *output, char del) {

    // Determina os argumentos do input