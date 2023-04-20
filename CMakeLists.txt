cmake_minimum_required(VERSION 3.25)
project(TransactionDiscounts VERSION 1.0)

# C++ standard
set(CMAKE_CXX_STANDARD 17)

# Including directories
include_directories(src)

# Adding source files from src directory, excluding main.cpp and tests
file(GLOB_RECURSE SOURCES "src/*.cpp")
list(REMOVE_ITEM SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")

# Removing CMakeFiles from the list of source files
list(FILTER SOURCES EXCLUDE REGEX "CMakeFiles")

# Creating a library from the source files
add_library(graph_lib STATIC ${SOURCES} src/Application/Application.cpp)

# Adding executable of the project
add_executable(GraphIterators src/main.cpp)

# Linking the library to the executable
target_link_libraries(GraphIterators graph_lib)
