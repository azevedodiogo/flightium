#include "queries/queries.h"

#include "managers/aircrafts/entity_aircraft.h"
#include "managers/aircrafts/structure_aircrafts.h"
#include "managers/storage_generic.h"

#define LARGE_BUFFER 4096

// Determina os argumentos do input da query 2
static int determine_arguments_query2 (char *input, char **manufacturer) {

    // Determina o número de aeronaves a encontrar
    int N = atoi (input);

    // Avança no input
    while (*input && *input != ' ') input++;

    // Verifica se foi dado um fabricante
    *manufacturer = *input ? input + 1 : NULL;

    // Retorna o número de aeronaves a encontrar
    return N;
}
