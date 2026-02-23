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

/**
 * @brief Enumeração dos datasets disponibilizados.
 */
typedef enum datasets {
    N_AIRCRAFT,     /**< Dataset das aeronaves. */
    N_AIRPORT,      /**< Dataset dos aeroportos. */
    N_PASSENGER,    /**< Dataset dos passageiros. */
    N_FLIGHT,       /**< Dataset dos voos. */
    N_RESERVATION,  /**< Dataset das reservas. */
    N_DATASETS      /**< Número total de datasets. */
} Datasets;

#endif