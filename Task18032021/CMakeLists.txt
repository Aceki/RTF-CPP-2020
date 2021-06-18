cmake_minimum_required(VERSION 3.10)

project(SmartPointers)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

enable_testing()

find_package(GTest CONFIG REQUIRED)

add_subdirectory(lib/pointers)
add_subdirectory(tests)

add_executable(prog main.cpp)

target_link_libraries(prog pointers)
