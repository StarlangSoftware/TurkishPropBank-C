//
// Created by Olcay Taner YILDIZ on 6.02.2023.
//

#include <stdlib.h>
#include <StringUtils.h>
#include <stdbool.h>
#include "Frameset.h"
#include "FramesetArgument.h"

Frameset_ptr create_frameset(char *id) {
    Frameset_ptr result = malloc(sizeof(Frameset));
    result->id = str_copy(result->id, id);
    result->frameset_arguments = create_array_list();
    return result;
}

void free_frameset(Frameset_ptr frameset) {
    free_array_list(frameset->frameset_arguments, (void (*)(void *)) free_frameset_argument);
    free(frameset->id);
    free(frameset);
}

/**
 * Another constructor of {@link Frameset} class which takes inputStream as input and reads the frameset
 *
 * @param frameset_node  Part of Xml node to read from
 */
Frameset_ptr create_frameset2(Xml_element_ptr frameset_node) {
    Frameset_ptr result = malloc(sizeof(Frameset));
    result->frameset_arguments = create_array_list();
    result->id = get_attribute_value(frameset_node, "id");
    Xml_element_ptr argument = frameset_node->first_child;
    while (argument != NULL) {
        Frameset_argument_ptr framesetArgument = create_frameset_argument(get_attribute_value(argument, "name"),
                                                                          argument->pcData,
                                                                          get_attribute_value(argument, "function"));
        array_list_add(result->frameset_arguments, framesetArgument);
        argument = argument->next_sibling;
    }
    return result;
}

/**
 * containsArgument method which checks if there is an {@link Argument} of the given argumentType.
 *
 * @param argument_type  ArgumentType of the searched {@link Argument}
 * @return true if the {@link Argument} with the given argumentType exists, false otherwise.
 */
bool contains_argument(Frameset_ptr frameset, Argument_type argument_type) {
    for (int i = 0; i < frameset->frameset_arguments->size; i++) {
        Frameset_argument_ptr frameset_argument = array_list_get(frameset->frameset_arguments, i);
        if (get_arguments(frameset_argument->argument_type) == argument_type) {
            return true;
        }
    }
    return false;
}

/**
 * The addArgument method takes a type and a definition of a {@link FramesetArgument} as input, then it creates a new FramesetArgument from these inputs and
 * adds it to the framesetArguments {@link ArrayList}.
 *
 * @param type  Type of the new {@link FramesetArgument}
 * @param definition Definition of the new {@link FramesetArgument}
 * @param function Function of the new {@link FramesetArgument}
 */
void add_argument(Frameset_ptr frameset, char *type, char *definition, char *function) {
    int check = 0;
    for (int i = 0; i < frameset->frameset_arguments->size; i++) {
        Frameset_argument_ptr frameset_argument = array_list_get(frameset->frameset_arguments, i);
        if (strcmp(frameset_argument->argument_type, type) == 0) {
            frameset_argument->definition = str_copy(frameset_argument->definition, definition);
            check = 1;
            break;
        }
    }
    if (!check) {
        Frameset_argument_ptr frameset_argument = create_frameset_argument(type, definition, function);
        array_list_add(frameset->frameset_arguments, frameset_argument);
    }
}

/**
 * The deleteArgument method takes a type and a definition of a {@link FramesetArgument} as input, then it searches for the FramesetArgument with these type and
 * definition, and if it finds removes it from the framesetArguments {@link ArrayList}.
 *
 * @param type  Type of the to be deleted {@link FramesetArgument}
 * @param definition Definition of the to be deleted {@link FramesetArgument}
 */
void delete_argument(Frameset_ptr frameset, char *type, char *definition) {
    int index = -1;
    for (int i = 0; i < frameset->frameset_arguments->size; i++) {
        Frameset_argument_ptr frameset_argument = array_list_get(frameset->frameset_arguments, i);
        if (strcmp(frameset_argument->argument_type, type) == 0 &&
            strcmp(frameset_argument->definition, definition) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        array_list_remove(frameset->frameset_arguments, index, (void (*)(void *)) free_frameset_argument);
    }
}

/**
 * Accessor for framesetArguments.
 *
 * @return framesetArguments.
 */
Array_list_ptr get_frameset_arguments(Frameset_ptr frameset) {
    return frameset->frameset_arguments;
}
