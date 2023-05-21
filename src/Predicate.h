//
// Created by Olcay Taner YILDIZ on 6.02.2023.
//

#ifndef PROPBANK_PREDICATE_H
#define PROPBANK_PREDICATE_H

#include <ArrayList.h>
#include "Roleset.h"

struct predicate {
    char *lemma;
    Array_list_ptr rolesets;
};

typedef struct predicate Predicate;
typedef Predicate *Predicate_ptr;

Predicate_ptr create_predicate(const char *lemma);

void free_predicate(Predicate_ptr predicate);

void add_roleset(Predicate_ptr predicate, Roleset_ptr roleset);

int size_of_predicate(const Predicate* predicate);

Roleset_ptr get_roleset(const Predicate* predicate, int index);

Roleset_ptr get_roleset_with_id(const Predicate* predicate, const char *role_id);

#endif //PROPBANK_PREDICATE_H
