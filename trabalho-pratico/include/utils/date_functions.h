#ifndef DATE_FUNCTIONS_H
#define DATE_FUNCTIONS_H

/**
 * @brief Data compactada num inteiro de 32 bits.
 * @details Data será representada no formato.
 */
typedef unsigned int date;


/**
 * @brief Índice de uma semana.
 */
typedef short week_index;

/**
 * @brief Retorna o minuto de um `date`.
 */
#define GET_MINUTE(d) ((d) & 0x3F)

/**
 * @brief Retorna a hora de um `date`.
 */
#define GET_HOUR(d) (((d) >> 6) & 0x1F)