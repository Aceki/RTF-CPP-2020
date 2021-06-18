set(SOURCES string_with_mv.cpp string_without_mv.cpp)
set(HEADERS string_with_mv.h   string_without_mv.h)

add_library(strings ${SOURCES} ${HEADERS})

target_include_directories(strings PUBLIC .)
