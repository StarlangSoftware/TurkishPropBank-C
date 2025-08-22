//
// Created by Olcay Taner YILDIZ on 6.02.2023.
//

#include "../src/FramesetList.h"
#include "../src/FramesetArgument.h"
#include <stdio.h>
#include <HashMap/HashMap.h>
#include <CounterHashMap.h>

void testFrames(Frameset_list_ptr frameset_list) {
    if (17531 != size(frameset_list)) {
        printf("Test failed in testFrames\n");
    }
}

void testArgSize(Frameset_list_ptr frameset_list) {
    int count = 0;
    for (int i = 0; i < size(frameset_list); i++) {
        Frameset_ptr frameset = get_frameset(frameset_list, i);
        count += frameset->frameset_arguments->size;
    }
    if (29473 != count) {
        printf("Test failed in testArgSize\n");
    }
}

void testCase(Frameset_list_ptr frameset_list) {
    Counter_hash_map_ptr caseList = create_counter_hash_map((unsigned int (*)(const void *, int)) hash_function_string,
                                                            (int (*)(const void *, const void *)) compare_string);
    for (int i = 0; i < size(frameset_list); i++) {
        Frameset_ptr frameset = get_frameset(frameset_list, i);
        for (int j = 0; j < frameset->frameset_arguments->size; j++) {
            Frameset_argument_ptr argument = array_list_get(frameset->frameset_arguments, j);
            if (argument->grammatical_case != NULL) {
                if (str_contains(argument->grammatical_case, "abl")) {
                    put_counter_hash_map(caseList, "abl");
                }
                if (str_contains(argument->grammatical_case, "acc")) {
                    put_counter_hash_map(caseList, "acc");
                }
                if (str_contains(argument->grammatical_case, "dat")) {
                    put_counter_hash_map(caseList, "dat");
                }
                if (str_contains(argument->grammatical_case, "gen")) {
                    put_counter_hash_map(caseList, "gen");
                }
                if (str_contains(argument->grammatical_case, "ins")) {
                    put_counter_hash_map(caseList, "ins");
                }
                if (str_contains(argument->grammatical_case, "loc")) {
                    put_counter_hash_map(caseList, "loc");
                }
                if (str_contains(argument->grammatical_case, "nom")) {
                    put_counter_hash_map(caseList, "nom");
                }
            }
        }
    }
    if (418 != count_counter_hash_map(caseList, "abl")) {
        printf("Test failed in testCase abl\n");
    }
    if (4633 != count_counter_hash_map(caseList, "acc")) {
        printf("Test failed in testCase acc\n");
    }
    if (2402 != count_counter_hash_map(caseList, "dat")) {
        printf("Test failed in testCase dat\n");
    }
    if (870 != count_counter_hash_map(caseList, "gen")) {
        printf("Test failed in testCase gen\n");
    }
    if (451 != count_counter_hash_map(caseList, "ins")) {
        printf("Test failed in testCase ins\n");
    }
    if (666 != count_counter_hash_map(caseList, "loc")) {
        printf("Test failed in testCase loc\n");
    }
    if (2049 != count_counter_hash_map(caseList, "nom")) {
        printf("Test failed in testCase nom\n");
    }
    free_counter_hash_map(caseList);
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
    if (14535 != count_counter_hash_map(nameList, "ARG0")) {
        printf("Test failed in testArgName\n");
    }
    if (12996 != count_counter_hash_map(nameList, "ARG1")) {
        printf("Test failed in testArgName\n");
    }
    if (1865 != count_counter_hash_map(nameList, "ARG2")) {
        printf("Test failed in testArgName\n");
    }
    if (76 != count_counter_hash_map(nameList, "ARG3")) {
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
    if (475 != count_counter_hash_map(functionList, "com")) {
        printf("Test failed in testArgFunction\n");
    }
    if (14 != count_counter_hash_map(functionList, "ext")) {
        printf("Test failed in testArgFunction\n");
    }
    if (808 != count_counter_hash_map(functionList, "loc")) {
        printf("Test failed in testArgFunction\n");
    }
    if (195 != count_counter_hash_map(functionList, "rec")) {
        printf("Test failed in testArgFunction\n");
    }
    if (13 != count_counter_hash_map(functionList, "pat")) {
        printf("Test failed in testArgFunction\n");
    }
    if (10579 != count_counter_hash_map(functionList, "ppt")) {
        printf("Test failed in testArgFunction\n");
    }
    if (597 != count_counter_hash_map(functionList, "src")) {
        printf("Test failed in testArgFunction\n");
    }
    if (794 != count_counter_hash_map(functionList, "gol")) {
        printf("Test failed in testArgFunction\n");
    }
    if (156 != count_counter_hash_map(functionList, "tmp")) {
        printf("Test failed in testArgFunction\n");
    }
    if (14425 != count_counter_hash_map(functionList, "pag")) {
        printf("Test failed in testArgFunction\n");
    }
    if (1417 != count_counter_hash_map(functionList, "dir")) {
        printf("Test failed in testArgFunction\n");
    }
    free_counter_hash_map(functionList);
}

int main() {
    Frameset_list_ptr frameset_list = create_frameset_list();
    testFrames(frameset_list);
    testCase(frameset_list);
    testArgSize(frameset_list);
    testArgName(frameset_list);
    testArgFunction(frameset_list);
    free_frameset_list(frameset_list);
}