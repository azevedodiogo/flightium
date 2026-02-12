#ifndef STRUCTURE_AIRLINES_H
#define STRUCTURE_AIRLINES_H

/** @brief Estrutura de armazenamento das companhias aéreas. */
typedef struct storage_airlines *StorageAirlines;

/** @brief Entidade da companhia aérea. */
typedef struct entity_airline *EntityAirline;



/**
 * @brief Cria a estrutura de armazenamento das companhias aéreas.
 * @param inicial_capacity Capacidade inicial pretendida.
 * @return Estrutura inicializada.
 */
StorageAirlines create_storage_airlines (int inicial_capacity);

/**
 * @brief Liberta todos os recursos associados à estrutura de companhias.
 * @param storage_airlines Estrutura a eliminar.
 */
void destroy_storage_airlines (StorageAirlines storage_airlines);

/**
 * @brief Obtém uma companhia aérea a partir do seu nome.
 * @param storage_airlines Estrutura de armazenamento.
 * @param name Nome da companhia.
 * @return Registo encontrado ou NULL se não existir.
 */
const struct entity_airline *get_airline_by_id (StorageAirlines storage_airlines, const char *name);

/**
 * @brief Regista uma nova companhia ou atualiza uma existente.
 * @param storage_airlines Estrutura de armazenamento.
 * @param name Nome da companhia aérea.
 * @param delay Atraso inicial associado.
 */
void register_airline (StorageAirlines storage_airlines, const char *name, int delay);

/**
 * @brief Prepara a estrutura para execução eficiente das queries.
 * @param storage_airlines Estrutura a preparar.
 */
void prepare_airlines (StorageAirlines storage_airlines);

/**
 * @brief Determina as N companhias com maior atraso médio.
 * @param storage_airlines Estrutura de armazenamento.
 * @param N Número de companhias pretendidas.
 * @param found Array de saída com as companhias mais atrasadas.
 * @return Número de registos colocados em `found`.
 */
int most_delayed_airlines (StorageAirlines storage_airlines, int N, const struct entity_airline *found []);

#endif