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