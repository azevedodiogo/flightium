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