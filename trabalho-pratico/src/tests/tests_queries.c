#define _POSIX_C_SOURCE 199309L

#include "tests/tests_queries.h"

#include "tests/tests_utils.h"
#include "tests/test_results/test_results.h"
#include "managers/database.h"
#include "queries/queries.h"

#include <stdio.h>
#include <sys/resource.h>

#define BUFFER 1024
#define LARGE_BUFFER 4096

// Executa as queries dadas