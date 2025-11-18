#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <ncurses.h>

/**
 * @brief Desenha o ecrã inicial com elementos gráficos, neste caso um avião e as nuvens.
 * @warning Requer que o ncurses esteja inicializado e o suporte a cores (start_color()) ativado.
 */
void draw_plane_with_clouds ();

/**
 * @brief Desenha um relógio de carregamento.
 * @warning Destinado a ecrãs de espera.
 */
void draw_clock ();