//
// Created by Olcay Taner YILDIZ on 5.02.2023.
//

#include <stdlib.h>
#include <StringUtils.h>
#include <string.h>
#include "Argument.h"

/**
 * Another constructor of {@link Argument} class which takes argumentType and id as inputs and initializes corresponding attributes
 *
 * @param argument_type  Type of the argument
 * @param id  Id of the argument
 */
Argument_ptr create_argument(char *argument_type, char *id) {
    Argument_ptr result = malloc(sizeof(Argument));
    result->argument_type = str_copy(result->argument_type, argument_type);
    result->id = str_copy(result->id, id);
    return result;
}

void free_argument(Argument_ptr argument) {
    free(argument->argument_type);
    free(argument->id);
    free(argument);
}

/**
 * A constructor of {@link Argument} class which takes argument string which is in the form of argumentType$id
 * and parses this string into argumentType and id. If the argument string does not contain '$' then the
 * constructor return a NONE type argument.
 *
 * @param argument  Argument string containing the argumentType and id
 */
Argument_ptr create_argument2(char *argument) {
    Argument_ptr result = malloc(sizeof(Argument));
    if (strchr(argument, '$') != NULL){
        Array_list_ptr items = str_split(argument, '$');
        result->argument_type = array_list_get(items, 0);
        result->id = array_list_get(items, 1);
        free_array_list(items, NULL);
    } else {
        result->argument_type = str_copy(result->argument_type, "NONE");
        result->id = NULL;
    }
    return result;
}
