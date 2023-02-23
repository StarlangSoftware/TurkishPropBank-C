//
// Created by Olcay Taner YILDIZ on 6.02.2023.
//

#ifndef PROPBANK_PREDICATELIST_H
#define PROPBANK_PREDICATELIST_H

#include <HashMap/HashMap.h>
#include <HashMap/HashSet.h>
#include "Predicate.h"

struct predicate_list {
    Hash_map_ptr list;
};

typedef struct predicate_list Predicate_list;
typedef Predicate_list *Predicate_list_ptr;

Predicate_list_ptr create_predicate_list();

void free_predicate_list(Predicate_list_ptr predicate_list);

int size_of_predicate_list(Predicate_list_ptr predicate_list);

Predicate_ptr get_predicate(Predicate_list_ptr predicate_list, char *lemma);

Array_list_ptr get_lemma_list(Predicate_list_ptr predicate_list);

#endif //PROPBANK_PREDICATELIST_H
