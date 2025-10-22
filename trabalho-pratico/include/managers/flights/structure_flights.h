#ifndef STRUCTURE_FLIGHTS_H
#define STRUCTURE_FLIGHTS_H

#include "utils/date_functions.h"

/** @brief Estrutura de armazenamento dos voos. */
typedef struct storage_flights *StorageFlights;

/** @brief Entidade do voo. */
typedef struct entity_flight *EntityFlight;



/**
 * @brief Cria a estrutura de armazenamento dos voos.
 * @param inicial_capacity Capacidade inicial pretendida.
 * @return Estrutura inicializada.
 */
StorageFlights create_storage_flights (int inicial_capacity);

/**
 * @brief Liberta todos os recursos associados aos voos.
 * @param storage_flights Estrutura a eliminar.
 */
void destroy_storage_flights (StorageFlights storage_flights);

/**
 * @brief Obtém um voo a partir do seu identificador.
 * @param storage_flights Estrutura de armazenamento.
 * @param flight_id Identificador do voo.