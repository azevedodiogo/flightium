#ifndef DATABASE_H
#define DATABASE_H

/**
 * @brief Estrutura opaca que agrega todas as entidades do sistema.
 */
typedef struct database *Database;

/** @brief Estrutura de armazenamento das aeronaves. */
typedef struct storage_aircrafts *StorageAircrafts;

/** @brief Estrutura de armazenamento das companhias aéreas. */
typedef struct storage_airlines *StorageAirlines;

/** @brief Estrutura de armazenamento dos aeroportos. */
typedef struct storage_airports *StorageAirports;