# CMakeList.txt : CMake project for Nolfaris, include source and define
# project specific logic here.
cmake_minimum_required (VERSION 3.8)

# add boost
find_package(Boost 1.69.0 COMPONENTS regex)
include_directories(${Boost_INCLUDE_DIRS})

# add rapidjson
find_package(RapidJSON)

# Add the data files
# configure_file(${CMAKE_CURRENT_SOURCE_DIR}/data/grammar_rules.json ${CMAKE_CURRENT_BINARY_DIR}/data/grammar_rules.json COPYONLY) 
add_definitions("-DGRAMMAR_JSON=\"${CMAKE_CURRENT_BINARY_DIR}/data/grammar_rules.json\"")

# Add source to this project's executable.

set ( TARGET_H 
    "headers/error.h"
    "headers/nobject.h"
    "headers/tools.h" 
)

set ( TARGET_SRC
    "cpp/main.cpp"
    "cpp/error.cpp"
    "cpp/nobject.cpp"
    "cpp/tools.cpp"
)

add_executable (Nolfaris ${TARGET_SRC} ${TARGET_H})