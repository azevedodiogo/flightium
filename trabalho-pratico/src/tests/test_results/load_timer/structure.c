#include "tests/test_results/load_timer.h"

#define N_DATASETS 5

// Estrutura para medir os tempos de leitura
typedef struct load_timer {
    double timers [N_DATASETS];
} LOAD_TIMER, *LoadTimer;



// Cria os tempos de leitura
LoadTimer create_load_timer () {
    