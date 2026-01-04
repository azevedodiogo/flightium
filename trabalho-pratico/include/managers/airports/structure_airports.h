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
 * @param city Cidade.
 * @param type Tipo de aeroporto.
 * @param country País.
 */
void register_airport (StorageAirports storage_airports, const char *code, const char *name, const char *city, const char *type, const char *country);

/**
 * @brief Regista uma ocorrência do aeroporto na matriz de voos.
 * @param storage_airports Estrutura de armazenamento.
 * @param line Índice da linha no dataset.
 * @param origin Código do aeroporto de origem.
 */
void register_airport_matrix_flights (StorageAirports storage_airports, int line, const char *origin);

/**
 * @brief Regista uma ocorrência do aeroporto na matriz de nacionalidades.
 * @param storage_airports Estrutura de armazenamento.
 * @param code Código do aeroporto.
 * @param nationality Nacionalidade do passageiro associada ao registo.
 */
void register_airport_matrix_nationalities (StorageAirports storage_airports, const char *code, const char *nationality);

/**
 * @brief Atualiza contadores de chegadas e partidas entre dois aeroportos.
 * @param airports Estrutura de armazenamento.
 * @param origin Código do aeroporto de origem.
 * @param destination Código do aeroporto de destino.
 */
void update_airports (StorageAirports airports, const char *origin, const char *destination);

/**
 * @brief Prepara a estrutura de aeroportos para execução eficiente de queries.
 * @param storage_airports Estrutura a preparar.
 */
void prepare_airports (StorageAirports storage_airports);

/**
 * @brief Determina o aeroporto mais visitado num intervalo temporal.
 * @param storage_airports Estrutura de armazenamento.
 * @param min_date Data mínima.
 * @param max_date Data máxima.
 * @param max_count Ponteiro para armazenar o número máximo de visitas encontradas.
 * @return Registo do aeroporto mais visitado ou NULL se não existir.
 */
const struct entity_airport *most_visited_airport_by_timespan (StorageAirports storage_airports, date min_date, date max_date, int *max_count);

/**
 * @brief Determina o aeroporto mais visitado por passageiros de uma nacionalidade.
 * @param storage_airports Estrutura de armazenamento.
 * @param nationality Nacionalidade alvo.
 * @param arrival_count Ponteiro para guardar o número de chegadas encontradas.
 * @return Registo do aeroporto mais visitado ou NULL se não existir.
 */
const struct entity_airport *most_visited_airport_by_nationality (StorageAirports storage_airports, const char *nationality, int *arrival_count);

#endif