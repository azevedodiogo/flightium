#include "parsers/parser_passengers.h"

#include "utils/utility_functions.h"
#include "utils/date_functions.h"
#include "parsers/general_validations.h"
#include "managers/passengers/structure_passengers.h"

#define NO_VALUE -1

// Carrega uma linha do dataset dos passageiros
int load_line_passengers (char *input, Database database) {

    // Carrega o número de documento
    int document_number = validate_document_number (separate_block (&input, '"'));
    if (document_number == NO_VALUE) return EXIT_FAILURE;

    // Carrega o primeiro nome
    char *first_name = separate_block (&input, '"');

    // Carrega o último nome
    char *last_Name = separate_block (&input, '"');

    // Carrega a data de nascimento
    date dob = validate_date (separate_block (&input, '"'), 0);
    if (dob == INVALID_DATE) return EXIT_FAILURE;

    // Carrega a nacionalidade
    char *nationality = separate_block (&input, '"');

    // Carrega o género
    if (validate_gender (separate_block (&input, '"'))) return EXIT_FAILURE;

    // Carrega o email
    if (validate_email (separate_block (&input, '"'))) return EXIT_FAILURE;

    // Regista o passageiro
    register_passenger (get_database_passengers (database), document_number, first_name, last_Name, nationality, dob);

    // O aeroporto é válido
    return EXIT_SUCCESS;
}