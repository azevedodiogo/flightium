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
    QueryError query_error = g_malloc (sizeof (QUERY_ERROR));

    // Define as componentes do registo
    query_error -> query_num = query_num;
    query_error -> command_num = command_num;
    query_error -> error_line = NO_VALUE;
    query_error -> expected_line [0] = query_error -> actual_line [0] = 0;

    // Retorna o registo
    return query_error;
}

// Elimina um registo da entidade erro da query
void destroy_query_error (QueryError query_error) {
    g_free (query_error);
}

// Devolve o número da query de um erro
int get_query_error_number (QueryError query_error) {
    return query_error -> query_num;
}

// Devolve o número do comando de um erro
int get_query_error_command (QueryError query_error) {
    return query_error -> command_num;
}

// Devolve o número da linha de um erro
int get_query_error_line (QueryError query_error) {
    return query_error -> error_line;