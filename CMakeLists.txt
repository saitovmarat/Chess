cmake_minimum_required(VERSION 3.1.0)

project(Chess VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Threads REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(Chess
    mainwindow.ui
    mainwindow.cpp
    main.cpp
    # resources.qrc
)

target_link_libraries(Chess 
    PRIVATE
        Qt5::Widgets
        Threads::Threads
        )