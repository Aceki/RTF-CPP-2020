set(HEADERS physical_quantity.h   force.h   pressure.h   area.h)
set(SOURCES physical_quantity.cpp force.cpp pressure.cpp area.cpp)

add_library(physics STATIC ${HEADERS} ${SOURCES})

target_include_directories(physics INTERFACE . PUBLIC ../exceptions)