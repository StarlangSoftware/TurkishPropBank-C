//
// Created by Olcay Taner YILDIZ on 6.02.2023.
//

#include "../src/FramesetList.h"
#include "../src/FramesetArgument.h"
#include <stdio.h>
#include <HashMap/HashMap.h>
#include <stdlib.h>
#include <CounterHashMap.h>

void testFrames(Frameset_list_ptr frameset_list) {
    if (17691 != size(frameset_list)) {
        printf("Test failed in testFrames\n");
    }
}

void testArgSize(Frameset_list_ptr frameset_list) {
    int count = 0;
    for (int i = 0; i < size(frameset_list); i++) {
        Frameset_ptr frameset = get_frameset(frameset_list, i);
        count += frameset->frameset_arguments->size;
    }
    if (29759 != count) {
        printf("Test failed in testArgSize\n");
    }
}

void testArgName(Frameset_list_ptr frameset_list) {
    Counter_hash_map_ptr nameList = create_counter_hash_map((unsigned int (*)(const void *, int)) hash_function_string,
                                                            (int (*)(const void *, const void *)) compare_string);
    for (int i = 0; i < size(frameset_list); i++) {
        Frameset_ptr frameset = get_frameset(frameset_list, i);
        for (int j = 0; j < frameset->frameset_arguments->size; j++) {
            Frameset_argument_ptr argument = array_list_get(frameset->frameset_arguments, j);
            put_counter_hash_map(nameList, argument->argument_type);
        }
    }
    if (14668 != count_counter_hash_map(nameList, "ARG0")) {
        printf("Test failed in testArgName\n");
    }
    if (13126 != count_counter_hash_map(nameList, "ARG1")) {
        printf("Test failed in testArgName\n");
    }
    if (1886 != count_counter_hash_map(nameList, "ARG2")) {
        printf("Test failed in testArgName\n");
    }
    if (78 != count_counter_hash_map(nameList, "ARG3")) {
        printf("Test failed in testArgName\n");
    }
    if (1 != count_counter_hash_map(nameList, "ARG4")) {
        printf("Test failed in testArgName\n");
    }
    free_counter_hash_map(nameList);
}

void testArgFunction(Frameset_list_ptr frameset_list) {
    Counter_hash_map_ptr functionList = create_counter_hash_map((unsigned int (*)(const void *, int)) hash_function_string,
                                                                (int (*)(const void *, const void *)) compare_string);
    for (int i = 0; i < size(frameset_list); i++) {
        Frameset_ptr frameset = get_frameset(frameset_list, i);
        for (int j = 0; j < frameset->frameset_arguments->size; j++) {
            Frameset_argument_ptr argument = array_list_get(frameset->frameset_arguments, j);
            put_counter_hash_map(functionList, argument->function);
        }
    }
    if (481 != count_counter_hash_map(functionList, "com")) {
        printf("Test failed in testArgFunction\n");
    }
    if (14 != count_counter_hash_map(functionList, "ext")) {
        printf("Test failed in testArgFunction\n");
    }
    if (814 != count_counter_hash_map(functionList, "loc")) {
        printf("Test failed in testArgFunction\n");
    }
    if (198 != count_counter_hash_map(functionList, "rec")) {
        printf("Test failed in testArgFunction\n");
    }
    if (14 != count_counter_hash_map(functionList, "pat")) {
        printf("Test failed in testArgFunction\n");
    }
    free_counter_hash_map(functionList);
}

int main() {
    Frameset_list_ptr frameset_list = create_frameset_list();
    testFrames(frameset_list);
    testArgSize(frameset_list);
    testArgName(frameset_list);
    testArgFunction(frameset_list);
    free_frameset_list(frameset_list);
}