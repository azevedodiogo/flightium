#include "managers/reservations/structure_reservations.h"

#include <glib.h>

// Estrutura de armazenamento da entidade reserva
typedef struct storage_reservations {
    GHashTable *data;
} STORAGE_RESERVATIONS, *StorageReservations;