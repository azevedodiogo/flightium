#include "parsers/parser_flights.h"

#include "utils/utility_functions.h"
#include "managers/aircrafts/entity_aircraft.h"
#include "managers/aircrafts/structure_aircrafts.h"
#include "managers/airlines/structure_airlines.h"
#include "managers/airports/structure_airports.h"
#include "managers/flights/structure_flights.h"
#include "parsers/general_validations.h"

#define NO_VALUE -1

// Carrega uma linha do dataset dos voos
int load_line_flights (char *input, Database database) {

    // Carrega o id de voo
    char *flight_id = separate_block (&input, '"');
    if (validate_flight_id (flight_id)) return EXIT_FAILURE;

    // Carrega a data de partida
    date departure = validate_date (separate_block (&input, '"'), 1);
    if (departure == INVALID_DATE) return EXIT_FAILURE;

    // Carrega a data de partida real
    char *block = separate_block (&input, '"');
    date actual_departure = validate_date (block, 1);
    if (actual_departure == INVALID_DATE && validate_not_applicable (block)) return EXIT_FAILURE;

    // Carrega a data de chegada
    date arrival = validate_date (separate_block (&input, '"'), 1);
    if (arrival == INVALID_DATE) return EXIT_FAILURE;