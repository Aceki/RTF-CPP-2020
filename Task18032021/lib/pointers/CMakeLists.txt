add_library(pointers STATIC shared_pointer.cpp unique_pointer.cpp)

target_include_directories(pointers PUBLIC .)