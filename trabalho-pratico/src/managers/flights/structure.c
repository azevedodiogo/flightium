#include "managers/flights/structure_flights.h"

#include "managers/flights/entity_flight.h"
#include "managers/storage_generic.h"

// Estrutura de armazenamento dos voos
typedef struct storage_flights {
    StorageGeneric data;
} STORAGE_FLIGHTS, *StorageFlights;



// Cria a estrutura de armazenamento dos voos
StorageFlights create_storage_flights (int inicial_capacity) {

    // Aloca memória para a estrutura
    StorageFlights storage_flights = g_malloc (sizeof (STORAGE_FLIGHTS));

    // Cria a sub-estrutura
    storage_flights -> data = create_storage_generic (inicial_capacity, destroy_flight, 1);

    // Retorna a estrutura
    return storage_flights;
}

// Elimina a estrutura de armazenamento dos voos
void destroy_storage_flights (StorageFlights storage_flights) {

    // Elimina a sub-estrutura
    destroy_storage_generic (storage_flights -> data);

    // Elimina a estrutura
    g_free (storage_flights);
}

// Devolve um voo a partir do seu id