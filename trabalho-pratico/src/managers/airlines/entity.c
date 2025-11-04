#include "managers/airlines/entity_airline.h"

#include <math.h>

// Entidade da companhia aérea
typedef struct entity_airline {
    char *name;
    int delay_count;
    int total_delay;
} ENTITY_AIRLINE, *EntityAirline;



// Cria um registo da entidade companhia aérea
EntityAirline create_airline (const char *name, int delay) {