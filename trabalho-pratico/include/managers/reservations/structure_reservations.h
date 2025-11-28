#ifndef STRUCTURE_RESERVATIONS_H
#define STRUCTURE_RESERVATIONS_H

/** @brief Estrutura de armazenamento das reservas. */
typedef struct storage_reservations *StorageReservations;



/**
 * @brief Cria a estrutura de armazenamento das reservas.
 * @return Estrutura inicializada.
 */
StorageReservations create_storage_reservations ();

/**
 * @brief Liberta todos os recursos associados às reservas.
 * @param storage_reservations Estrutura a eliminar.
 */
void destroy_storage_reservations (StorageReservations storage_reservations);

/**