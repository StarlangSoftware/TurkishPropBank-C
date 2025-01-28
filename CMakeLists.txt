cmake_minimum_required(VERSION 3.23)
project(PropBank)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-O3")

find_package(xml_parser_c REQUIRED)
find_package(util_c REQUIRED)

add_library(PropBank src/Argument.c src/Argument.h src/ArgumentType.h src/FramesetArgument.c src/FramesetArgument.h src/Role.c src/Role.h src/Frameset.c src/Frameset.h src/FramesetList.c src/FramesetList.h src/Roleset.c src/Roleset.h src/Predicate.c src/Predicate.h src/PredicateList.c src/PredicateList.h src/ArgumentType.c
        src/ArgumentList.c
        src/ArgumentList.h)
target_link_libraries(PropBank xml_parser_c::xml_parser_c util_c::util_c)
add_executable(ArgumentTypeTest src/Argument.c src/Argument.h src/ArgumentType.h src/FramesetArgument.c src/FramesetArgument.h src/Role.c src/Role.h src/Frameset.c src/Frameset.h src/FramesetList.c src/FramesetList.h src/Roleset.c src/Roleset.h src/Predicate.c src/Predicate.h src/PredicateList.c src/PredicateList.h Test/ArgumentTypeTest.c src/ArgumentType.c
        src/ArgumentList.c
        src/ArgumentList.h)
target_link_libraries(ArgumentTypeTest xml_parser_c::xml_parser_c util_c::util_c)
add_executable(FramesetListTest src/Argument.c src/Argument.h src/ArgumentType.h src/FramesetArgument.c src/FramesetArgument.h src/Role.c src/Role.h src/Frameset.c src/Frameset.h src/FramesetList.c src/FramesetList.h src/Roleset.c src/Roleset.h src/Predicate.c src/Predicate.h src/PredicateList.c src/PredicateList.h Test/FramesetListTest.c src/ArgumentType.c
        src/ArgumentList.c
        src/ArgumentList.h)
target_link_libraries(FramesetListTest xml_parser_c::xml_parser_c util_c::util_c)
add_executable(PredicateListTest src/Argument.c src/Argument.h src/ArgumentType.h src/FramesetArgument.c src/FramesetArgument.h src/Role.c src/Role.h src/Frameset.c src/Frameset.h src/FramesetList.c src/FramesetList.h src/Roleset.c src/Roleset.h src/Predicate.c src/Predicate.h src/PredicateList.c src/PredicateList.h Test/PredicateListTest.c src/ArgumentType.c
        src/ArgumentList.c
        src/ArgumentList.h)
target_link_libraries(PredicateListTest xml_parser_c::xml_parser_c util_c::util_c)
