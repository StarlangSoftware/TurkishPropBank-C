//
// Created by Olcay Taner YILDIZ on 6.02.2023.
//

#include "../src/ArgumentType.h"
#include <stdio.h>

int main(){
    if (get_arguments("") != NONE){
        printf("Test failed");
    }
    if (get_arguments("arg0") != ARG0){
        printf("Test failed");
    }
    if (get_arguments("argmdis") != ARGMDIS){
        printf("Test failed");
    }
    if (get_arguments("Arg1") != ARG1){
        printf("Test failed");
    }
    if (get_arguments("Argmdir") != ARGMDIR){
        printf("Test failed");
    }
}