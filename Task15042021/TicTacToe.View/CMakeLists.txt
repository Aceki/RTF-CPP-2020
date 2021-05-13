project(TicTacToe.View LANGUAGES CXX)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(View
        ${PROJECT_SOURCES}
    )
else()
    add_executable(View
        ${PROJECT_SOURCES}
    )
endif()

#target_link_libraries(View PRIVATE Controller)
target_link_libraries(View PRIVATE Model)
