#define _POSIX_C_SOURCE 199309L

#include "queries/queries.h"
#include "utils/utility_functions.h"
#include "tests/test_results/test_results.h"
#include "tests/tests_parsers.h"
#include "tests/tests_queries.h"
#include "tests/tests_utils.h"

#include <sys/resource.h>
#include <stdio.h>

// Função principal
int main (int argc, char **argv) {

    // Declara variáveis de teste