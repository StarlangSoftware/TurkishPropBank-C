cmake_minimum_required(VERSION 3.23)
project(PropBank C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-O3")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library(PropBank src/Argument.c src/Argument.h src/ArgumentType.h src/FramesetArgument.c src/FramesetArgument.h src/Role.c src/Role.h src/Frameset.c src/Frameset.h src/FramesetList.c src/FramesetList.h src/Roleset.c src/Roleset.h src/Predicate.c src/Predicate.h src/PredicateList.c src/PredicateList.h)
target_link_libraries(PropBank ${CONAN_LIBS})
