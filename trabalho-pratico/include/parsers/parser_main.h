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