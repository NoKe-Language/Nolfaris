# minimum required CMAKE version
CMAKE_MINIMUM_REQUIRED(VERSION 3.8 FATAL_ERROR)


project ("Nolfaris")

# add boost
find_package(Boost 1.69.0 COMPONENTS regex program_options)
include_directories(${Boost_INCLUDE_DIRS})

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# compiler must be 11 or 14
set(CMAKE_CXX_STANDARD 17)

# required if linking to static library
add_definitions(-DANTLR4CPP_STATIC)

# using /MD flag for antlr4_runtime (for Visual C++ compilers only)
set(ANTLR4_WITH_STATIC_CRT OFF)
# add external build for antlrcpp
include(ExternalAntlr4Cpp)
# add antrl4cpp artifacts to project environment
include_directories(${ANTLR4_INCLUDE_DIRS})

# set variable pointing to the antlr tool that supports C++
# this is not required if the jar file can be found under PATH environment
set(ANTLR_EXECUTABLE /usr/local/lib/antlr-4.7.2-complete.jar)

# add macros to generate ANTLR Cpp code from grammar
find_package(ANTLR REQUIRED)

# Call macro to add lexer and grammar to your build dependencies.
antlr_target(SampleGrammarLexer NokeLexer.g4 LEXER
             PACKAGE nolfaris)
antlr_target(SampleGrammarParser NokeParser.g4 PARSER
             PACKAGE nolfaris
             DEPENDS_ANTLR SampleGrammarLexer)

# include generated files in project environment
include_directories(${ANTLR_SampleGrammarLexer_OUTPUT_DIR})
include_directories(${ANTLR_SampleGrammarParser_OUTPUT_DIR})

# Add the data files
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/data/grammar_rules.json ${CMAKE_CURRENT_BINARY_DIR}/src/data/grammar_rules.json COPYONLY) 
add_definitions("-DGRAMMAR_JSON=\"${CMAKE_CURRENT_BINARY_DIR}/src/data/grammar_rules.json\"")

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/data/errors.json ${CMAKE_CURRENT_BINARY_DIR}/src/data/errors.json COPYONLY) 
add_definitions("-DERRORS_JSON=\"${CMAKE_CURRENT_BINARY_DIR}/src/data/errors.json\"")

# Add source to this project's executable.

set ( TARGET_H 
    "src/headers/error.h"
    "src/headers/nobject.h"
    "src/headers/tools.hpp" 
)

set ( TARGET_SRC
    "src/cpp/main.cpp"
    "src/cpp/error.cpp"
    "src/cpp/nobject.cpp"
    "src/cpp/tools.cpp"
)

set ( DEPENDENCIES_SRC
    "src/standalone_libs/json.hpp"
)

add_executable (Nolfaris 
    ${TARGET_SRC} 
    ${TARGET_H} 
    ${DEPENDENCIES_SRC} 
    ${ANTLR_SampleGrammarLexer_CXX_OUTPUTS}
    ${ANTLR_SampleGrammarParser_CXX_OUTPUTS}
)

# add generated grammar to demo binary target
target_link_libraries(Nolfaris antlr4_static ${Boost_LIBRARIES})