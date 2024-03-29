//
// Created by Olcay Taner YILDIZ on 5.02.2023.
//

#ifndef PROPBANK_ROLE_H
#define PROPBANK_ROLE_H

#include "ArgumentType.h"

struct role {
    char *description;
    char *f;
    char *n;
};

typedef struct role Role;
typedef Role *Role_ptr;

Role_ptr create_role(const char *description, const char *f, const char *n);

void free_role(Role_ptr role);

Argument_type get_argument_type(const Role* role);

#endif //PROPBANK_ROLE_H
