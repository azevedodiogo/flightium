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
