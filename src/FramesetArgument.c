//
// Created by Olcay Taner YILDIZ on 5.02.2023.
//

#include <stdlib.h>
#include <StringUtils.h>
#include "FramesetArgument.h"

/**
 * A constructor of {@link FramesetArgument} class which takes argumentType and definition as input and initializes corresponding attributes
 *
 * @param argument_type  ArgumentType of the frameset argument
 * @param function  Function of the frameset argument
 * @param definition  Definition of the frameset argument
 */
Frameset_argument_ptr create_frameset_argument(char *argument_type, char *definition, char *function) {
    Frameset_argument_ptr result = malloc(sizeof(Frameset_argument));
    result->argument_type = str_copy(result->argument_type, argument_type);
    result->function = str_copy(result->function, function);
    result->definition = str_copy(result->definition, definition);
    return result;
}

void free_frameset_argument(Frameset_argument_ptr frameset_argument) {
    free(frameset_argument->argument_type);
    free(frameset_argument->function);
    free(frameset_argument->definition);
    free(frameset_argument);
}
