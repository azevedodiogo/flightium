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