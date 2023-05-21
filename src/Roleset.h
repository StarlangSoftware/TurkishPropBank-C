//
// Created by Olcay Taner YILDIZ on 6.02.2023.
//

#ifndef PROPBANK_ROLESET_H
#define PROPBANK_ROLESET_H

#include <ArrayList.h>
#include "Role.h"

struct roleset {
    char *id;
    char *name;
    Array_list_ptr roles;
};

typedef struct roleset Roleset;
typedef Roleset *Roleset_ptr;

Roleset_ptr create_roleset(const char *id, const char *name);

void free_roleset(Roleset_ptr roleset);

void add_role(Roleset_ptr roleset, Role_ptr role);

Role_ptr get_role(const Roleset* roleset, int index);

int size_of_roleset(const Roleset* roleset);

Role_ptr get_role_with_argument(const Roleset* roleset, const char *n);

#endif //PROPBANK_ROLESET_H
