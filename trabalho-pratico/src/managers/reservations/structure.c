#include "managers/reservations/structure_reservations.h"

#include <glib.h>

// Estrutura de armazenamento da entidade reserva
typedef struct storage_reservations {
    GHashTable *data;
} STORAGE_RESERVATIONS, *StorageReservations;



// Cria a estrutura de armazenamento da entidade reserva
StorageReservations create_storage_reservations () {

    // Aloca memória para a estrutura
    StorageReservations storage_reservations = g_malloc (sizeof (STORAGE_RESERVATIONS));

    // Cria a sub-estrutura
    storage_reservations -> data = g_hash_table_new_full (g_direct_hash, g_direct_equal, NULL, NULL);

    // Retorna a estrutura
    return storage_reservations;
}

// Elimina a estrutura de armazenamento da entidade reserva
void destroy_storage_reservations (StorageReservations storage_reservations) {

    // Elimina a sub-estrutura
    g_hash_table_destroy (storage_reservations -> data);

    // Elimina a estrutura
    g_free (storage_reservations);
}

// Adiciona um registo da entidade reserva
int register_reservation (StorageReservations storage_reservations, int reservation_id) {

    // Obtém a data
    GHashTable *data = storage_reservations -> data;
    gpointer key = GINT_TO_POINTER (reservation_id);

    // Verifica se a reserva já existia
    if (g_hash_table_contains (data, key)) return EXIT_FAILURE;

    // Regista a reserva
    g_hash_table_add (storage_reservations -> data, GINT_TO_POINTER (reservation_id));

    // A reserva foi registada
    return EXIT_SUCCESS;
}