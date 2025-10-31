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