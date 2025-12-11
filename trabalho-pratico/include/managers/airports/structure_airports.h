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
 */
void destroy_storage_airports (StorageAirports storage_airports);

/**
 * @brief Obtém um aeroporto a partir do seu código.
 * @param storage_airports Estrutura de armazenamento.
 * @param code Código do aeroporto.
 * @return Registo correspondente ou NULL se não existir.
 */
const struct entity_airport *get_airport_by_id (StorageAirports storage_airports, const char *code);

/**
 * @brief Regista um novo aeroporto na estrutura.
 * @param storage_airports Estrutura de armazenamento.
 * @param code Código do aeroporto.
 * @param name Nome do aeroporto.