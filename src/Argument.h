//
// Created by Olcay Taner YILDIZ on 5.02.2023.
//

#ifndef PROPBANK_ARGUMENT_H
#define PROPBANK_ARGUMENT_H

struct argument{
    char* argument_type;
    char* id;
};

typedef struct argument Argument;
typedef Argument* Argument_ptr;

Argument_ptr create_argument(char* argument_type, char* id);
Argument_ptr create_argument2(char* argument);
void free_argument(Argument_ptr argument);

#endif //PROPBANK_ARGUMENT_H
