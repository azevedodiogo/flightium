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