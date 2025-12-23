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
	airport -> arrival_count = 0;
	airport -> departure_count = 0;
	strcpy (airport -> country, country);

	// Retorna o registo
	return airport;
}

// Elimina um registo da entidade aeroporto
void destroy_airport (gpointer airport) {
	EntityAirport temp = airport;
	g_free (temp -> code);
	g_free (temp -> name);
	g_free (temp -> city);
	g_free (temp -> type);
	g_free (temp);
}

// Devolve o código de um aeroporto
const char *get_airport_code (const struct entity_airport *airport) {
	return airport -> code;
}

// Devolve o nome de um aeroporto
const char *get_airport_name (const struct entity_airport *airport) {
	return airport -> name;
}

// Devolve a cidade de um aeroporto
const char *get_airport_city (const struct entity_airport *airport) {
	return airport -> city;
}

// Devolve o tipo de um aeroporto
const char *get_airport_type (const struct entity_airport *airport) {
	return airport -> type;
}

// Devolve o número de chegadas de um aeroporto
unsigned short get_airport_arrival_count (const struct entity_airport *airport) {
	return airport -> arrival_count;
}

// Devolve o número de partidas de um aeroporto
unsigned short get_airport_departure_count (const struct entity_airport *airport) {
	return airport -> departure_count;
}

// Devolve o país de um aeroporto
const char *get_airport_country (const struct entity_airport *airport) {
	return airport -> country;
}

// Incrementa o número de chegadas de um aeroporto
void inc_airport_arrival_count (EntityAirport airport) {
	airport -> arrival_count++;
}

// Incrementa o número de partidas de um aeroporto
void inc_airport_departure_count (EntityAirport airport) {
	airport -> departure_count++;
}