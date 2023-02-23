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

Frameset_ptr create_frameset(char *id);

Frameset_ptr create_frameset2(Xml_element_ptr frameset_node);

void free_frameset(Frameset_ptr frameset);

int contains_argument(Frameset_ptr frameset, Argument_type argument_type);

void add_argument(Frameset_ptr frameset, char *type, char *definition, char *function);

void delete_argument(Frameset_ptr frameset, char *type, char *definition);

Array_list_ptr get_frameset_arguments(Frameset_ptr frameset);

#endif //PROPBANK_FRAMESET_H
