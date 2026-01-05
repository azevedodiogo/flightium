#include "interactive_program/graphics.h"

#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define LARGE_BUFFER 4096



const char *plane_art[] = {
"__  _",
"\\ `/ |",
" \\__`!",
" / ,' `-.__________________",
"'-'\\_____              LI3 `-.",
"   <____()-=O=O=O=O=O=[]====--)",
"     `.___ ,-----,_______...-'",
"          /    .'",
"         /   .'",
"        /  .'",         
"        `-'",
NULL
};

const char *clouds_art[] = {
"          _  _",
"         ( `   )_",
"        (    )    `)",
"      (_   (_ .  _) _)",
"",
"                                     _",
"                                    (  )",
"                                 ( `  ) . )",
"                               (_, _(  ,_)_)",
NULL
};

const char *clock_art[] = {
"     Loading ...",

"        _____",
"     _.'_____`._",
"   .'.-'  12 `-.`.",
"  /,' 11      1 `.\\",    
" // 10      /   2 \\\\",  
";;         /       ::",
"|| 9  ----O      3 ||",
"::                 ;;",
" \\\\ 8           4 //",   
"  \\`. 7       5 ,'/",    
"   '.`-.__6__.-'.'",
"    ((-._____.-))",
"    _))       ((_",
NULL
};

// Desenha o ecrã inicial
void draw_plane_with_clouds () {

    // Auxiliares para o avião
    int plane_y = 10, plane_x = 50;

    // Auxiliares para as nuvens
    int cloud_y = plane_y - 5, cloud_x = plane_x + 10;

    // Desenha as nuvens
    for (int i = 0; clouds_art[i]; i++) mvprintw(cloud_y + i, cloud_x, "%s", clouds_art[i]);

    // Desenha o avião
    for (int i = 0; plane_art[i]; i++) mvprintw(plane_y + i, plane_x, "%s", plane_art[i]);
}

// Desenha o relógio
void draw_clock () {

    // Espera 200 ms antes de desenhar
    usleep (200 * 1000);

    // Auxiliares para o relógio
    int clock_y = 15, clock_x = 80;

    // Desenha o relógio
    for (int i = 0; clock_art[i]; i++) mvprintw(clock_y + i, clock_x, "%s", clock_art[i]);
    
    refresh ();
}

// Conta o número de quebras de linha numa string
int get_newlines (char text[]) {
    int newlines = 0;
    for (int i = 0; text[i] != '\0'; i++) if (text[i] == '\n') newlines++;
    return newlines;
}

// Imprime uma caixa com texto e um botão
void modal_start (char text[], const char button[], int width, int screen_y_max, int screen_x_max) {
    
    int key = 0;
    
    // Definições da janela
    int necessary_lines = get_newlines(text) + 1 + 4;  
    int posY = (screen_y_max - necessary_lines) / 2, posX = (screen_x_max - width) / 2;

    // Cria a janela centralizada
    WINDOW* window = newwin(necessary_lines, width, posY, posX);
    box(window, 0, 0); refresh();
    wrefresh(window); keypad(window, true);

    // Centraliza o texto
    int text_len = strlen(text);
    int text_x = (width - text_len) / 2;
    mvwprintw(window, necessary_lines / 2 - 1, text_x, "%s", text);

    // Centraliza o botão
    int button_x = (width - strlen(button)) / 2, button_y = necessary_lines - 2;
    wattron(window, COLOR_PAIR(2) | A_BOLD);
    mvwprintw(window, button_y, button_x, "%s", button);
    wattroff(window, COLOR_PAIR(2) | A_BOLD);

    // Fica à espera de ENTER
    while (key != 10) key = wgetch(window);

    // Destrói a janela
    wclear(window); wrefresh(window); delwin(window);
}

// Imprime uma caixa de input e lê o texto do utilizador
int text_input_box (int pos_y, int pos_x, int width, int input_size, char* text, char* input, int can_exit) {

    // Centraliza a janela
    if (can_exit && width < 32) {
        pos_x = pos_x + width / 2 - (32 / 2); width = 32;
    }
    pos_y -= 3;

    // Cria a janela de input
    WINDOW* window = newwin(6, width, pos_y, pos_x);

    box(window, 0, 0); refresh(); wrefresh(window);

    // Apresenta o texto da instrução
    wattron(window, COLOR_PAIR(1)); mvwprintw(window, 0, 2, "%s", text); wattroff(window, COLOR_PAIR(1));

    // Apresenta o prompt ">" para digitar
    mvwprintw(window, 3, 1, ">");

    // Apresenta a mensagem de instruções
    wattron(window, A_DIM);
    if (can_exit == 1) mvwprintw(window, 4, 1, "[ENTER] for default || [ESC] to Cancel");
    else if (can_exit == 2) mvwprintw(window, 4, 1, "[ESC] to Cancel");
    else mvwprintw(window, 4, 1, "[ENTER] Confirm");
    wattroff(window, A_DIM);

    // Mostra o cursor durante o input
    int cursor = 0, ch;
    wmove(window, 3, 3); curs_set(1);

    // Loop para ler cada tecla até ENTER ou tamanho máximo
    while ((ch = wgetch(window)) != '\n' && cursor < input_size - 1) {

        // Se o utilizador carregar no ESC, a janela fecha
        if (can_exit && ch == 27) {  