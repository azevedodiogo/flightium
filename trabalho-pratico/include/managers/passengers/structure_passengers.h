#ifndef STRUCTURE_PASSENGERS_H
#define STRUCTURE_PASSENGERS_H

#include "utils/date_functions.h"

/** @brief Estrutura de armazenamento dos passageiros. */
typedef struct storage_passengers *StoragePassengers;

/** @brief Entidade do passageiro. */
typedef struct entity_passenger *EntityPassenger;


// Há abstração das estruturas internas através de typedefs para ponteiros.
// Desta maneira, se houvesse necessidade de alterar alguma estrutura para outra, bastava mudar o ficheiro structure.c.
// O resto do programa continuaria a chamar a função get_passenger, sem saber que por trás aconteceu a troca de uma Hash Table para um Array. 