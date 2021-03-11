set(HEADERS exception.h   logic_exception.h)
set(SOURCES exception.cpp logic_exception.cpp)

add_library(exceptions STATIC ${HEADERS} ${SOURCES})

target_include_directories(exceptions INTERFACE .)