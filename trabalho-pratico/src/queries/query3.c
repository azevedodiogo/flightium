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
    int min_date [3], max_date [3], max_count; determine_arguments_query3 (input, min_date, max_date);

    // Converte as datas
    date min = convert_date (min_date [0], min_date [1], min_date [2]);
    date max = convert_date (max_date [0], max_date [1], max_date [2]);

    // Determina o aeroporto com mais visitas durante o intervalo de tempo
    const struct entity_airport *airport = most_visited_airport_by_timespan (get_database_airports (database), min, max, &max_count);

    // Verifica se foi encontrado um aeroporto
    if (airport) {

        // Obtém as componentes do aeroporto
        const char *code = get_airport_code (airport);
        const char *name = get_airport_name (airport);