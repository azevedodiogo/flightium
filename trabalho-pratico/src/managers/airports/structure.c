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
void destroy_storage_airports (StorageAirports storage_airports) {

    // Elimina a linha das matriz dos voos
    for (int i = 0; i < storage_airports -> len_flights; i++) g_free (storage_airports -> matrix_flights [i]);

    // Elimina as sub-estruturas de armazenamento
    destroy_storage_generic (storage_airports -> data);
    destroy_storage_generic (storage_airports -> matrix_nationalities);
    g_free (storage_airports -> matrix_flights);

    // Elimina a estrutura de armazenamento
    g_free (storage_airports);
}

// Devolve um aeroporto a partir do seu código
const struct entity_airport *get_airport_by_id (StorageAirports storage_airports, const char *code) {
    return get_generic_by_id (storage_airports -> data, code);
}

// Adiciona um novo registo de um aeroporto
void register_airport (StorageAirports storage_airports, const char *code, const char *name, const char *city, const char *type, const char *country) {
    register_generic (storage_airports -> data, g_strdup (code), create_airport (code, name, city, type, country));
}

// Regista uma ocorrência do aeroporto na matriz dos voos
void register_airport_matrix_flights (StorageAirports storage_airports, int line, const char *origin) {

    // Verifica se a data é anteiror a 01-01-2025
    if (line < storage_airports -> offset_flights) {

        // Calcula variáveis auxiliares
        int diff = storage_airports -> offset_flights - line;
        int new_len = storage_airports -> len_flights + diff;

        // Aloca memória para a nova matriz
        int **new_matrix = g_malloc (new_len * sizeof (int *));

        // Inicializa as linhas novas
        for (int i = 0; i < diff; i++) new_matrix [i] = g_malloc0 (get_generic_len (storage_airports -> data) * sizeof (int));

        // Copia as linhas antigas