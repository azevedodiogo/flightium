#ifndef TESTS_PARSERS_H
#define TESTS_PARSERS_H

/** @brief Estrutura agregadora dos resultados de testes. */
typedef struct tests *Tests;

/** @brief Declaração antecipada da base de dados para evitar dependências circulares. */
typedef struct database *Database;

/**
 * @brief Executa os testes de carregamento dos datasets.
 * @param database Base de dados de destino.
 * @param directory Diretório base dos ficheiros de teste.
 * @param tests Estrutura onde os resultados são registados.
 * @return 0 em caso de sucesso. Caso contrário, devolve-se um valor não nulo se algum teste falhar.
 */
int test_load_datasets (Database database, const char *directory, Tests tests);

#endif