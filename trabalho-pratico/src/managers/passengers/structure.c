#include "managers/passengers/structure_passengers.h"

#include "managers/passengers/entity_passenger.h"
#include "managers/storage_generic.h"
#include "utils/utility_functions.h"
#include "utils/date_functions.h"

#define EXPECTED_WEEKS 38
#define EXPECTED_RESERVATIONS_PER_WEEK 600

// Entidade do gasto
typedef struct spending {
    int index;
    int price;
} Spending;

// Informação sobre os gastos de uma semana
typedef struct weekly_spendings {
    GArray *array;
    int top10 [10];
    int top10_len;
} WeeklySpendings;

// Estrutura de armazenamento dos passageiros
typedef struct storage_passengers {
    StorageGeneric data;
    WeeklySpendings *weekly_spendings;
    int len, offset;
} STORAGE_PASSENGERS, *StoragePassengers;



// Cria a estrutura de armazenamento dos passageiros
StoragePassengers create_storage_passengers (int inicial_capacity) {

    // Aloca memória para a estrutura
    StoragePassengers storage_passengers = g_malloc (sizeof (STORAGE_PASSENGERS));

    // Cria as sub-estruturas
    storage_passengers -> data = create_storage_generic (inicial_capacity, destroy_passenger, 0);
    storage_passengers -> weekly_spendings = g_malloc0 (EXPECTED_WEEKS * sizeof (WeeklySpendings));
    for (int i = 0; i < EXPECTED_WEEKS; i++) storage_passengers -> weekly_spendings [i].array = g_array_sized_new (FALSE, FALSE, sizeof (Spending), (inicial_capacity > 1000000 ? 200 : 1) * EXPECTED_RESERVATIONS_PER_WEEK);
    storage_passengers -> len = EXPECTED_WEEKS; storage_passengers -> offset = 0;

    // Retorna a estrutura
    return storage_passengers;
}

// Elimina a estrutura de armazenamento dos passageiros
void destroy_storage_passengers (StoragePassengers storage_passengers) {

    // Elimina as sub-estruturas
    for (int i = 0; i < storage_passengers -> len; i++) g_array_free (storage_passengers -> weekly_spendings [i].array, TRUE);
    g_free (storage_passengers -> weekly_spendings);
    destroy_storage_generic (storage_passengers -> data);

    // Elimina a estrutura
    g_free (storage_passengers);
}

// Devolve um passageiro a partir do seu número de documento
const struct entity_passenger *get_passenger_by_id (StoragePassengers storage_passengers, int document_number) {

    // Determina o índice da ocorrência do registo
    int index = get_index (storage_passengers -> data, GINT_TO_POINTER (document_number));

    // Retorna o registo
    return index == INVALID_INDEX ? NULL : get_generic_by_index (storage_passengers -> data, index);
}

// Adiciona um novo registo de um passageiro
void register_passenger (StoragePassengers storage_passengers, int document_number, const char *first_name, const char *last_name, const char *nationality, date dob) {
    register_generic (storage_passengers -> data, GINT_TO_POINTER (document_number), create_passenger (first_name, last_name, nationality, document_number, dob));
}

// Adiciona um novo registo de um gasto
void register_spending (StoragePassengers storage_passengers, int line, int document_number, int price) {

    // Cria o gasto
    Spending spending = (Spending) {get_index (storage_passengers -> data, GINT_TO_POINTER (document_number)), price};

    // Verifica se a data é inferior a 01-01-2025
    if (line < storage_passengers -> offset) {

        // Calcula variáveis auxiliares
        int diff = storage_passengers -> offset - line;
        int new_len = storage_passengers -> len + diff;

        // Aloca memória para o novo array
        WeeklySpendings *new_array = g_malloc0 (new_len * sizeof (WeeklySpendings));

        // Cria os novos arrays
        for (int i = 0; i < diff; i++) new_array [i].array = g_array_new (FALSE, FALSE, sizeof (Spending));

        // Copia os elementos antigos
        memcpy (new_array + diff, storage_passengers -> weekly_spendings, storage_passengers -> len * sizeof (WeeklySpendings));

        // Define a nova matriz
        g_free (storage_passengers -> weekly_spendings);
        storage_passengers -> weekly_spendings = new_array;
        storage_passengers -> len = new_len;
        storage_passengers -> offset = line;
    }

    // Adiciona o registo
    g_array_append_val (storage_passengers -> weekly_spendings [line - storage_passengers -> offset].array, spending);