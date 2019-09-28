# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("Nolfaris")

# add json files
add_definitions("-GRAMMAR_JSON=\"${CMAKE_SOURCE_DIR}/src/data/grammar_rules.json\"")

# Include sub-projects.
add_subdirectory ("src")

