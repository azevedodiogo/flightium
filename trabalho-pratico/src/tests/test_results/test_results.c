#include "tests/test_results/test_results.h"

#include "tests/test_results/load_timer.h"
#include "tests/test_results/query_errors.h"
#include "tests/test_results/query_results.h"

// Estrutura de armazenamento dos testes
typedef struct tests {
    LoadTimer load_timer;
    StorageQueryErrors errors;
    StorageQueryResults results;
} TESTS, *Tests;



// Cria a estrutura de armazenamento dos testes