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
    StorageAircrafts storage_aircrafts = g_malloc (sizeof (STORAGE_AIRCRAFTS));

    // Cria a sub-estrutura
    storage_aircrafts -> data = create_storage_generic (inicial_capacity, destroy_aircraft, 1);

    // Retorna a estrutura
    return storage_aircrafts;
}

// Elimina a estrutura de armazenamento das aeronaves
void destroy_storage_aircrafts (StorageAircrafts storage_aircrafts) {

    // Elimina a sub-estrutura
    destroy_storage_generic (storage_aircrafts -> data);

    // Elimina a estrutura
    g_free (storage_aircrafts);
}

// Devolve uma aeronave a partir do seu código
const struct entity_aircraft *get_aircraft_by_id (StorageAircrafts storage_aircrafts, const char *identifier) {
    return get_generic_by_id (storage_aircrafts -> data, identifier);
}

// Adiciona um novo registo de uma aeronave
void register_aircraft (StorageAircrafts storage_aircrafts, const char *identifier, const char *manufacturer, const char *model) {
    register_generic (storage_aircrafts -> data, g_strdup (identifier), create_aircraft (identifier, manufacturer, model));
}

// Verifica se uma aeronave está registada
int check_aircraft (StorageAircrafts storage_aircrafts, const char *identifier) {
    return get_index (storage_aircrafts -> data, identifier);
}

// Atualiza o número de voos de uma aeronave
void update_aircraft (StorageAircrafts storage_aircrafts, int index) {
    inc_aircraft_flight_count (get_generic_by_index (storage_aircrafts -> data, index));
}