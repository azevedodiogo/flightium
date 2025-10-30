#include "parsers/parser_reservations.h"

#include "utils/utility_functions.h"
#include "managers/airports/structure_airports.h"
#include "managers/flights/entity_flight.h"
#include "managers/flights/structure_flights.h"
#include "managers/passengers/entity_passenger.h"
#include "managers/passengers/structure_passengers.h"
#include "managers/reservations/structure_reservations.h"
#include "parsers/general_validations.h"

#include <math.h>

#define NO_VALUE -1

// Verifica se uma string representa corretamente uma lista de ids de voos