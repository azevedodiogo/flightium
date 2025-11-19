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

/**
 * @brief Cria a estrutura de armazenamento dos passageiros.
 * @param inicial_capacity Capacidade inicial pretendida.
 * @return Estrutura inicializada.
 */
StoragePassengers create_storage_passengers (int inicial_capacity);

/**
 * @brief Liberta todos os recursos associados aos passageiros.
 * @param storage_passengers Estrutura a eliminar.
 */
void destroy_storage_passengers (StoragePassengers storage_passengers);

/**
 * @brief Obtém um passageiro pelo número de documento.
 * @param storage_passengers Estrutura de armazenamento.
 * @param document_number Número de documento.
 * @param index Ponteiro onde é devolvido o índice interno do passageiro.
 * @return Registo correspondente ou NULL se não existir.
 */
const struct entity_passenger *get_passenger_by_id (StoragePassengers storage_passengers, int document_number);

/**
 * @brief Regista um novo passageiro.
 * @param storage_passengers Estrutura de armazenamento.
 * @param document_number Número de documento.
 * @param first_name Primeiro nome.
 * @param last_name Último nome.
 * @param nationality Nacionalidade.