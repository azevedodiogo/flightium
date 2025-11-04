#include "tests/test_results/load_timer.h"

#define N_DATASETS 5

// Estrutura para medir os tempos de leitura
typedef struct load_timer {
    double timers [N_DATASETS];