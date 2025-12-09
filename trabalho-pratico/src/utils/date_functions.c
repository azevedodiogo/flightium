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
