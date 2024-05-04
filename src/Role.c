//
// Created by Olcay Taner YILDIZ on 5.02.2023.
//

#include <stdlib.h>
#include <StringUtils.h>
#include <Memory/Memory.h>
#include "Role.h"

/**
 * A constructor of Role class which takes description, f, and n as inputs and initializes corresponding with these inputs.
 *
 * @param description  Description of the role
 * @param f  Argument Type of the role
 * @param n  Number of the role
 */
Role_ptr create_role(const char *description, const char *f, const char *n) {
    Role_ptr result = malloc_(sizeof(Role), "create_role");
    result->description = str_copy(result->description, description);
    result->f = str_copy(result->f, f);
    result->n = str_copy(result->n, n);
    return result;
}

/**
 * Destructor for the Role class. Frees memory allocated for description, f, and n.
 * @param role Current role.
 */
void free_role(Role_ptr role) {
    free_(role->description);
    free_(role->f);
    free_(role->n);
    free_(role);
}

/**
 * Constructs and returns the argument type for this role.
 *
 * @return Argument type for this role.
 */
Argument_type get_argument_type(const Role* role) {
    char *upper = uppercase_en(role->f);
    char *s = str_concat("ARG", upper);
    Argument_type result = get_arguments(s);
    free_(upper);
    free_(s);
    return result;
}
