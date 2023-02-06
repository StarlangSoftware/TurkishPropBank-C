//
// Created by Olcay Taner YILDIZ on 6.02.2023.
//

#include "../src/PredicateList.h"
#include <stdio.h>
#include <CounterHashMap.h>
#include <stdlib.h>

void testPredicateSize(Predicate_list_ptr predicate_list){
    if (8656 != size_of_predicate_list(predicate_list)){
        printf("Test failed in testPredicateSize\n");
    }
}

void testRoleSetSize(Predicate_list_ptr predicate_list){
    int count = 0;
    Array_list_ptr lemmaList = get_lemma_list(predicate_list);
    for (int i = 0; i < lemmaList->size; i++){
        char* lemma = array_list_get(lemmaList,i);
        count += size_of_predicate(get_predicate(predicate_list, lemma));
    }
    if (10685 != count){
        printf("Test failed in testRoleSetSize\n");
    }
    free_array_list(lemmaList, NULL);
}

void testRoleSize(Predicate_list_ptr predicate_list){
    int count = 0;
    Array_list_ptr lemmaList = get_lemma_list(predicate_list);
    for (int i = 0; i < lemmaList->size; i++){
        char* lemma = array_list_get(lemmaList,i);
        int size = size_of_predicate(get_predicate(predicate_list, lemma));
        for (int j = 0; j < size; j++){
            count += size_of_roleset(get_roleset(get_predicate(predicate_list, lemma), i));
        }
    }
    if (27080 != count){
        printf("Test failed in testRoleSetSize\n");
    }
    free_array_list(lemmaList, NULL);
}

void testFunction(Predicate_list_ptr predicate_list){
    Counter_hash_map_ptr functionList = create_counter_hash_map((unsigned int (*)(void *, int)) hash_function_string,
                                                            (int (*)(void *, void *)) compare_string);
    Array_list_ptr lemmaList = get_lemma_list(predicate_list);
    for (int i = 0; i < lemmaList->size; i++){
        char* lemma = array_list_get(lemmaList,i);
        int size = size_of_predicate(get_predicate(predicate_list, lemma));
        for (int j = 0; j < size; j++){
            int size2 = size_of_roleset(get_roleset(get_predicate(predicate_list, lemma), j));
            for (int k = 0; k < size2; k++){
                char* function = get_role(get_roleset(get_predicate(predicate_list, lemma), j), k)->f;
                put_counter_hash_map(functionList, function);
            }
        }
    }
    if (197 != count_counter_hash_map(functionList, "com")){
        printf("Test failed in testFunction\n");
    }
    if (292 != count_counter_hash_map(functionList, "ext")){
        printf("Test failed in testFunction\n");
    }
    if (580 != count_counter_hash_map(functionList, "loc")){
        printf("Test failed in testFunction\n");
    }
    if (1104 != count_counter_hash_map(functionList, "prd")){
        printf("Test failed in testFunction\n");
    }
    if (2395 != count_counter_hash_map(functionList, "gol")){
        printf("Test failed in testFunction\n");
    }
    free_array_list(lemmaList, NULL);
    free_counter_hash_map(functionList, free);
}

void testN(Predicate_list_ptr predicate_list){
    Counter_hash_map_ptr nList = create_counter_hash_map((unsigned int (*)(void *, int)) hash_function_string,
                                                         (int (*)(void *, void *)) compare_string);
    Array_list_ptr lemmaList = get_lemma_list(predicate_list);
    for (int i = 0; i < lemmaList->size; i++){
        char* lemma = array_list_get(lemmaList,i);
        int size = size_of_predicate(get_predicate(predicate_list, lemma));
        for (int j = 0; j < size; j++){
            int size2 = size_of_roleset(get_roleset(get_predicate(predicate_list, lemma), j));
            for (int k = 0; k < size2; k++){
                char* function = get_role(get_roleset(get_predicate(predicate_list, lemma), j), k)->n;
                put_counter_hash_map(nList, function);
            }
        }
    }
    if (8906 != count_counter_hash_map(nList, "0")){
        printf("Test failed in testN\n");
    }
    if (10375 != count_counter_hash_map(nList, "1")){
        printf("Test failed in testN\n");
    }
    if (5934 != count_counter_hash_map(nList, "2")){
        printf("Test failed in testN\n");
    }
    if (1313 != count_counter_hash_map(nList, "3")){
        printf("Test failed in testN\n");
    }
    if (72 != count_counter_hash_map(nList, "m")){
        printf("Test failed in testN\n");
    }
    free_array_list(lemmaList, NULL);
    free_counter_hash_map(nList, free);
}

int main(){
    Predicate_list_ptr predicate_list = create_predicate_list();
    testPredicateSize(predicate_list);
    testRoleSetSize(predicate_list);
    testFunction(predicate_list);
    testN(predicate_list);
    free_predicate_list(predicate_list);
}