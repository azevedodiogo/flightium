#include "managers/airports/structure_airports.h"

#include "managers/airports/entity_airport.h"
#include "managers/storage_generic.h"
#include "utils/date_functions.h"
#include "utils/utility_functions.h"

#define N_EXPECTED_NATIONALITIES 55
#define N_EXPECTED_DAYS 273

// Estrutura de armazenamento dos aeroportos
typedef struct storage_airports {
    StorageGeneric data;
    StorageGeneric matrix_nationalities;
    int **matrix_flights;
    int len_flights, offset_flights;
} STORAGE_AIRPORTS, *StorageAirports;



// Cria a estrutura de armazenamento dos aeroportos
StorageAirports create_storage_airports (int inicial_capacity) {

    // Aloca memória para a estrutura de armazenamento
    StorageAirports storage_airports = g_malloc (sizeof (STORAGE_AIRPORTS));

    // Cria as sub-estruturas de armazenamento
    storage_airports -> data = create_storage_generic (inicial_capacity, destroy_airport, 1);
    storage_airports -> matrix_nationalities = create_storage_generic (N_EXPECTED_NATIONALITIES, g_free, 1);
    storage_airports -> matrix_flights = g_malloc (N_EXPECTED_DAYS * sizeof (int *));
    storage_airports -> len_flights = N_EXPECTED_DAYS; storage_airports -> offset_flights = 0;

    // Cria a linha das matriz dos voos
    for (int i = 0; i < N_EXPECTED_DAYS; i++) storage_airports -> matrix_flights [i] = g_malloc0 (inicial_capacity * sizeof (int));

    // Retorna a estrutura de armazenamento
    return storage_airports;
}

// Elimina a estrutura de armazenamento dos aeroportos