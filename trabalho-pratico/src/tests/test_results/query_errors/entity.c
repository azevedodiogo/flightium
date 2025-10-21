#include "tests/test_results/query_errors.h"

#include <string.h>

#define NO_VALUE -1
#define BUFFER 1024

// Estrutura da entidade erro da query
typedef struct query_error {
    int query_num;
    int command_num;
    int error_line;
    char expected_line [BUFFER];   
    char actual_line [BUFFER];    
} QUERY_ERROR, *QueryError;



// Cria um registo da entidade erro da query
QueryError create_query_error (int query_num, int command_num) {

    // Aloca memória para o registo