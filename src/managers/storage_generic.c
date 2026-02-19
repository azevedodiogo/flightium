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

    // Aloca memória para a estrutura de armazenamento
    StorageGeneric storage_generic = g_malloc (sizeof (STORAGE_GENERIC));

    // Define as componentes da estrutura
    storage_generic -> array = g_malloc (number_elements * sizeof (gpointer));
    storage_generic -> indexing = g_hash_table_new_full (flag ? g_str_hash : g_direct_hash, flag ? g_str_equal : g_direct_equal, flag ? g_free : NULL, NULL);
    storage_generic -> destroy_func = destroy_func;
    storage_generic -> len = 0; storage_generic -> capacity = number_elements;

    // Retorna a estrutura de armazenamento
    return storage_generic;
}

// Elimina uma estrutura de armazenamento genérica
void destroy_storage_generic (StorageGeneric storage_generic) {
    
    // Liberta as sub-estruturas de armazenamento
    for (int i = 0; i < storage_generic -> len; i++) storage_generic -> destroy_func (storage_generic -> array [i]);
    g_free (storage_generic -> array);
    g_hash_table_destroy (storage_generic -> indexing);

    // Liberta a estrutura de armazenamento
    g_free (storage_generic);
}

// Devolve o comprimento do array da estrutura de armazenamento genérica
int get_generic_len (StorageGeneric storage_generic) {
    return storage_generic -> len;
}

// Determina o índice do array a partir da sua indexação
int get_index (StorageGeneric storage_generic, gconstpointer key) {

    // Procura o registo
    gpointer index = g_hash_table_lookup (storage_generic -> indexing, key);

    // Retorna o índice
    return index ? GPOINTER_TO_INT (index) - 1 : INVALID_INDEX;
}

// Devolve um registo a partir do seu identificador
gpointer get_generic_by_id (StorageGeneric storage_generic, gconstpointer key) {

    // Determina o índice da ocorrência do registo
    int index = get_index (storage_generic, key);

    // Retorna o registo
    return index == INVALID_INDEX ? NULL : ((gpointer *) (storage_generic -> array)) [index];
}

// Devolve um elemento num índice do array
gpointer get_generic_by_index (StorageGeneric storage_generic, int index) {
    return (index < 0 || index >= storage_generic -> len) ? NULL : storage_generic -> array [index];
}

// Adiciona um novo registo na estrutura de armazenamento genérica
void register_generic (StorageGeneric storage_generic, gpointer key, gpointer value) {

    // Adiciona a indexação
    g_hash_table_insert (storage_generic -> indexing, key, GINT_TO_POINTER (storage_generic -> len + 1));

    // Verifica se é necessário realizar uma realocação
    if (storage_generic -> len == storage_generic -> capacity) {

        // Duplica a capacidade
        storage_generic -> capacity *= 1.5;

        // Realoca a memória
        storage_generic -> array = g_realloc (storage_generic -> array, storage_generic -> capacity * sizeof (gpointer));
    }

    // Adiciona o registo ao array
    storage_generic -> array [storage_generic -> len++] = value;
}

// Ordena a estrutura de armazenamento genérica
void sort_generic_structure (StorageGeneric storage_generic, GCompareFunc compare_func) {
    qsort (storage_generic -> array, storage_generic -> len, sizeof (gpointer), compare_func);
}