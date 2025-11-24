#include "managers/passengers/entity_passenger.h"

// Entidade do passageiro
typedef struct entity_passenger {
    char *first_name;
    char *last_name;
    char *nationality;
    int document_number;
    date dob;
} ENTITY_PASSENGER, *EntityPassenger;



// Cria a informação sobre um passageiro
EntityPassenger create_passenger (const char *first_name, const char *last_name, const char *nationality, int document_number, date dob) {

    // Aloca memória para o registo
    EntityPassenger passenger = g_malloc (sizeof (ENTITY_PASSENGER));

    // Define as componentes do registo
    passenger -> first_name = g_strdup (first_name);
    passenger -> last_name = g_strdup (last_name);
    passenger -> nationality = g_strdup (nationality);
    passenger -> document_number = document_number;
    passenger -> dob = dob;

    // Retorna o registo
    return passenger;
}

// Elimina aum registo da entidade passageiro
void destroy_passenger (gpointer passenger) {
    EntityPassenger temp = passenger;
    g_free (temp -> first_name);
    g_free (temp -> last_name);
    g_free (temp -> nationality);
    g_free (temp);
}

// Devolve o primeiro nome de um passageiro
const char *get_passenger_first_name (const struct entity_passenger *passenger) {
    return passenger -> first_name;
}

// Devolve o último nome de um passageiro
const char *get_passenger_last_name (const struct entity_passenger *passenger) {
    return passenger -> last_name;