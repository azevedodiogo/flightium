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

/** @brief Estrutura de armazenamento dos voos. */
typedef struct storage_flights *StorageFlights;

/** @brief Estrutura de armazenamento dos passageiros. */
typedef struct storage_passengers *StoragePassengers;

/** @brief Estrutura de armazenamento das reservas. */
typedef struct storage_reservations *StorageReservations;



/**
 * @brief Cria e inicializa a base de dados.
 * @param dataset Identificador do dataset a carregar (pode-se definir capacidades iniciais).
 * @return Estrutura `Database` pronta a receber dados.