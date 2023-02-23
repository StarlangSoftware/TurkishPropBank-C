//
// Created by Olcay Taner YILDIZ on 5.02.2023.
//

#ifndef PROPBANK_ARGUMENTTYPE_H
#define PROPBANK_ARGUMENTTYPE_H

#include <string.h>
#include "StringUtils.h"

enum argument_type {
    NONE,
    PREDICATE,
    ARG0,
    ARG1,
    ARG2,
    ARG3,
    ARG4,
    ARG5,
    ARGMNONE,
    ARGMEXT,
    ARGMLOC,
    ARGMDIS,
    ARGMADV,
    ARGMCAU,
    ARGMTMP,
    ARGMPNC,
    ARGMMNR,
    ARGMDIR
};

typedef enum argument_type Argument_type;

Argument_type get_arguments(char *arguments_type);

char *get_propbank_type(Argument_type argument_type);

#endif //PROPBANK_ARGUMENTTYPE_H
