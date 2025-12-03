#include "tests/test_results/load_timer.h"

#define N_DATASETS 5

// Estrutura para medir os tempos de leitura
typedef struct load_timer {
    double timers [N_DATASETS];
} LOAD_TIMER, *LoadTimer;



// Cria os tempos de leitura
LoadTimer create_load_timer () {
    
    // Aloca memória para a estrutura
    LoadTimer load_timer = g_malloc0 (sizeof (LOAD_TIMER));

    // Retorna a estrutura
    return load_timer;
}

// Elimina os tempos de leitura
void destroy_load_timer (LoadTimer load_timer) {
    if (load_timer) g_free (load_timer); 
}

// Devolve o tempo de leitura de um dataset
double get_dataset_time (const LoadTimer load_timer, int index) {
    return load_timer -> timers [index];
}

// Define o tempo de leitura de um dataset
void set_dataset_time (LoadTimer load_timer, int index, double time) {
    load_timer -> timers [index] = time;
}