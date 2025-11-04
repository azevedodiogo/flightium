#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <ncurses.h>

/**
 * @brief Desenha o ecrã inicial com elementos gráficos, neste caso um avião e as nuvens.
 * @warning Requer que o ncurses esteja inicializado e o suporte a cores (start_color()) ativado.