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