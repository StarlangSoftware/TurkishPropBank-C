//
// Created by Olcay Taner YILDIZ on 6.02.2023.
//

#ifndef PROPBANK_FRAMESET_H
#define PROPBANK_FRAMESET_H

#include <ArrayList.h>
#include <XmlElement.h>
#include "ArgumentType.h"

struct frameset {
    char *id;
    Array_list_ptr frameset_arguments;
};

typedef struct frameset Frameset;
typedef Frameset *Frameset_ptr;

Frameset_ptr create_frameset(const char *id);

Frameset_ptr create_frameset2(const Xml_element* frameset_node);

void free_frameset(Frameset_ptr frameset);

bool contains_argument(const Frameset* frameset, Argument_type argument_type);

void add_argument(Frameset_ptr frameset, const char *type, const char *definition, const char *function, const char *grammatical_case);

void delete_argument(Frameset_ptr frameset, const char *type, const char *definition);

Array_list_ptr get_frameset_arguments(const Frameset* frameset);

#endif //PROPBANK_FRAMESET_H
