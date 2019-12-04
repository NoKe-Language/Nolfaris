# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("Nolfaris")

# add boost
find_package(Boost 1.69.0 COMPONENTS regex program_options)
include_directories(${Boost_INCLUDE_DIRS})

# add json
# find_package(nlohmann_json 3.2.0 REQUIRED)

# Add the data files
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/data/grammar_rules.json ${CMAKE_CURRENT_BINARY_DIR}/src/data/grammar_rules.json COPYONLY) 
add_definitions("-DGRAMMAR_JSON=\"${CMAKE_CURRENT_BINARY_DIR}/src/data/grammar_rules.json\"")

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/data/errors.json ${CMAKE_CURRENT_BINARY_DIR}/src/data/errors.json COPYONLY) 
add_definitions("-DERRORS_JSON=\"${CMAKE_CURRENT_BINARY_DIR}/src/data/errors.json\"")

# Add source to this project's executable.

set ( TARGET_H 
    "src/headers/error.hpp"
    "src/headers/nobject.hpp"
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

add_executable (Nolfaris ${TARGET_SRC} ${TARGET_H} ${DEPENDENCIES_SRC})

# enable c++ 17
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

# link libraries
# set (json_LIBRARIES PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(Nolfaris ${Boost_LIBRARIES})
