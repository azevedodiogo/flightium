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

/**
 * @brief Conta o número de quebras de linha numa sequência de texto.
 * @param text Sequência terminada por '\0' a inspecionar.
 * @return Número de caracteres '\n' encontrados.
 */
int get_newlines (char text[]);
