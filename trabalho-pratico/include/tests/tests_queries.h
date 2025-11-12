#ifndef TESTS_QUERIES_H
#define TESTS_QUERIES_H

/** @brief Estrutura agregadora dos resultados de testes. */
typedef struct tests *Tests;

/** @brief Declaração antecipada da base de dados para evitar dependências circulares. */
typedef struct database *Database;

/**
 * @brief Executa as queries de teste e recolhe estatísticas.
 * @param database Base de dados preparada para teste.