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

    // Aloca memória para o registo
    EntityAirline airline = g_malloc (sizeof (ENTITY_AIRLINE));

    // Define as componentes do registo
    airline -> name = g_strdup (name);
    airline -> delay_count = 1;
    airline -> total_delay = delay;

    // Retorna o registo
    return airline;
}

// Elimina um registo da entidade companhia aérea
void destroy_airline (gpointer airline) {
    EntityAirline temp = airline;