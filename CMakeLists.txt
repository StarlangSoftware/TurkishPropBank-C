cmake_minimum_required(VERSION 3.23)
project(PropBank C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-O3")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library(PropBank src/Argument.c src/Argument.h src/ArgumentType.h src/FramesetArgument.c src/FramesetArgument.h src/Role.c src/Role.h src/Frameset.c src/Frameset.h src/FramesetList.c src/FramesetList.h src/Roleset.c src/Roleset.h src/Predicate.c src/Predicate.h src/PredicateList.c src/PredicateList.h src/ArgumentType.c)
target_link_libraries(PropBank ${CONAN_LIBS})
add_executable(ArgumentTypeTest src/Argument.c src/Argument.h src/ArgumentType.h src/FramesetArgument.c src/FramesetArgument.h src/Role.c src/Role.h src/Frameset.c src/Frameset.h src/FramesetList.c src/FramesetList.h src/Roleset.c src/Roleset.h src/Predicate.c src/Predicate.h src/PredicateList.c src/PredicateList.h Test/ArgumentTypeTest.c src/ArgumentType.c)
target_link_libraries(ArgumentTypeTest ${CONAN_LIBS})
add_executable(FramesetListTest src/Argument.c src/Argument.h src/ArgumentType.h src/FramesetArgument.c src/FramesetArgument.h src/Role.c src/Role.h src/Frameset.c src/Frameset.h src/FramesetList.c src/FramesetList.h src/Roleset.c src/Roleset.h src/Predicate.c src/Predicate.h src/PredicateList.c src/PredicateList.h Test/FramesetListTest.c src/ArgumentType.c)
target_link_libraries(FramesetListTest ${CONAN_LIBS})
add_executable(PredicateListTest src/Argument.c src/Argument.h src/ArgumentType.h src/FramesetArgument.c src/FramesetArgument.h src/Role.c src/Role.h src/Frameset.c src/Frameset.h src/FramesetList.c src/FramesetList.h src/Roleset.c src/Roleset.h src/Predicate.c src/Predicate.h src/PredicateList.c src/PredicateList.h Test/PredicateListTest.c src/ArgumentType.c)
target_link_libraries(PredicateListTest ${CONAN_LIBS})
