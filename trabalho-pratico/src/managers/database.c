#include "managers/database.h"

#include "managers/aircrafts/structure_aircrafts.h"
#include "managers/airlines/structure_airlines.h"
#include "managers/airports/structure_airports.h"
#include "managers/flights/structure_flights.h"
#include "managers/passengers/structure_passengers.h"
#include "managers/reservations/structure_reservations.h"

#include <glib.h>

// Base de dados
typedef struct database {
    StorageAircrafts aircrafts;
    StorageAirlines airlines;
    StorageAirports airports;
    StorageFlights flights;
    StoragePassengers passengers;
    StorageReservations reservations;
} DATABASE, *Database;

// Tamanhos dos arrays
static const int size_aircrafts [] = {1000, 5000};
static const int size_airlines [] = {30, 30};
static const int size_airports [] = {7355, 7355};
static const int size_flights [] = {1108700, 5616628};
static const int size_passengers [] = {200000, 2000000};



// Cria a base de dados
Database create_database (int dataset) {

    // Aloca memória para a base de dados
    Database database = g_malloc (sizeof (DATABASE));

    // Cria as estruturas de armazenamento das entidades
    database -> aircrafts = create_storage_aircrafts (size_aircrafts [dataset]);
    database -> airlines = create_storage_airlines (size_airlines [dataset]);
    database -> airports = create_storage_airports (size_airports [dataset]);
    database -> flights = create_storage_flights (size_flights [dataset]);
    database -> passengers = create_storage_passengers (size_passengers [dataset]);
    database -> reservations = create_storage_reservations ();

    // Retorna a base de dados
    return database;
}

// Elimina a base de dados
void destroy_database (Database database) {

    // Elimina as estruturas de armazenamento das entidades
    destroy_storage_aircrafts (database -> aircrafts);
    destroy_storage_airlines (database -> airlines);
    destroy_storage_airports (database -> airports);
    destroy_storage_flights (database -> flights);
    destroy_storage_passengers (database -> passengers);
    destroy_storage_reservations (database -> reservations);

    // Elimina a base de dados
    g_free (database);
}

// Devolve a estrutura de armazenamento das aeronaves
StorageAircrafts get_database_aircrafts (Database database) {
    return database -> aircrafts;
}

// Devolve a estrutura de armazenamento das companhias
StorageAirlines get_database_airlines (Database database) {
    return database -> airlines;
}

// Devolve a estrutura de armazenamento dos aeroportos
StorageAirports get_database_airports (Database database) {
    return database -> airports;
}

// Devolve a estrutura de armazenamento dos voos
StorageFlights get_database_flights (Database database) {
    return database -> flights;
}

// Devolve a estrutura de armazenamento dos passageiros
StoragePassengers get_database_passengers (Database database) {
    return database -> passengers;
}

// Devolve a estrutura de armazenameto das reservas
StorageReservations get_database_reservations (Database database) {
    return database -> reservations;