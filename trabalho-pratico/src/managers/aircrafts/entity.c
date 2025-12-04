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
    aircraft -> flight_count = 0;

    // Retorna o registo
    return aircraft;
}

// Elimina um registo da entidade aeronave
void destroy_aircraft (gpointer aircraft) {
    EntityAircraft temp = aircraft;
    g_free (temp -> identifier);
    g_free (temp -> manufacturer);
    g_free (temp -> model);
    g_free (temp);
}

// Devolve o identificador de uma aeronave
const char *get_aircraft_identifier (const struct entity_aircraft *aircraft) {
    return aircraft -> identifier;
}

// Devolve o fabricante de uma aeronave
const char *get_aircraft_manufacturer (const struct entity_aircraft *aircraft) {
    return aircraft -> manufacturer;
}

// Devolve o modelo de uma aeronave
const char *get_aircraft_model (const struct entity_aircraft *aircraft) {
    return aircraft -> model;
}

// Devolve o número de voos de uma aeronave