#include "managers/aircrafts/entity_aircraft.h"

// Entidade da aeronave
typedef struct entity_aircraft {
    char *identifier;
    char *manufacturer;
    char *model;
    unsigned short flight_count;
} ENTITY_AIRCRAFT, *EntityAircraft;



// Cria um registo da entidade aeronave
EntityAircraft create_aircraft (const char *identifier, const char *manufacturer, const char *model) {

    // Aloca memória para o registo
    EntityAircraft aircraft = g_malloc (sizeof (ENTITY_AIRCRAFT));

    // Define as componentes do registo
    aircraft -> identifier = g_strdup (identifier);
    aircraft -> manufacturer = g_strdup (manufacturer);
    aircraft -> model = g_strdup (model);