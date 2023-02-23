//
// Created by Olcay Taner YILDIZ on 5.02.2023.
//

#include <stdlib.h>
#include <StringUtils.h>
#include <ctype.h>
#include "Role.h"

/**
 * A constructor of {@link Role} class which takes description, f, and n as inputs and initializes corresponding with these inputs.
 *
 * @param description  Description of the role
 * @param f  Argument Type of the role
 * @param n  Number of the role
 */
Role_ptr create_role(char *description, char *f, char *n) {
    Role_ptr result = malloc(sizeof(Role));
    result->description = str_copy(result->description, description);
    result->f = str_copy(result->f, f);
    result->n = str_copy(result->n, n);
    return result;
}

void free_role(Role_ptr role) {
    free(role->description);
    free(role->f);
    free(role->n);
    free(role);
}

/**
 * Constructs and returns the argument type for this role.
 *
 * @return Argument type for this role.
 */
Argument_type get_argument_type(Role_ptr role) {
    char *upper = uppercase_en(role->f);
    char *s = str_concat("ARG", upper);
    Argument_type result = get_arguments(s);
    free(upper);
    free(s);
    return result;
}
