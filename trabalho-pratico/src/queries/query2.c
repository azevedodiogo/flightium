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

// Executa a query 2
void execute_query2 (Database database, char *input, char *output, char del) {

    // Determina os argumentos do input
    char *arg_manufacturer; int N = determine_arguments_query2 (input, &arg_manufacturer);

    // Declara o array de aeronaves encontradas
    const struct entity_aircraft *array [N];

    // Determina as N aeronaves com mais voos para o fabricante dados
    int number_found = determine_most_flown_aircrafts_by_manufacturer (get_database_aircrafts (database), arg_manufacturer, N, array);
    
    // Percorre o array para definir o output
    for (int i = 0; i < number_found; i++) {

        // Determina o tamanho atual do output
        int len_output = *output == '\n' ? 0 : strlen (output);

        // Obtém as componentes da aeronave
        const char *identifier = get_aircraft_identifier (array [i]);
        const char *manufacturer = get_aircraft_manufacturer (array [i]);
        const char *model = get_aircraft_model (array [i]);
        int flight_count = get_aircraft_flight_count (array [i]);
