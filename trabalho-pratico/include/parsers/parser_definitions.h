#ifndef PARSER_DEFINITIONS_H
#define PARSER_DEFINITIONS_H

/** @brief Estrutura opaca da base de dados para ocultar a implementação e evitar dependências circulares. */
typedef struct database *Database;

/** @brief Ponteiros para funções de carregamento de datasets. */
int load_line_aircrafts (char *, Database);
int load_line_airports (char *, Database);
int load_line_passengers (char *, Database);
int load_line_flights (char *, Database);
int load_line_reservations (char *, Database);
