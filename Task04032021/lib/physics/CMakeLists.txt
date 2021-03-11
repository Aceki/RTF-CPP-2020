set(HEADERS physical_quantity.h   power.h   pressure.h   area.h)
set(HEADERS physical_quantity.cpp power.cpp pressure.cpp area.cpp)

add_library(physics STATIC ${HEADERS} ${SOURCES})

target_link_libraries(physics PRIVATE exceptions)

target_include_directories(physics INTERFACE .)