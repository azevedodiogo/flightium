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