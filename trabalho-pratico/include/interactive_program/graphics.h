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

/**
 * @brief Apresenta uma janela que exige interação do utilizador antes de continuar, centrado com texto e um único botão. Esta janela bloqueia a interface subjacente até o utilizador premir 'ENTER'.
 * @param text Conteúdo principal a mostrar.
 * @param button Texto do botão de confirmação.
 * @param width Largura da janela, em colunas.
 * @param screen_y_max Altura total disponível.
 * @param screen_x_max Largura total disponível.
 * @warning É estática até o utilizador premir 'ENTER'.
 */
void modal_start (char text[], const char button[], int width, int screen_y_max, int screen_x_max);

/**
 * @brief Apresenta uma caixa para introdução de texto e lê a entrada do utilizador.
 * @param pos_y Coordenada Y usada para centrar a caixa.
 * @param pos_x Coordenada X usada para centrar a caixa.
 * @param width Largura mínima desejada para a caixa, em colunas.
 * @param input_size Tamanho máximo do campo de entrada (inclui o terminador '\0').
 * @param text Mensagem de instrução apresentada no topo da caixa.
 * @param input Destino onde é guardada a entrada válida.
 * @param can_exit Define o comportamento da tecla ESC durante o programa interativo. 1 = anula e retorna 1. 0 = ignorada. 2 = Só cancela se houver texto na entrada.
 * @return 0 em caso de sucesso, 1 se o utilizador cancelar com ESC.
 * @warning Não valida o conteúdo; o chamador deve garantir que o buffer é suficiente e que o contexto ncurses está inicializado.
 */
int text_input_box (int pos_y, int pos_x, int width, int input_size, char* text, char* input, int can_exit);

/**
 * @brief Mostra uma janela com capacidade de scroll contendo a saída de uma query.
 * @param pos_y Coordenada Y do canto superior da janela.
 * @param pos_x Coordenada X do canto superior da janela.
 * @param width Largura da janela, em colunas.
 * @param height Altura da janela, em linhas.
 * @param title Título apresentado na moldura.
 * @param output Texto a apresentar, com linhas separadas por '\n'.