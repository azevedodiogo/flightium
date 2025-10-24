#include "queries/queries.h"

#include "managers/airports/entity_airport.h"
#include "managers/airports/structure_airports.h"

#define LARGE_BUFFER 4096

// Executa a query 1
void execute_query1 (Database database, char *input, char *output, char del) {

    // Procura o aeroporto na estrutura de armazenamento
    const struct entity_airport *airport = get_airport_by_id (get_database_airports (database), input);

    // Verifica se o aeroporto existe