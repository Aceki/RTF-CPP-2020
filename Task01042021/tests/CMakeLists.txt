set(SOURCES main.cpp string_without_mv_tests.cpp string_with_mv_tests.cpp)

add_executable(runTests ${SOURCES})

target_link_libraries(runTests gtest gtest_main rt pthread strings)
