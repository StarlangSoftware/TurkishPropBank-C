//
// Created by Olcay Taner YILDIZ on 28.01.2025.
//

#ifndef ARGUMENTLIST_H
#define ARGUMENTLIST_H
#include <ArrayList.h>

struct argument_list {
    Array_list_ptr arguments;
};

typedef struct argument_list Argument_list;
typedef Argument_list *Argument_list_ptr;

Argument_list_ptr create_argument_list(const char* argument_list);

void free_argument_list(Argument_list_ptr argument_list);

char* argument_list_to_string(Argument_list_ptr argument_list);

void update_connected_id(Argument_list_ptr argument_list, const char *previous_id, const char *current_id);

void add_predicate(Argument_list_ptr argument_list, const char *predicate_id);

void remove_predicate(Argument_list_ptr argument_list);

bool contains_predicate(Argument_list_ptr argument_list);

bool contains_predicate_with_id(Argument_list_ptr argument_list, const char *predicate_id);

Array_list_ptr get_arguments_in_argument_list(Argument_list_ptr argument_list);

bool contains_argument_in_argument_list(Argument_list_ptr argument_list, const char* argument_type, const char *id);

#endif //ARGUMENTLIST_H
