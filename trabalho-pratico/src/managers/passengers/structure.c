#include "managers/passengers/structure_passengers.h"

#include "managers/passengers/entity_passenger.h"
#include "managers/storage_generic.h"
#include "utils/utility_functions.h"
#include "utils/date_functions.h"

#define EXPECTED_WEEKS 38
#define EXPECTED_RESERVATIONS_PER_WEEK 600

// Entidade do gasto
typedef struct spending {
    int index;
    int price;
} Spending;

// Informação sobre os gastos de uma semana
typedef struct weekly_spendings {
    GArray *array;
    int top10 [10];
    int top10_len;
} WeeklySpendings;

// Estrutura de armazenamento dos passageiros
typedef struct storage_passengers {
    StorageGeneric data;
    WeeklySpendings *weekly_spendings;
    int len, offset;
} STORAGE_PASSENGERS, *StoragePassengers;


