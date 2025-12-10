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

    // Elimina a estrutura
    g_free (storage_airlines);
}

// Devolve uma companhia aérea a partir do seu nome
const struct entity_airline *get_airline_by_id (StorageAirlines storage_airlines, const char *name) {
    return get_generic_by_id (storage_airlines -> data, name);
}

// Adiciona um novo registo de uma companhia
void register_airline (StorageAirlines storage_airlines, const char *name, int delay) {

    // Obtém a data
    StorageGeneric data = storage_airlines -> data;

    // Procura o índice da companhia aérea
    int index = get_index (data, name);

    // Verifica se a companhia aérea ainda não existia
    if (index == INVALID_INDEX) register_generic (data, g_strdup (name), create_airline (name, delay));

    // Atualiza a companhia aérea
    else update_airline_delay (get_generic_by_index (storage_airlines -> data, index), delay);
}

// Prepara a estrutura de armazenamento das companhias aéreas para as queries
void prepare_airlines (StorageAirlines storage_airlines) {
    sort_generic_structure (storage_airlines -> data, compare_airlines);
}

// Determina as N companhias aéreas com maior tempo de atraso médio
int most_delayed_airlines (StorageAirlines storage_airlines, int N, const struct entity_airline *found []) {

    // Obtém a data
    StorageGeneric data = storage_airlines -> data;

    // Obtém o número de elementos na estrutura genérica
    int len = get_generic_len (data), number_found = 0;

    // Percorre o array até encontrar todas as aeronaves pretendidas
    for (number_found = 0; number_found < N && number_found < len; number_found++) found [number_found] = get_generic_by_index (storage_airlines -> data, number_found);

    // Retorna o número de companhias aéreas encontradas
    return number_found;
}