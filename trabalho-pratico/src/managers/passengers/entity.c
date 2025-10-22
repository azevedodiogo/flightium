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