#include "managers/airports/structure_airports.h"

#include "managers/airports/entity_airport.h"
#include "managers/storage_generic.h"
#include "utils/date_functions.h"
#include "utils/utility_functions.h"

#define N_EXPECTED_NATIONALITIES 55
#define N_EXPECTED_DAYS 273

// Estrutura de armazenamento dos aeroportos
typedef struct storage_airports {
    StorageGeneric data;
    StorageGeneric matrix_nationalities;
    int **matrix_flights;
    int len_flights, offset_flights;
} STORAGE_AIRPORTS, *StorageAirports;



// Cria a estrutura de armazenamento dos aeroportos
StorageAirports create_storage_airports (int inicial_capacity) {

    // Aloca memória para a estrutura de armazenamento
    StorageAirports storage_airports = g_malloc (sizeof (STORAGE_AIRPORTS));

    // Cria as sub-estruturas de armazenamento
    storage_airports -> data = create_storage_generic (inicial_capacity, destroy_airport, 1);
    storage_airports -> matrix_nationalities = create_storage_generic (N_EXPECTED_NATIONALITIES, g_free, 1);
    storage_airports -> matrix_flights = g_malloc (N_EXPECTED_DAYS * sizeof (int *));
    storage_airports -> len_flights = N_EXPECTED_DAYS; storage_airports -> offset_flights = 0;

    // Cria a linha das matriz dos voos
    for (int i = 0; i < N_EXPECTED_DAYS; i++) storage_airports -> matrix_flights [i] = g_malloc0 (inicial_capacity * sizeof (int));

    // Retorna a estrutura de armazenamento
    return storage_airports;
}

// Elimina a estrutura de armazenamento dos aeroportos
void destroy_storage_airports (StorageAirports storage_airports) {

    // Elimina a linha das matriz dos voos
    for (int i = 0; i < storage_airports -> len_flights; i++) g_free (storage_airports -> matrix_flights [i]);

    // Elimina as sub-estruturas de armazenamento
    destroy_storage_generic (storage_airports -> data);
    destroy_storage_generic (storage_airports -> matrix_nationalities);
    g_free (storage_airports -> matrix_flights);

    // Elimina a estrutura de armazenamento
    g_free (storage_airports);
}

// Devolve um aeroporto a partir do seu código
const struct entity_airport *get_airport_by_id (StorageAirports storage_airports, const char *code) {
    return get_generic_by_id (storage_airports -> data, code);
}

// Adiciona um novo registo de um aeroporto
void register_airport (StorageAirports storage_airports, const char *code, const char *name, const char *city, const char *type, const char *country) {
    register_generic (storage_airports -> data, g_strdup (code), create_airport (code, name, city, type, country));
}

// Regista uma ocorrência do aeroporto na matriz dos voos
void register_airport_matrix_flights (StorageAirports storage_airports, int line, const char *origin) {

    // Verifica se a data é anteiror a 01-01-2025
    if (line < storage_airports -> offset_flights) {

        // Calcula variáveis auxiliares
        int diff = storage_airports -> offset_flights - line;
        int new_len = storage_airports -> len_flights + diff;

        // Aloca memória para a nova matriz
        int **new_matrix = g_malloc (new_len * sizeof (int *));

        // Inicializa as linhas novas
        for (int i = 0; i < diff; i++) new_matrix [i] = g_malloc0 (get_generic_len (storage_airports -> data) * sizeof (int));

        // Copia as linhas antigas
        memcpy (new_matrix + diff, storage_airports -> matrix_flights, storage_airports -> len_flights * sizeof (int *));

        // Define a nova matriz
        g_free (storage_airports -> matrix_flights);
        storage_airports -> matrix_flights = new_matrix;
        storage_airports -> len_flights = new_len;
        storage_airports -> offset_flights = line;
    }

    // Atualiza o contador
    storage_airports -> matrix_flights [line - storage_airports -> offset_flights][get_index (storage_airports -> data, origin)]++;
}

