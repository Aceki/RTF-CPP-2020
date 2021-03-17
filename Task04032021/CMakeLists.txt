cmake_minimum_required(VERSION 3.0)

project(Task04032021)

set(BINARY_DIR ${CMAKE_BINARY_DIR})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BINARY_DIR}/lib)

add_subdirectory(lib)

add_executable(prog main.cpp)

target_link_libraries(prog physics)