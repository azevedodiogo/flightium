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
 * @param stop_character Delimitador usado para a separação.
 * @return Ponteiro para o bloco extraído ou NULL se não existir.
 */
char* separate_block (char **str, char stop_character);

/**
 * @brief Determina o tipo de dataset presente num diretório.
 * @param directory Caminho fornecido pelo utilizador.
 * @param dataset Ponteiro onde é devolvido o identificador do dataset.
 * @return 0 em caso de sucesso. Caso contrário, devolve-se um valor não nulo se o dataset não for reconhecido.
 */
int determine_dataset (const char *directory, int *dataset);

/**
 * @brief Ajusta índices limitantes garantindo que permanecem dentro dos limites válidos.
 * @param len Comprimento total do vetor de destino.