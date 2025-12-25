#ifndef STRUCTURE_AIRCRAFTS_H
#define STRUCTURE_AIRCRAFTS_H

/** @brief Estrutura de armazenamento das aeronaves. */
typedef struct storage_aircrafts *StorageAircrafts;

/** @brief Entidade da aeronave. */
typedef struct entity_aircraft *EntityAircraft;



/**
 * @brief Cria a estrutura de armazenamento das aeronaves.
 * @param inicial_capacity Capacidade inicial pretendida para alocação.
 * @return Estrutura inicializada.
 */
StorageAircrafts create_storage_aircrafts (int inicial_capacity);

/**
 * @brief Liberta todos os recursos associados às aeronaves.
 * @param storage_aircrafts Estrutura a eliminar.
 */
void destroy_storage_aircrafts (StorageAircrafts storage_aircrafts);

/**
 * @brief Obtém uma aeronave a partir do seu identificador.
 * @param storage_aircrafts Estrutura de armazenamento.
 * @param identifier Código da aeronave.
 * @return Registo encontrado ou NULL se não existir.
 */
const struct entity_aircraft *get_aircraft_by_id (StorageAircrafts storage_aircrafts, const char *identifier);

/**
 * @brief Regista uma nova aeronave na estrutura.
 * @param storage_aircrafts Estrutura de armazenamento.
 * @param identifier Código único da aeronave.
 * @param manufacturer Fabricante.
 * @param model Modelo.
 */
void register_aircraft (StorageAircrafts storage_aircrafts, const char *identifier, const char *manufacturer, const char *model);

/**
 * @brief Verifica se uma aeronave está registada.
 * @param storage_aircrafts Estrutura de armazenamento.
 * @param index Código único da aeronave.
 * @return Índice da aeronave.
 */
int check_aircraft (StorageAircrafts storage_aircrafts, const char *identifier);

/**
 * @brief Atualiza o número de voos de uma aeronave.
 * @param storage_aircrafts Estrutura de armazenamento.
 * @param index Índice da aeronave.
 */
void update_aircraft (StorageAircrafts storage_aircrafts, int index);

/**
 * @brief Organiza as aeronaves para otimizar queries subsequentes.
 * @param storage_aircrafts Estrutura a preparar.
 */
void prepare_aircrafts (StorageAircrafts storage_aircrafts);

/**
 * @brief Determina as N aeronaves com mais voos para um fabricante.
 * @param storage_aircrafts Estrutura de armazenamento.
 * @param wanted_manufacturer Fabricante alvo.
 * @param N Número máximo de aeronaves pretendidas.
 * @param found Array de saída onde são colocados os registos encontrados.
 * @return Número de aeronaves guardadas no array `found`.
 */
int determine_most_flown_aircrafts_by_manufacturer (StorageAircrafts storage_aircrafts, const char *wanted_manufacturer, int N, const struct entity_aircraft *found []);

#endif