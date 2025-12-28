#include "utils/date_functions.h"

#define NUMBER_MINUTES_IN_ONE_DAY 1440
#define NUMBER_DAYS_SINCE_ORIGIN_START_2025 739251

// Número de dias de cada mês
static const int days_in_month [] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Verifica se o ano é bissexto
static int is_leap_year (int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Calcula o número de dias de um mês
static int n_days_in_month (int year, int month) {
    return (month == 2 && is_leap_year (year)) ? 29 : days_in_month [month - 1];
}

// Converte uma data em `date`
date convert_date (int year, int month, int day) {
    return (year << 20) | (month << 16) | (day << 11) | 0;
}

// Converte uma data e tempo em `date`
date convert_datetime (int year, int month, int day, int hour, int minute) {
    return (year << 20) | (month << 16) | (day << 11) | (hour << 6) | minute;
}

// Converte uma data para o número total de dias desde 01-01-0001
int days_since_origin (date date) {

    // Obtém as componentes necessárias
    int year = GET_YEAR (date), month = GET_MONTH (date), day = GET_DAY (date);

    // Número de dias
    int days = 0;

    // Soma dias dos anos anteriores
    for (int y = 1; y < year; y++) days += is_leap_year (y) ? 366 : 365;

    // Soma dias dos meses anteriores no mesmo ano
    for (int m = 1; m < month; m++) days += n_days_in_month (year, m);

    // Soma dias do mês atual
    days += (day - 1);

    // Retorna o número de dias
    return days;
}

// Calcula a diferença, em minutos, entre duas datas
int date_diff (date date1, date date2) {

    // Obtém as componentes das datas
    int hour1 = GET_HOUR (date1), minute1 = GET_MINUTE (date1);
    int hour2 = GET_HOUR (date2), minute2 = GET_MINUTE (date2);

    // Retorna a diferença
    return days_since_jan_first (date2) * NUMBER_MINUTES_IN_ONE_DAY + hour2 * 60 + minute2 - (days_since_jan_first (date1) * NUMBER_MINUTES_IN_ONE_DAY + hour1 * 60 + minute1);
}
