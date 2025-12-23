#ifndef ENTITY_AIRCRAFT_H
#define ENTITY_AIRCRAFT_H

#include <glib.h>

/**
 * @brief Entidade que representa uma aeronave identificada pelo seu código.
 */
typedef struct entity_aircraft *EntityAircraft;



/**
 * @brief Cria um registo de aeronave.
 * @param identifier Código único da aeronave.
 * @param manufacturer Fabricante.
 * @param model Modelo específico.
 * @return Nova entidade aeronave.
 */
EntityAircraft create_aircraft (const char *identifier, const char *manufacturer, const char *model);

/**
 * @brief Liberta a memória associada a uma aeronave.
 * @param aircraft Ponteiro para a entidade a destruir.
 */
void destroy_aircraft (gpointer aircraft);

/**
 * @brief Obtém o identificador da aeronave.
 * @param aircraft Registo alvo.
 * @return String com o código da aeronave.
 */
const char *get_aircraft_identifier (const struct entity_aircraft *aircraft);

/**
 * @brief Obtém o fabricante da aeronave.
 * @param aircraft Registo alvo.
 * @return String com o fabricante.
 */
const char *get_aircraft_manufacturer (const struct entity_aircraft *aircraft);

/**
 * @brief Obtém o modelo da aeronave.
 * @param aircraft Registo alvo.
 * @return String com o modelo.
 */
const char *get_aircraft_model (const struct entity_aircraft *ircraft);

/**
 * @brief Devolve o número total de voos associados à aeronave.
 * @param aircraft Registo alvo.
 * @return Contagem de voos.
 */
unsigned short get_aircraft_flight_count (const struct entity_aircraft *aircraft);

/**
 * @brief Incrementa o contador de voos da aeronave.
 * @param aircraft Registo alvo a atualizar.
 */
void inc_aircraft_flight_count (EntityAircraft aircraft);

/**
 * @brief Compara duas aeronaves com base no seu número de voos (ou lexicograficamente pelo identificador em caso de empate).
 * @param aircraft1_pointer Ponteiro para a primeira aeronave.
 * @param aircraft2_pointer Ponteiro para a segunda aeronave.
 * @return Valor negativo, zero ou positivo conforme a ordem pretendida.
 */
int compare_aircrafts (gconstpointer aircraft1_pointer, gconstpointer aircraft2_pointer);

#endif