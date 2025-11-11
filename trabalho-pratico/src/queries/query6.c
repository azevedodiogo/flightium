#include "queries/queries.h"

#include "managers/airports/entity_airport.h"
#include "managers/airports/structure_airports.h"

#define NO_VALUE -1
#define LARGE_BUFFER 4096

// Executa a query 6
void execute_query6 (Database database, char *input, char *output, char del) {

    // Número de visitas do aeroporto
    int arrival_count = NO_VALUE;

    // Determina o aeroporto mais visitado para passageiros da nacionalidade dada
    const struct entity_airport *airport = most_visited_airport_by_nationality (get_database_airports (database), input, &arrival_count);

    // Define o output
    if (airport) g_snprintf (output, LARGE_BUFFER, "%s%c%d\n", get_airport_code (airport), del, arrival_count);
    else *output = '\n';
}