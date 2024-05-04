//
// Created by Olcay Taner YILDIZ on 5.02.2023.
//

#include <stdlib.h>
#include <StringUtils.h>
#include <string.h>
#include <stdio.h>
#include <Memory/Memory.h>
#include "Argument.h"

/**
 * Another constructor of Argument class which takes argumentType and id as inputs and initializes corresponding attributes
 *
 * @param argument_type  Type of the argument
 * @param id  Id of the argument
 */
Argument_ptr create_argument(const char *argument_type, const char *id) {
    Argument_ptr result = malloc_(sizeof(Argument), "create_argument");
    result->argument_type = str_copy(result->argument_type, argument_type);
    result->id = str_copy(result->id, id);
    return result;
}

/**
 * Destructor for the Argument class. Free memory allocated for argument type, id.
 * @param argument Current argument.
 */
void free_argument(Argument_ptr argument) {
    free_(argument->argument_type);
    free_(argument->id);
    free_(argument);
}

/**
 * A constructor of Argument class which takes argument string which is in the form of argumentType$id
 * and parses this string into argumentType and id. If the argument string does not contain '$' then the
 * constructor return a NONE type argument.
 *
 * @param argument  Argument string containing the argumentType and id
 */
Argument_ptr create_argument2(const char *argument) {
    Argument_ptr result = malloc_(sizeof(Argument), "create_argument2");
    if (strchr(argument, '$') != NULL) {
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

/**
 * to_string converts an Argument to a string. If the argumentType is "NONE" returns only "NONE", otherwise
 * it returns argument string which is in the form of argumentType$id
 *
 * @return string form of argument
 */
char *argument_to_string(const Argument *argument) {
    char* result;
    if (strcmp(argument->argument_type, "NONE") == 0){
        result = malloc_(5 * sizeof(char), "argument_to_string_1");
        strcpy(result, "NONE");
        return result;
    } else {
        result = malloc_((strlen(argument->argument_type) + 2 + strlen(argument->id)) * sizeof(char), "argument_to_string_2");
        sprintf(result, "%s$%s", argument->argument_type, argument->id);
        return result;
    }
}
