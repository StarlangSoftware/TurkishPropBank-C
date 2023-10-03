//
// Created by Olcay Taner YILDIZ on 6.02.2023.
//

#include <stdlib.h>
#include <StringUtils.h>
#include "Roleset.h"
#include "Role.h"

/**
 * A constructor of RoleSet class which takes _id and _name as inputs and initializes corresponding attributes
 * with these inputs.
 *
 * @param _id  Id of the roleSet
 * @param _name Name of the roleSet
 */
Roleset_ptr create_roleset(const char *id, const char *name) {
    Roleset_ptr result = malloc(sizeof(Roleset));
    result->id = str_copy(result->id, id);
    result->name = str_copy(result->name, name);
    result->roles = create_array_list();
    return result;
}

void free_roleset(Roleset_ptr roleset) {
    free(roleset->id);
    free(roleset->name);
    free_array_list(roleset->roles, (void (*)(void *)) free_role);
    free(roleset);
}

/**
 * The addRole method takes a Role as input and adds it to the roles ArrayList.
 *
 * @param role  Role to be added
 */
void add_role(Roleset_ptr roleset, Role_ptr role) {
    array_list_add(roleset->roles, role);
}

/**
 * The getRole method returns the role at the given index.
 *
 * @param index  Index of the role
 * @return Role at the given index.
 */
Role_ptr get_role(const Roleset* roleset, int index) {
    return array_list_get(roleset->roles, index);
}

/**
 * The size_of_predicate method returns the size_of_roleset of the roles ArrayList.
 *
 * @return the size_of_roleset of the roles ArrayList.
 */
int size_of_roleset(const Roleset* roleset) {
    return roleset->roles->size;
}

/**
 * Finds and returns the role with the given argument number n. For example, if n == 0, the method returns
 * the argument ARG0.
 * @param n Argument number
 * @return The role with the given argument number n.
 */
Role_ptr get_role_with_argument(const Roleset* roleset, const char *n) {
    for (int i = 0; i < roleset->roles->size; i++) {
        Role_ptr role = array_list_get(roleset->roles, i);
        if (strcmp(role->n, n) == 0) {
            return role;
        }
    }
    return NULL;
}
