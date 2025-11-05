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
