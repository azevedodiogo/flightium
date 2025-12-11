#include "utils/utility_functions.h"

#include <stdio.h>

#define NO_VALUE -1
#define BUFFER 1024

// Separa uma string por um caractere
char *our_strsep (char **str, char stop_character) {

    // Guarda o endereço inicial
    char *r = *str;

    // Avança na string até ao caractere de paragem ou ao fim da string
    while ((*str) [0] && (*str) [0] != stop_character) (*str)++;

    // Avança o caractere de paragem
    if ((*str) [0] == stop_character) {
        (*str) [0] = 0;
        (*str)++;
    }

    // Retorna o endereço inicial
    return r;
}

// Separa uma string por um caractere e avança até à próxima ocorrência do mesmo
char* separate_block (char **str, char stop_character) {

    // Avança a primeira vez
    our_strsep (str, stop_character);

    // Avança a segunda vez
    char *r = our_strsep (str, stop_character);

    // Retorna o endereço inicial
    return r;
}

// Determina o tipo de dataset
int determine_dataset (const char *directory, int *dataset) {

    // Nome do ficheiro
    char file_name [BUFFER]; snprintf (file_name, BUFFER, "%s/aircrafts.csv", directory);

    // Abre o ficheiro
    FILE *file = fopen (file_name, "r");

    // Verifica se o ficheiro não foi aberto corretamente
    if (file == NULL) return NO_VALUE;

    // Número de linhas do ficheiro
    int lines; char aux [BUFFER];