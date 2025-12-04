#ifndef LOAD_TIMER_H
#define LOAD_TIMER_H

#include <glib.h>

/** @brief Estrutura usada para medir tempos de carregamento de datasets. */
typedef struct load_timer *LoadTimer;



/**
 * @brief Cria a estrutura de temporização.
 * @return Estrutura inicializada ou NULL em caso de falha.
 */
LoadTimer create_load_timer ();

/**
 * @brief Liberta os recursos associados ao temporizador.
 * @param load_timer Estrutura a eliminar.
 */
void destroy_load_timer (LoadTimer load_timer);

/**