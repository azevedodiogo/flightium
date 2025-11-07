#ifndef UTILITY_FUNCTIONS_H
#define UTILITY_FUNCTIONS_H

#include <glib.h>

/**
 * @brief Separa uma string até encontrar o carácter indicado.
 * @param str Ponteiro para a string a processar; é atualizado para o segmento restante.
 * @param stop_character Delimitador usado para a separação.
 * @return Ponteiro para o segmento extraído ou NULL se não existir.
 */
char *our_strsep (char **str, char stop_character);

/**
 * @brief Separa uma string e avança para além do próximo delimitador encontrado.
 * @param str Ponteiro para a string a processar. É atualizado para o segmento restante.