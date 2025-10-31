#ifndef PARSER_MAIN_H
#define PARSER_MAIN_H

#include "managers/database.h"

#include <stdio.h>

// {- Funções de carregamento -}

/**
 * @brief Abre os ficheiros de leitura e escrita para todos os datasets.
 * @param read_files Array de FILE* para leitura.
 * @param write_files Array de FILE* para escrita dos registos inválidos.
 * @param directory Diretório base onde se encontram os datasets.
 * @return 0 em caso de sucesso. Caso contrário, devolve-se um valor não nulo se algum ficheiro falhar ao abrir.
 */
int open_dataset_files (FILE *read_files [], FILE *write_files [], const char *directory);

/**
 * @brief Carrega todos os datasets para a base de dados.
 * @param database Estrutura de base de dados a preencher.
 * @param directory Diretório base onde se encontram os ficheiros.
 * @return 0 em caso de sucesso. Caso contrário, devolve-se um valor não nulo se ocorrerem erros de parsing.
 */
int load_datasets (Database database, const char *directory);

/**
 * @brief Carrega um dataset genérico linha a linha.
 * @param read_file Ficheiro de origem.
 * @param write_file Ficheiro de destino para registos inválidos.
 * @param input Zona de memória reutilizada para leitura.
 * @param database Base de dados de destino.
 * @param load_line Função específica de parsing para cada linha.
 */
void generic_load_dataset (FILE *read_file, FILE *write_file, char *input, Database database, int (*load_line) (char *, Database));

#endif