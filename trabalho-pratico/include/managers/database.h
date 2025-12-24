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
 * @warning O chamador deve libertar a estrutura com `destroy_database()`. Qualquer acesso após a destruição é comportamento indefinido.
 */
Database create_database (int dataset);

/**
 * @brief Liberta todos os recursos associados à base de dados.
 * @param database Estrutura a destruir.
 * @warning Invalida todos os ponteiros devolvidos pelos getters. A instância não deve ser reutilizada depois de destruída.
 */
void destroy_database (Database database);

/**
 * @brief Obtém a estrutura de armazenamento das aeronaves.
 * @param database Base de dados em utilização.
 * @return Ponteiro para a estrutura interna de aeronaves.
 * @warning O ponteiro refere-se a dados internos da base de dados e deixa de ser válido após `destroy_database()`.
 */
StorageAircrafts get_database_aircrafts (Database database);

/**
 * @brief Obtém a estrutura de armazenamento das companhias aéreas.
 * @param database Base de dados em utilização.
 * @return Ponteiro para a estrutura interna de companhias aéreas.
 * @warning O ponteiro refere-se a dados internos da base de dados e deixa de ser válido após `destroy_database()`.
 */
StorageAirlines get_database_airlines (Database database);

/**
 * @brief Obtém a estrutura de armazenamento dos aeroportos.
 * @param database Base de dados em utilização.
 * @return Ponteiro para a estrutura interna de aeroportos.
 * @warning O ponteiro refere-se a dados internos da base de dados e deixa de ser válido após `destroy_database()`.
 */
StorageAirports get_database_airports (Database database);

/**
 * @brief Obtém a estrutura de armazenamento dos voos.
 * @param database Base de dados em utilização.
 * @return Ponteiro para a estrutura interna de voos.
 * @warning O ponteiro refere-se a dados internos da base de dados e deixa de ser válido após `destroy_database()`.
 */
StorageFlights get_database_flights (Database database);

/**
 * @brief Obtém a estrutura de armazenamento dos passageiros.
 * @param database Base de dados em utilização.
 * @return Ponteiro para a estrutura interna de passageiros.
 * @warning O ponteiro refere-se a dados internos da base de dados e deixa de ser válido após `destroy_database()`.
 */
StoragePassengers get_database_passengers (Database database);

/**
 * @brief Obtém a estrutura de armazenamento das reservas.
 * @param database Base de dados em utilização.
 * @return Ponteiro para a estrutura interna de reservas.
 * @warning Ponteiro não é de posse do chamador; fica inválido após `destroy_database()`.
 */