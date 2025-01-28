//
// Created by Olcay Taner YILDIZ on 28.01.2025.
//

#include "ArgumentList.h"
#include <stdio.h>
#include <string.h>
#include <StringUtils.h>
#include <Memory/Memory.h>
#include "Argument.h"

/**
 * Constructor of argument list from a string. The arguments for a word is a concatenated list of arguments
 * separated via '#' character.
 * @param argument_list String consisting of arguments separated with '#' character.
 */
Argument_list_ptr create_argument_list(const char *argument_list) {
    Argument_list_ptr result = malloc_(sizeof(struct argument_list), "create_argument_list");
    result->arguments = create_array_list();
    Array_list_ptr items = str_split(argument_list, '#');
    for (int i = 0; i < items->size; i++) {
        array_list_add(result->arguments, create_argument2(array_list_get(items, i)));
    }
    free_array_list(items, free_);
    return result;
}

void free_argument_list(Argument_list_ptr argument_list) {
    free_array_list(argument_list->arguments, (void (*)(void *)) free_argument);
    free_(argument_list);
}

/**
 * Overloaded toString method to convert an argument list to a string. Concatenates the string forms of all
 * arguments with '#' character.
 * @return String form of the argument list.
 */
char* argument_list_to_string(Argument_list_ptr argument_list) {
    char* result;
    char** arguments;
    if (argument_list->arguments->size == 0) {
        result = malloc_(5 * sizeof(char), "argument_to_string_1");
        strcpy(result, "NONE");
        return result;
    } else {
        arguments = malloc_(argument_list->arguments->size * sizeof(char*), "argument_to_string_2");
        int size = 0;
        for (int i = 0; i < argument_list->arguments->size; i++) {
            arguments[i] = argument_to_string(array_list_get(argument_list->arguments, i));
            size += strlen(arguments[i]);
        }
        result = malloc_(size * sizeof(char), "argument_to_string_3");
        sprintf(result, "%s", arguments[0]);
        for (int i = 1; i < argument_list->arguments->size; i++) {
            sprintf(result, "%s#%s", result, arguments[i]);
            free_(arguments[i]);
        }
        free_(arguments[0]);
        free_(arguments);
        return result;
    }
}

/**
 * Replaces id's of predicates, which have previousId as synset id, with currentId.
 * @param argument_list Argument list
 * @param previous_id Previous id of the synset.
 * @param current_id Replacement id.
 */
void update_connected_id(Argument_list_ptr argument_list, const char *previous_id, const char *current_id) {
    for (int i = 0; i < argument_list->arguments->size; i++) {
        Argument_ptr argument = array_list_get(argument_list->arguments, i);
        if (strcmp(previous_id, argument->id) == 0) {
            free_(argument->id);
            argument->id = str_copy(argument->id, current_id);
        }
    }
}

/**
 * Adds a predicate argument to the argument list of this word.
 * @param argument_list Argument list
 * @param predicate_id Synset id of this predicate.
 */
void add_predicate(Argument_list_ptr argument_list, const char *predicate_id) {
    if (argument_list->arguments->size != 0 && strcmp(((Argument_ptr)array_list_get(argument_list->arguments, 0))->argument_type, "NONE") == 0) {
        array_list_remove(argument_list->arguments, 0, (void (*)(void *)) free_argument);
    }
    array_list_add(argument_list->arguments, create_argument("PREDICATE", predicate_id));
}

/**
 * Removes the predicate with the given predicate id.
 * @param argument_list Argument list
 */
void remove_predicate(Argument_list_ptr argument_list) {
    for (int i = 0; i < argument_list->arguments->size; i++) {
        Argument_ptr argument = array_list_get(argument_list->arguments, i);
        if (strcmp(argument->argument_type, "PREDICATE") == 0) {
            array_list_remove(argument_list->arguments, i, (void (*)(void *)) free_argument);
            break;
        }
    }
}

/**
 * Checks if one of the arguments is a predicate.
 * @param argument_list Argument list
 * @return True, if one of the arguments is predicate; false otherwise.
 */
bool contains_predicate(Argument_list_ptr argument_list) {
    for (int i = 0; i < argument_list->arguments->size; i++) {
        Argument_ptr argument = array_list_get(argument_list->arguments, i);
        if (strcmp(argument->argument_type, "PREDICATE") == 0) {
            return true;
        }
    }
    return false;
}

/**
 * Checks if one of the arguments is a predicate with the given id.
 * @param argument_list Argument list
 * @param predicate_id Synset id to check.
 * @return True, if one of the arguments is predicate; false otherwise.
 */
bool contains_predicate_with_id(Argument_list_ptr argument_list, const char *predicate_id) {
    for (int i = 0; i < argument_list->arguments->size; i++) {
        Argument_ptr argument = array_list_get(argument_list->arguments, i);
        if (strcmp(argument->argument_type, "PREDICATE") == 0 && strcmp(predicate_id, argument->id) == 0) {
            return true;
        }
    }
    return false;
}

/**
 * Returns the arguments as an array list of strings.
 * @param argument_list Argument list
 * @return Arguments as an array list of strings.
 */
Array_list_ptr get_arguments_in_argument_list(Argument_list_ptr argument_list) {
    Array_list_ptr result = create_array_list();
    for (int i = 0; i < argument_list->arguments->size; i++) {
        Argument_ptr argument = array_list_get(argument_list->arguments, i);
        array_list_add(result, argument_to_string(argument));
    }
    return result;
}

/**
 * Checks if the given argument with the given type and id exists or not.
 * @param argument_list Argument list
 * @param argument_type Type of the argument to search for.
 * @param id Id of the argument to search for.
 * @return True if the argument exists, false otherwise.
 */
bool contains_argument_in_argument_list(Argument_list_ptr argument_list, const char* argument_type, const char *id) {
    for (int i = 0; i < argument_list->arguments->size; i++) {
        Argument_ptr argument = array_list_get(argument_list->arguments, i);
        if (strcmp(argument->argument_type, argument_type) == 0 && strcmp(argument->id, id) == 0) {
            return true;
        }
    }
    return false;
}
