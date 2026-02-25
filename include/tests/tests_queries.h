#ifndef TESTS_QUERIES_H
#define TESTS_QUERIES_H

/** @brief Estrutura agregadora dos resultados de testes. */
typedef struct tests *Tests;

/** @brief Declaração antecipada da base de dados para evitar dependências circulares. */
typedef struct database *Database;

/**
 * @brief Executa as queries de teste e recolhe estatísticas.
 * @param database Base de dados preparada para teste.
 * @param directory Diretório base dos ficheiros de comandos de teste.
 * @param tests Estrutura onde os resultados são registados.
 * @return 0 em caso de sucesso. Caso contrário, devolve-se um valor não nulo se algum teste falhar.
 */
int test_execute_queries (Database database, const char *directory, Tests tests);

#endif