#include "managers/flights/entity_flight.h"

#include <string.h>

#define SIZE_AIRPORT_PK 3

// Entidade do voo
typedef struct entity_flight {
	char origin [SIZE_AIRPORT_PK + 1];
	char destination [SIZE_AIRPORT_PK + 1];
	week_index week;
	char status;
} ENTITY_FLIGHT, *EntityFlight;


