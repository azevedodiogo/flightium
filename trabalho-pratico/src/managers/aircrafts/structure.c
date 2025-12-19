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

// Prepara a estrutura de armazenamento das aeronaves para as queries
void prepare_aircrafts (StorageAircrafts storage_aircrafts) {
    sort_generic_structure (storage_aircrafts -> data, compare_aircrafts);
}

// Determina as N aeronaves com mais voos para um dado fabricante (opcional)
int determine_most_flown_aircrafts_by_manufacturer (StorageAircrafts storage_aircrafts, const char *wanted_manufacturer, int N, const struct entity_aircraft *found []) {

    // Obtém a data
    StorageGeneric data = storage_aircrafts -> data;

    // Obtém o número de elementos da estrutura
    int len = get_generic_len (data), number_found = 0;

    // Percorre o array até encontrar todas as aeronaves pretendidas
    for (int i = 0; number_found < N && i < len; i++) {

        // Obtém o elemento do array
        const struct entity_aircraft *aircraft = get_generic_by_index (data, i);

        // Obtém o fabricante da aeronave
        const char *manufacturer = get_aircraft_manufacturer (aircraft);

        // Verifica se a aeronave possui o fabricante desejado
        if (wanted_manufacturer == NULL || strcmp (wanted_manufacturer, manufacturer) == 0) found [number_found++] = aircraft;
    }

    // Retorna o array
    return number_found;
}