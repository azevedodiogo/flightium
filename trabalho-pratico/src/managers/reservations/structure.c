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