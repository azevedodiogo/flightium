#ifndef TESTS_PARSERS_H
#define TESTS_PARSERS_H

/** @brief Estrutura agregadora dos resultados de testes. */
typedef struct tests *Tests;

/** @brief Declaração antecipada da base de dados para evitar dependências circulares. */
typedef struct database *Database;

/**
 * @brief Executa os testes de carregamento dos datasets.
 * @param database Base de dados de destino.