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

    // Verifica se o primeiro voo não existe
    if (*flight_outbound == NULL) return EXIT_FAILURE;

    // Verifica se o último caractere do bloco é o fim da lista - ']'
    if (string [0] == ']') return EXIT_SUCCESS;

    // Lê o segundo id de voo
    *flight_return = get_flight_by_id (storage_flights, separate_block (&string, 39));

    // Verifica se o último caractere do bloco não é o fim da lista - ']'
    return (string [0] != ']') ? EXIT_FAILURE : EXIT_SUCCESS;
}

// Atualiza a base de dados para uma reserva
static void update_database_reservation (Database database, const struct entity_flight *flight_outbound, const struct entity_flight *flight_return, const char *nationality, int document_number, int price) {

    // Adiciona o registo do gasto
    register_spending (get_database_passengers (database), get_flight_week (flight_outbound), document_number, price);

    // Obtém as estruturas de armazenamento necessárias
    StorageAirports airports = get_database_airports (database);

    // Atualiza os aeroportos e as nacionalidades
    if (get_flight_status (flight_outbound) != 'C') {
        update_airports (airports, get_flight_origin (flight_outbound), get_flight_destination (flight_outbound));
        register_airport_matrix_nationalities (airports, get_flight_destination (flight_outbound), nationality);
    } if (flight_return && get_flight_status (flight_return) != 'C') {
        update_airports (airports, get_flight_origin (flight_return), get_flight_destination (flight_return));
        register_airport_matrix_nationalities (airports, get_flight_destination (flight_return), nationality);
    }
}
