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
static int validate_reservation_flights (char *string, gconstpointer *flight_outbound, gconstpointer *flight_return, gpointer storage_flights) {

    // Verifica se o primeiro caractere do bloco não é o início da lista - '['
    if (string [0] != '[') return EXIT_FAILURE;

    // Carrega o primeiro id de voo
    *flight_outbound = get_flight_by_id (storage_flights, separate_block (&string, 39));
