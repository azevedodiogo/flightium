#include "tests/tests_utils.h"

#include "tests/test_results/query_errors.h"
#include "tests/test_results/query_results.h"

#include <stdio.h>

#define NO_VALUE -1
#define TEST_ERROR 1
#define TEST_CORRECT 2
#define TEST_INCORRECT 3
#define BUFFER 1024

// Extrai uma linha específica do conteúdo de um ficheiro
static void extract_line_from_content (const char *content, int line_number, char *buffer) {

    // Contador da linha atual
    int current_line = 1, i = 0;
    
    // Percorre o conteúdo até encontrar a linha desejada ou chegar ao final
    while (*content && current_line < line_number) {
        if (*content == '\n') current_line++;
        content++;
    }