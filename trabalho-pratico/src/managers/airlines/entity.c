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
    g_free (temp -> name);
    g_free (temp);
}

// Devolve o nome de uma companhia aérea
const char *get_airline_name (const struct entity_airline *airline) {
    return airline -> name;
}

// Devolve o número de atrasos de uma companhia aérea
int get_airline_delay_count (const struct entity_airline *airline) {
    return airline -> delay_count;
}

// Devolve o atraso total de uma companhia aérea
int get_airline_total_delay (const struct entity_airline *airline) {
    return airline -> total_delay;
}

// Atualiza o atraso de uma companhia aérea
void update_airline_delay (EntityAirline airline, int delay) {

    // Incrementa o número de atrasos
    airline -> delay_count++;

    // Atualiza o atraso total
    airline -> total_delay += delay;
}

// Compara duas companhias aéreas
int compare_airlines (gconstpointer airline1_pointer, gconstpointer airline2_pointer) {