# CMakeList.txt : CMake project for Nolfaris, include source and define
# project specific logic here.
cmake_minimum_required (VERSION 3.8)

# add boost
find_package(Boost 1.69.0 COMPONENTS regex)
include_directories(${Boost_INCLUDE_DIRS})

# add rapidjson
find_package(RapidJSON)

# add the data files
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data/grammar_rules.json DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/data)
add_definitions("-DGRAMMAR_JSON=\"${CMAKE_CURRENT_BINARY_DIR}/data/grammar_rules.json\"")

# Add source to this project's executable.
add_executable (Nolfaris "cpp/main.cpp" "cpp/nobject.cpp" "cpp/tools.cpp" "headers/nobject.h" "headers/tools.h")

# link libraries
target_link_libraries(Nolfaris ${Boost_LIBRARIES})

