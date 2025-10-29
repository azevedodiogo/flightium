#include "queries/queries.h"

#include "managers/airports/entity_airport.h"
#include "managers/airports/structure_airports.h"

#define NO_VALUE -1
#define LARGE_BUFFER 4096

// Executa a query 6
void execute_query6 (Database database, char *input, char *output, char del) {

    // Número de visitas do aeroporto
    int arrival_count = NO_VALUE;
