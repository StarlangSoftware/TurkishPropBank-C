//
// Created by Olcay Taner YILDIZ on 6.02.2023.
//

#include <stdlib.h>
#include <StringUtils.h>
#include "Predicate.h"
#include "Roleset.h"

/**
 * A constructor of {@link Predicate} class which takes _lemma as input and initializes _lemma with this input.
 * The constructor also initializes the roleSets array.
 *
 * @param _lemma  Lemma of the predicate
 */
Predicate_ptr create_predicate(const char *lemma) {
    Predicate_ptr result = malloc(sizeof(Predicate));
    result->lemma = str_copy(result->lemma, lemma);
    result->rolesets = create_array_list();
    return result;
}

void free_predicate(Predicate_ptr predicate) {
    free(predicate->lemma);
    free_array_list(predicate->rolesets, (void (*)(void *)) free_roleset);
    free(predicate);
}

/**
 * The addRoleSet method takes a {@link RoleSet} as input and adds it to the roleSets {@link ArrayList}.
 *
 * @param roleSet  RoleSet to be added
 */
void add_roleset(Predicate_ptr predicate, Roleset_ptr roleset) {
    array_list_add(predicate->rolesets, roleset);
}

/**
 * The size method returns the size of the roleSets {@link ArrayList}.
 *
 * @return the size of the roleSets {@link ArrayList}.
 */
int size_of_predicate(const Predicate* predicate) {
    return predicate->rolesets->size;
}

/**
 * The getRoleSet method returns the roleSet at the given index.
 *
 * @param index  Index of the roleSet
 * @return {@link RoleSet} at the given index.
 */
Roleset_ptr get_roleset(const Predicate* predicate, int index) {
    return array_list_get(predicate->rolesets, index);
}

/**
 * Another getRoleSet method which returns the roleSet with the given roleSet id.
 *
 * @param roleId  Id of the searched roleSet
 * @return {@link RoleSet} which has the given id.
 */
Roleset_ptr get_roleset_with_id(const Predicate* predicate, const char *role_id) {
    for (int i = 0; i < predicate->rolesets->size; i++) {
        Roleset_ptr roleset = array_list_get(predicate->rolesets, i);
        if (strcmp(roleset->id, role_id) == 0) {
            return roleset;
        }
    }
    return NULL;
}
