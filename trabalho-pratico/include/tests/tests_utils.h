#ifndef TESTS_UTILS_H
#define TESTS_UTILS_H

#include <glib.h>
#include <sys/resource.h>

/** @brief Estrutura para medir os tempos de leitura. */
typedef struct load_timer *LoadTimer;