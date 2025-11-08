#include "managers/airports/entity_airport.h"

#include <string.h>

#define SIZE_COUNTRY 2

// Entidade do aeroporto
typedef struct entity_airport {
	char *code;
	char *name;
	char *city;
	char *type;
	unsigned short arrival_count;
	unsigned short departure_count;
	char country [SIZE_COUNTRY + 1];
} ENTITY_AIRPORT, *EntityAirport;



// Cria um registo da entidade aeroporto
EntityAirport create_airport (const char *code, const char *name, const char *city, const char *type, const char *country) {

	// Aloca memória para o registo
	EntityAirport airport = g_malloc (sizeof (ENTITY_AIRPORT));

	// Define as componentes do registo
	airport -> code = g_strdup (code);
	airport -> name = g_strdup (name);
	airport -> city = g_strdup (city);
	airport -> type = g_strdup (type);