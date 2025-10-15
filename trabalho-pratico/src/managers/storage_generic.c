#include "managers/storage_generic.h"

// Estrutura de armazenamento genérica
typedef struct storage_generic {
    gpointer *array;
    int len, capacity;
    GHashTable *indexing;