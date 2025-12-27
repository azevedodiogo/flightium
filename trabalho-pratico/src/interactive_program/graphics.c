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