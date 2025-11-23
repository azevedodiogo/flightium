#ifndef ENTITY_AIRLINE_H
#define ENTITY_AIRLINE_H

#include <glib.h>

/** @brief Entidade que representa uma companhia aérea. */
typedef struct entity_airline *EntityAirline;



/**
 * @brief Cria um registo de companhia aérea.
 * @param name Nome da companhia.
 * @param delay Valor inicial de atraso (em minutos).
 * @return Nova entidade.
 */
EntityAirline create_airline (const char *name, int delay);

/**
 * @brief Liberta a memória associada a uma companhia aérea.
 * @param airline Ponteiro para a entidade.
 */
void destroy_airline (gpointer airline);

/**
 * @brief Obtém o nome da companhia.
 * @param airline Registo alvo.
 * @return String com o nome da companhia.
 */
const char *get_airline_name (const struct entity_airline *airline);

/**
 * @brief Obtém o número de voos com atraso.
 * @param airline Registo alvo.
 * @return Contagem de atrasos.
 */
int get_airline_delay_count (const struct entity_airline *airline);

/**
 * @brief Obtém o atraso total acumulado.
 * @param airline Registo alvo.
 * @return Minutos totais de atraso.
 */
int get_airline_total_delay (const struct entity_airline *airline);

/**
 * @brief Atualiza as estatísticas de atraso da companhia.
 * @param airline Registo alvo.
 * @param delay Atraso a adicionar (pode também ser zero ou negativo se aplicável).
 */
void update_airline_delay (EntityAirline airline, int delay);

/**
 * @brief Compara duas companhias aéreas com base do seu atraso médio (ou lexicograficamente pelo nome em caso de empate).
 * @param airline1_pointer Ponteiro para a primeira companhia.
 * @param airline2_pointer Ponteiro para a segunda companhia.
 * @return Valor negativo, zero ou positivo segundo a ordenação definida.
 */
int compare_airlines (gconstpointer airline1_pointer, gconstpointer airline2_pointer);

#endif