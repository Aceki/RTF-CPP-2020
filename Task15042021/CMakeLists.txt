cmake_minimum_required(VERSION 3.5)

project(TicTacToe)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

link_libraries(Qt${QT_VERSION_MAJOR}::Widgets)

add_subdirectory(TicTacToe.Model)
#add_subdirectory(TicTacToe.Controller)
add_subdirectory(TicTacToe.View)
