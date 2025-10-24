#include "managers/airlines/structure_airlines.h"
#include "managers/airlines/entity_airline.h"
#include "managers/storage_generic.h"

// Estrutura de armazenamento das companhias aéreas
typedef struct storage_airlines {
    StorageGeneric data;
} STORAGE_AIRLINES, *StorageAirlines;



// Cria a estrutura de armazenamento das companhias aéreas
StorageAirlines create_storage_airlines (int inicial_capacity) {

    // Aloca memória para a estrutura