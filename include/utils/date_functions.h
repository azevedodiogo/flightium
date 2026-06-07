#ifndef DATE_FUNCTIONS_H
#define DATE_FUNCTIONS_H

/**
 * @brief Data compactada num inteiro de 32 bits.
 * @details Representação em bits:
 *          Bits 0-5   : Minuto (6 bits)
 *          Bits 6-10  : Hora (5 bits)
 *          Bits 11-15 : Dia (5 bits)
 *          Bits 16-19 : Mês (4 bits)
 *          Bits 20-30 : Ano (11 bits)
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
 * @brief Converte a data para o número total de dias decorridos desde 01-01-0001.
 * @param date Valor compactado a converter.
 * @return Quantidade de dias decorridos desde a origem.
 * @warning Assume que a data é válida e pertence ao calendário gregoriano simplificado utilizado neste módulo.
 */
int days_since_origin (date date);

/**
 * @brief Calcula a diferença em minutos entre duas datas.
 * @param date1 Data de referência.
 * @param date2 Data contra a qual se compara.
 * @return Número de minutos que devem ser adicionados a `date1` para atingir `date2` (pode ser negativo).
 * @warning O resultado pode ser negativo se `date2` preceder `date1`.
 */
int date_diff (date date1, date date2);

/**
 * @brief Calcula quantos dias decorreram desde 1 de janeiro do ano correspondente à data.
 * @param date Data compactada em análise.
 * @return Dias completos decorridos dentro do ano.
 * @warning Para anos diferentes de 2025, recorre a uma origem interna fixa. Deve ser utilizada apenas com datas válidas.
 */
int days_since_jan_first (date date);

/**
 * @brief Determina o índice da semana do ano para a data fornecida.
 * @param date Valor compactado a avaliar.
 * @return Índice da semana dentro do ano (base 0).
 * @warning Assume que a data obedece ao calendário gregoriano simplificado utilizado neste módulo.
 */
week_index date_to_week (date date);

#endif