cmake_minimum_required(VERSION 3.0)

project(MoveSemantic)

option(DEBUG true)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

enable_testing()

find_package(GTest CONFIG REQUIRED)

add_subdirectory(lib)
add_subdirectory(tests)

add_executable(prog main.cpp)

target_link_libraries(prog PRIVATE strings)
