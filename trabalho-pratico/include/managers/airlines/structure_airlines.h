#ifndef STRUCTURE_AIRLINES_H
#define STRUCTURE_AIRLINES_H

/** @brief Estrutura de armazenamento das companhias aéreas. */
typedef struct storage_airlines *StorageAirlines;

/** @brief Entidade da companhia aérea. */
typedef struct entity_airline *EntityAirline;



/**
 * @brief Cria a estrutura de armazenamento das companhias aéreas.
 * @param inicial_capacity Capacidade inicial pretendida.
 * @return Estrutura inicializada.
 */
StorageAirlines create_storage_airlines (int inicial_capacity);

/**
 * @brief Liberta todos os recursos associados à estrutura de companhias.
 * @param storage_airlines Estrutura a eliminar.
 */
void destroy_storage_airlines (StorageAirlines storage_airlines);