// Regista uma ocorrência do aeroporto na matriz das nacionalidades
void register_airport_matrix_nationalities (StorageAirports storage_airports, const char *code, const char *nationality) {

    // Obtém a data
    StorageGeneric data = storage_airports -> data;

    // Determina a coluna
    int column = get_index (data, code);

    // Obtém a linha
    int *line = get_generic_by_id (storage_airports -> matrix_nationalities, nationality);
    
    // Verifica se a linha ainda não existe
    if (line == NULL) {

        // Regista a nova linha
        register_generic (storage_airports -> matrix_nationalities, g_strdup (nationality), g_malloc0 (get_generic_len (data) * sizeof (int)));

        // Inicia o contador
        line = get_generic_by_index (storage_airports -> matrix_nationalities, get_generic_len (storage_airports -> matrix_nationalities) - 1);
        line [column] = 1;

    } else line [column]++;
}

// Atualiza os contadores dos aeroportos
void update_airports (StorageAirports storage_airports, const char *origin, const char *destination) {

    // Obtém a data
    StorageGeneric data = storage_airports -> data;

    // Determina os índices dos aeroportos
    int index_origin = get_index (data, origin);
    int index_destination = get_index (data, destination);

    // Atualiza os contadores dos aeroportos
    inc_airport_departure_count (get_generic_by_index (storage_airports -> data, index_origin));
    inc_airport_arrival_count (get_generic_by_index (storage_airports -> data, index_destination));
}

// Prepara a estrutura de armazenamento dos aeroportos para as queries
void prepare_airports (StorageAirports storage_airports) {

    // Obtém a matriz e o número de colunas
    int **matrix = storage_airports -> matrix_flights, len = get_generic_len (storage_airports -> data);

    // Torna a matriz numa matriz acumulada
    for (int i = 1; i < storage_airports -> len_flights; i++)
        for (int j = 0; j < len; j++)
            matrix [i][j] += matrix [i - 1][j];
}

// Encontra o máximo de uma linha de contadores de aeroportos (desempatando pelo código)
static int max_line_matrix_airports (StorageAirports storage_airports, int line [], int len, int *max_count) {

    // Informação sobre o máximo
    int max_index = 0; *max_count = line [0];
    const char *max_code = get_airport_code (get_generic_by_index (storage_airports -> data, 0));

    // Percorre a linha
    for (int i = 1; i < len; i++)
        if (line [i] > *max_count || (line [i] == *max_count && strcmp (max_code, get_airport_code (get_generic_by_index (storage_airports -> data, i))) > 0)) {
            max_index = i; *max_count = line [i]; max_code = get_airport_code (get_generic_by_index (storage_airports -> data, i));
        }

    // Retorna o índice encontrado
    return max_index;
}

// Determina o aeroporto mais visitado num intervalo de tempo
const struct entity_airport *most_visited_airport_by_timespan (StorageAirports storage_airports, date min_date, date max_date, int *max_count) {

    // Mínimo e máximo
    int min = days_since_jan_first (min_date), max = days_since_jan_first (max_date);

    // Verifica se o intervalo é inválido
    if (adjust_limits (storage_airports -> len_flights, storage_airports -> offset_flights, &min, &max)) return NULL;

    // Obtém a data
    StorageGeneric data = storage_airports -> data;

    // Determina o comprimento do array
    int len = get_generic_len (data), diff [len]; min--;

    // Calcula a linha diferença
    if (min > 0) for (int i = 0; i < len; i++) diff [i] = storage_airports -> matrix_flights [max][i] - storage_airports -> matrix_flights [min][i];

    // Encontra o máximo da linha
    return get_generic_by_index (storage_airports -> data, max_line_matrix_airports (storage_airports, min > 0 ? diff : storage_airports -> matrix_flights [max], len, max_count));
}

// Determina o aeroporto mais visitado por passageiros de uma determinada nacionalidade