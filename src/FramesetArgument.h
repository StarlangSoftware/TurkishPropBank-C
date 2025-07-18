//
// Created by Olcay Taner YILDIZ on 5.02.2023.
//

#ifndef PROPBANK_FRAMESETARGUMENT_H
#define PROPBANK_FRAMESETARGUMENT_H

struct frameset_argument {
    char *argument_type;
    char *function;
    char *definition;
    char *grammatical_case;
};

typedef struct frameset_argument Frameset_argument;
typedef Frameset_argument *Frameset_argument_ptr;

Frameset_argument_ptr create_frameset_argument(const char *argument_type,
                                               const char *definition,
                                               const char *function,
                                               const char *grammatical_case);

void free_frameset_argument(Frameset_argument_ptr frameset_argument);

#endif //PROPBANK_FRAMESETARGUMENT_H
