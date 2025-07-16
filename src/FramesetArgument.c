//
// Created by Olcay Taner YILDIZ on 5.02.2023.
//

#include <StringUtils.h>
#include <Memory/Memory.h>
#include "FramesetArgument.h"

/**
 * A constructor of FramesetArgument class which takes argumentType and definition as input and initializes corresponding attributes
 *
 * @param argument_type  ArgumentType of the frameset argument
 * @param function  Function of the frameset argument
 * @param definition  Definition of the frameset argument
 * @param grammatical_case Grammatical case of the frameset argument
 */
Frameset_argument_ptr create_frameset_argument(const char *argument_type, const char *definition, const char *function, const char *grammatical_case) {
    Frameset_argument_ptr result = malloc_(sizeof(Frameset_argument), "create_frameset_argument");
    result->argument_type = str_copy(result->argument_type, argument_type);
    result->function = str_copy(result->function, function);
    result->definition = str_copy(result->definition, definition);
    result->grammatical_case = str_copy(result->grammatical_case, grammatical_case);
    return result;
}

/**
 * Destructor for the frameset argument class. Frees memory allocated for argument type, function, definition.
 * @param frameset_argument Current frameset argument
 */
void free_frameset_argument(Frameset_argument_ptr frameset_argument) {
    free_(frameset_argument->argument_type);
    free_(frameset_argument->function);
    free_(frameset_argument->definition);
    free_(frameset_argument->grammatical_case);
    free_(frameset_argument);
}
