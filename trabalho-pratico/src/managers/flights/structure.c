#include "managers/flights/structure_flights.h"

#include "managers/flights/entity_flight.h"
#include "managers/storage_generic.h"

// Estrutura de armazenamento dos voos
typedef struct storage_flights {
    StorageGeneric data;
} STORAGE_FLIGHTS, *StorageFlights;



// Cria a estrutura de armazenamento dos voos
StorageFlights create_storage_flights (int inicial_capacity) {