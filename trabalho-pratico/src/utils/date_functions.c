#include "utils/date_functions.h"

#define NUMBER_MINUTES_IN_ONE_DAY 1440
#define NUMBER_DAYS_SINCE_ORIGIN_START_2025 739251

// Número de dias de cada mês
static const int days_in_month [] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};