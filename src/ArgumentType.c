//
// Created by Olcay Taner YILDIZ on 6.02.2023.
//

#include <stdlib.h>
#include <Memory/Memory.h>
#include "ArgumentType.h"

/**
 * The getArguments method takes an argumentsType string and returns the ArgumentType form of it.
 *
 * @param arguments_type  Type of the argument in string form
 * @return Type of the argument in ArgumentType form
 */
Argument_type get_arguments(const char* arguments_type){
    char* type = uppercase_en(arguments_type);
    Argument_type result;
    if (strcmp(type, "ARG0") == 0){
        result = ARG0;
    } else {
        if (strcmp(type, "ARG1") == 0) {
            result = ARG1;
        } else {
            if (strcmp(type, "ARG2") == 0) {
                result = ARG2;
            } else {
                if (strcmp(type, "ARG3") == 0) {
                    result = ARG3;
                } else {
                    if (strcmp(type, "ARG4") == 0) {
                        result = ARG4;
                    } else {
                        if (strcmp(type, "ARG5") == 0) {
                            result = ARG5;
                        } else {
                            if (strcmp(type, "ARGMADV") == 0) {
                                result = ARGMADV;
                            } else {
                                if (strcmp(type, "ARGMCAU") == 0) {
                                    result = ARGMCAU;
                                } else {
                                    if (strcmp(type, "ARGMDIR") == 0) {
                                        result = ARGMDIR;
                                    } else {
                                        if (strcmp(type, "ARGMDIS") == 0) {
                                            result = ARGMDIS;
                                        } else {
                                            if (strcmp(type, "ARGMEXT") == 0) {
                                                result = ARGMEXT;
                                            } else {
                                                if (strcmp(type, "ARGMLOC") == 0) {
                                                    result = ARGMLOC;
                                                } else {
                                                    if (strcmp(type, "ARGMMNR") == 0) {
                                                        result = ARGMMNR;
                                                    } else {
                                                        if (strcmp(type, "ARGMTMP") == 0) {
                                                            result = ARGMTMP;
                                                        } else {
                                                            if (strcmp(type, "ARGMNONE") == 0) {
                                                                result = ARGMNONE;
                                                            } else {
                                                                if (strcmp(type, "ARGMPNC") == 0) {
                                                                    result = ARGMPNC;
                                                                } else {
                                                                    if (strcmp(type, "PREDICATE") == 0) {
                                                                        result = PREDICATE;
                                                                    } else {
                                                                        result = NONE;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    free_(type);
    return result;
}

/**
 * The get_propbank_type method takes an argumentType in ArgumentType form and returns the string form of it.
 *
 * @param argument_type  Type of the argument in ArgumentType form
 * @return Type of the argument in string form
 */
char *get_propbank_type(Argument_type argument_type){
    switch (argument_type){
        case ARG0:
            return "ARG0";
        case ARG1:
            return "ARG1";
        case ARG2:
            return "ARG2";
        case ARG3:
            return "ARG3";
        case ARG4:
            return "ARG4";
        case ARG5:
            return "ARG5";
        case ARGMADV:
            return "ARGMADV";
        case ARGMCAU:
            return "ARGMCAU";
        case ARGMDIR:
            return "ARGMDIR";
        case ARGMDIS:
            return "ARGMDIS";
        case ARGMEXT:
            return "ARGMEXT";
        case ARGMLOC:
            return "ARGMLOC";
        case ARGMMNR:
            return "ARGMMNR";
        case ARGMTMP:
            return "ARGMTMP";
        case ARGMNONE:
            return "ARGMNONE";
        case ARGMPNC:
            return "ARGMPNC";
        case PREDICATE:
            return "PREDICATE";
        default:
            return "NONE";
    }
}
