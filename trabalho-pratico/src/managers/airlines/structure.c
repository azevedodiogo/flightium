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
    StorageAirlines storage_airlines = g_malloc (sizeof (STORAGE_AIRLINES));

    // Cria a sub-estrutura
    storage_airlines -> data = create_storage_generic (inicial_capacity, destroy_airline, 1);

    // Retorna a estrutura
    return storage_airlines;
}

// Elimina a estrutura de armazenamento das companhias aéreas
void destroy_storage_airlines (StorageAirlines storage_airlines) {

    // Elimina a sub-estrutura
    destroy_storage_generic (storage_airlines -> data);
