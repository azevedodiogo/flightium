#include "parsers/parser_flights.h"

#include "utils/date_functions.h"

#include <glib.h>

// Verifica se uma string representa corretamente 'N/A'
int validate_not_applicable (const char *string) {
    return strcmp (string, "N/A") == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}

// Verifica se as datas de um voo são válidas
int validate_flight_dates (const char status, date departure, date actual_departure, date arrival, date actual_arrival) {