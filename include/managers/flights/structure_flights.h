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
 * @return Registo correspondente ou NULL se não existir.
 */
const struct entity_flight *get_flight_by_id (StorageFlights storage_flights, const char *flight_id);

/**
 * @brief Regista um novo voo na estrutura.
 * @param storage_flights Estrutura de armazenamento.
 * @param flight_id Identificador do voo.
 * @param origin Código do aeroporto de origem.
 * @param destination Código do aeroporto de destino.
 * @param week Semana do voo.
 * @param status Estado do voo.
 */
void register_flight (StorageFlights storage_flights, const char *flight_id, const char *origin, const char *destination, week_index week, char status);

#endif