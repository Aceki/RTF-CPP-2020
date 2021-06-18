set(SOURCES main.cpp shared_pointer_tests.cpp unique_pointer_tests.cpp)

add_executable(runTests ${SOURCES})

target_link_libraries(runTests gtest gtest_main rt pthread pointers)