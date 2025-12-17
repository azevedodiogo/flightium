#include "queries/queries.h"

#include "utils/date_functions.h"
#include "managers/passengers/entity_passenger.h"
#include "managers/passengers/structure_passengers.h"

#define NO_VALUE -1
#define LARGE_BUFFER 4096

// Determina os argumentos do input da query 4
static void determine_arguments_query4 (char *input, int min_date [3], int max_date [3]) {
    min_date [0] = atoi (input);
    min_date [1] = atoi (input + 5);
    min_date [2] = atoi (input + 8);
    max_date [0] = atoi (input + 11);
    max_date [1] = atoi (input + 16);
    max_date [2] = atoi (input + 19);
}

// Executa a query 4
void execute_query4 (Database database, char *input, char *output, char del) {

    // Limites das semanas a procurar
    int min_date [3] = {0}, max_date [3] = {0};

    // Determina os argumentos do input
    if (*input) determine_arguments_query4 (input, min_date, max_date);
    else {
        min_date [0] = 2000;
        max_date [0] = 2026;
    }

    // Converte as datas
    date min = convert_date (min_date [0], min_date [1], min_date [2]);
    date max = convert_date (max_date [0], max_date [1], max_date [2]);

    // Determina o passageiro que mais gastou entre as duas semanas