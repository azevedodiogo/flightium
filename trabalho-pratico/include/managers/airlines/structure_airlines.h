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