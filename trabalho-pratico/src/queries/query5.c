#include "queries/queries.h"

#include "managers/airlines/entity_airline.h"
#include "managers/airlines/structure_airlines.h"
#include "managers/storage_generic.h"

#define LARGE_BUFFER 4096

// Executa a query 5
void execute_query5 (Database database, char *input, char *output, char del) {

    // Determina o argumento do input
    int N = atoi (input);

    // Declara o array de companhias aéreas encontradas
    const struct entity_airline *found [N];