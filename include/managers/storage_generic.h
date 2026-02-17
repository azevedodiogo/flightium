#ifndef STORAGE_GENERIC_H
#define STORAGE_GENERIC_H

#include <glib.h>

/**
 * @brief Indica um índice inválido.
 */
#define INVALID_INDEX -1

/**
 * @brief Estrutura genérica de armazenamento indexado por chave.
 */
typedef struct storage_generic *StorageGeneric;



/**
 * @brief Aloca e prepara uma estrutura de armazenamento genérica indexada.
 * @param number_elements Capacidade inicial pretendida para o conjunto de registos.
 * @param destroy_func Função obrigatória responsável por libertar cada elemento quando a estrutura for destruída.
 * @param flag Parâmetro de configuração do modo de indexação (0 = hash direto, diferente de zero = hash de strings).
 * @return Estrutura inicializada ou NULL se a alocação falhar.
 * @warning `destroy_func` não pode ser NULL.
 */
StorageGeneric create_storage_generic (int number_elements, void (*destroy_func) (gpointer), int flag);

/**
 * @brief Liberta todos os recursos associados à estrutura genérica.
 * @param storage_generic Estrutura a destruir.
 * @warning Depois de invocada, todos os ponteiros obtidos pelos getters deixam de ser válidos. Os elementos são libertados através de `destroy_func`.
 */
void destroy_storage_generic (StorageGeneric storage_generic);

/**
 * @brief Devolve o número de elementos presentes na estrutura.
 * @param storage_generic Estrutura alvo.
 * @return Comprimento do array ativo.
 */
int get_generic_len (StorageGeneric storage_generic);

/**
 * @brief Determina o índice interno associado a uma chave.
 * @param storage_generic Estrutura alvo.
 * @param key Chave usada para indexação.
 * @return Índice calculado ou `INVALID_INDEX` caso não exista registo associado.
 */
int get_index (StorageGeneric storage_generic, gconstpointer key);

/**
 * @brief Obtém um registo a partir do seu identificador.
 * @param storage_generic Estrutura alvo.
 * @param key Chave de pesquisa.
 * @return Ponteiro para o registo correspondente ou NULL se inexistente.
 */
gpointer get_generic_by_id (StorageGeneric storage_generic, gconstpointer key);

/**
 * @brief Obtém um registo a partir do seu índice.
 * @param storage_generic Estrutura alvo.
 * @param index Índice de pesquisa.
 * @return NULL caso o índice esteja fora dos limites, o registo no índice dado caso contrário.
 */
gpointer get_generic_by_index (StorageGeneric storage_generic, int index);

/**
 * @brief Regista um novo elemento na estrutura genérica.
 * @param storage_generic Estrutura alvo.
 * @param key Chave identificadora do registo.
 * @param value Valor associado à chave.
 * @warning Chaves duplicadas não são validadas. Inserir a mesma chave sucessivas vezes substitui a referência anterior no índice.
 */
void register_generic (StorageGeneric storage_generic, gpointer key, gpointer value);

/**
 * @brief Ordena a estrutura de armazenamento genérica conforme a função de comparação.
 * @param storage_generic Estrutura alvo.
 * @param compare_func Função usada para comparar os elementos.
 * @warning A ordenação pode invalidar os resultados de `get_index()` e `get_generic_by_id()` após a sua execução.
 */
void sort_generic_structure (StorageGeneric storage_generic, GCompareFunc compare_func);

#endif