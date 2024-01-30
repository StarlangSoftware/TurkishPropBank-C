cmake_minimum_required(VERSION 3.23)
project(PropBank)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-O3")

find_package(xml_parser_c REQUIRED)
find_package(util_c REQUIRED)

add_library(PropBank Argument.c Argument.h ArgumentType.h FramesetArgument.c FramesetArgument.h Role.c Role.h Frameset.c Frameset.h FramesetList.c FramesetList.h Roleset.c Roleset.h Predicate.c Predicate.h PredicateList.c PredicateList.h ArgumentType.c)
target_link_libraries(PropBank xml_parser_c::xml_parser_c util_c::util_c)
