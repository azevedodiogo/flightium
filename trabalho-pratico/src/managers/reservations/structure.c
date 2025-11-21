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