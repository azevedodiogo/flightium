#ifndef STRUCTURE_AIRPORTS_H
#define STRUCTURE_AIRPORTS_H

#include "utils/date_functions.h"

/** @brief Estrutura de armazenamento dos aeroportos. */
typedef struct storage_airports *StorageAirports;

/** @brief Entidade do aeroporto. */
typedef struct entity_airport *EntityAirport;



/**
 * @brief Cria a estrutura de armazenamento dos aeroportos.
 * @param inicial_capacity Capacidade inicial pretendida.
 * @return Estrutura inicializada.
 */
StorageAirports create_storage_airports (int inicial_capacity);

/**
 * @brief Liberta todos os recursos associados aos aeroportos.
 * @param storage_airports Estrutura a eliminar.