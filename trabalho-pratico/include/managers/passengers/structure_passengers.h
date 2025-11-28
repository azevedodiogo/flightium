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
 * @param dob Data de nascimento (formato `date`).
 */
void register_passenger (StoragePassengers storage_passengers, int document_number, const char *first_name, const char *last_name, const char *nationality, date dob);

/**
 * @brief Regista um novo gasto associado a um passageiro.
 * @param storage_passengers Estrutura de armazenamento.
 * @param line Índice da linha do dataset.
 * @param index Índice interno do passageiro.
 * @param price Valor gasto a acumular.
 */
void register_spending (StoragePassengers storage_passengers, int line, int document_number, int price);

/**
 * @brief Prepara a estrutura de passageiros para execução eficiente de queries.
 * @param storage_passengers Estrutura a preparar.
 */
void prepare_passengers (StoragePassengers storage_passengers);

/**
 * @brief Determina o passageiro com maior despesa num intervalo de semanas.
 *
 * @param storage_passengers Estrutura de armazenamento de passageiros preparada.