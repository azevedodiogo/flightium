#include "queries/queries.h"

#include "managers/airports/entity_airport.h"
#include "managers/airports/structure_airports.h"

#define LARGE_BUFFER 4096

// Executa a query 1
void execute_query1 (Database database, char *input, char *output, char del) {

    // Procura o aeroporto na estrutura de armazenamento
    const struct entity_airport *airport = get_airport_by_id (get_database_airports (database), input);

    // Verifica se o aeroporto existe
    if (airport) {

        // Obtém as componentes do aeroporto
        const char *name = get_airport_name (airport);
        const char *city = get_airport_city (airport);
        const char *country = get_airport_country (airport);
        const char *type = get_airport_type (airport);
        int arrival_count = get_airport_arrival_count (airport);
        int departure_count = get_airport_departure_count (airport);

        // Define o output
        g_snprintf (output, LARGE_BUFFER, "%s%c%s%c%s%c%s%c%s%c%d%c%d\n", input, del, name, del, city, del, country, del, type, del, arrival_count, del, departure_count);
    
    } else *output = '\n';
}