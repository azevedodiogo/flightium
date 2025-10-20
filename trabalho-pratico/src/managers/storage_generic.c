#include "managers/storage_generic.h"

// Estrutura de armazenamento genérica
typedef struct storage_generic {
    gpointer *array;
    int len, capacity;
    GHashTable *indexing;
    void (*destroy_func) (gpointer);
} STORAGE_GENERIC, *StorageGeneric;



// Cria uma estrutura de armazenamento genérica
StorageGeneric create_storage_generic (int number_elements, void (*destroy_func) (gpointer), int flag) {
