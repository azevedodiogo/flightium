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