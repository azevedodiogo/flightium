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

/**
 * @brief Retorna o dia de um `date`.
 */
#define GET_DAY(d) (((d) >> 11) & 0x1F)

/**
 * @brief Retorna o mês de um `date`.
 */
#define GET_MONTH(d) (((d) >> 16) & 0xF)

/**
 * @brief Retorna o ano de um `date`.
 */
#define GET_YEAR(d) (((d) >> 20) & 0x7FF)



/**
 * @brief Converte uma data em `date`, excluindo hora e minuto.
 * @param year Ano.
 * @param month Mês.
 * @param day Dia.
 * @return Valor compactado com horas e minutos definidos a zero.
 * @warning Os limites dos parâmetros não são validados. o chamador deve garantir a coerência dos valores.
 */
date convert_date (int year, int month, int day);

/**
 * @brief Converte data e hora num valor `date`.
 * @param year Ano.
 * @param month Mês.
 * @param day Dia.
 * @param hour Hora.
 * @param minute Minuto.
 * @return Valor compactado com data e tempo.
 * @warning Os valores fornecidos não são validados; fornecer parâmetros fora dos limites ocasiona comportamentos incorretos silenciosos.
 */
date convert_datetime (int year, int month, int day, int hour, int minute);

/**