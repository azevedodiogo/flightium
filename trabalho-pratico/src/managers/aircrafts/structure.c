#include "managers/aircrafts/structure_aircrafts.h"
#include "managers/aircrafts/entity_aircraft.h"
#include "managers/storage_generic.h"

// Estrutura de armazenamento das aeronaves
typedef struct storage_aircrafts {
    StorageGeneric data;
} STORAGE_AIRCRAFTS, *StorageAircrafts;



// Cria a estrutura de armazenamento das aeronaves
StorageAircrafts create_storage_aircrafts (int inicial_capacity) {

    // Aloca memória para a estrutura