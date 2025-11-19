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



// Cria um registo da entidade voo
EntityFlight create_flight (const char *origin, const char *destination, week_index week, char status) {

	// Aloca memória para o registo
	EntityFlight flight = g_malloc (sizeof (ENTITY_FLIGHT));

	// Define as componentes do registo
	strcpy (flight -> origin, origin);
	strcpy (flight -> destination, destination);
	flight -> week = week;
	flight -> status = status;

	// Retorna o registo
	return flight;
}

// Elimina um registo da entidade voo
void destroy_flight (gpointer flight) {
	g_free (flight);
}

// Devolve a origem de um voo
const char *get_flight_origin (const struct entity_flight *flight) {
	return flight -> origin;