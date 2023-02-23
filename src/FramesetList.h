//
// Created by Olcay Taner YILDIZ on 6.02.2023.
//

#ifndef PROPBANK_FRAMESETLIST_H
#define PROPBANK_FRAMESETLIST_H

#include <ArrayList.h>
#include "Frameset.h"

struct frameset_list {
    Array_list_ptr frames;
};

typedef struct frameset_list Frameset_list;
typedef Frameset_list *Frameset_list_ptr;

Frameset_list_ptr create_frameset_list();

void free_frameset_list(Frameset_list_ptr frameset_list);

int size(Frameset_list_ptr frameset_list);

Frameset_ptr get_frameset(Frameset_list_ptr frameset_list, int index);

void add_frameset(Frameset_list_ptr frameset_list, Frameset_ptr frameset);

Frameset_ptr get_frameset_with_id(Frameset_list_ptr frameset_list, char *synset_id);

int frame_exists(Frameset_list_ptr frameset_list, char *synset_id);

#endif //PROPBANK_FRAMESETLIST_H
