# CMakeList.txt : CMake project for Nolfaris, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# add boost
find_package(Boost 1.69.0 COMPONENTS regex xpressive)
include_directories(${Boost_INCLUDE_DIRS})

# Add source to this project's executable.
add_executable (Nolfaris "main.cpp")

# link libraries
target_link_libraries(Nolfaris ${Boost_LIBRARIES})

