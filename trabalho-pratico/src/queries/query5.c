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

    // Determina as N companhias aéreas com maior tempo de atraso médio
    int number_found = most_delayed_airlines (get_database_airlines (database), N, found);

    // Percorre o array até encontrar todas as aeronaves pretendidas
    for (int i = 0; i < number_found; i++) {

        // Determina o tamanho do output
        int len_output = *output == '\n' ? 0 : strlen (output);

        // Obtém as componentes da companhia aérea
        const char *name = get_airline_name (found [i]);
        int delay_count = get_airline_delay_count (found [i]);
        int total_delay = get_airline_total_delay (found [i]);
        double avg_delay = ((double) (total_delay)) / ((double) delay_count);
