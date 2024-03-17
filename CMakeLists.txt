cmake_minimum_required(VERSION 3.5)

set(TARGET_NAME Chess)
project(${TARGET_NAME} VERSION 1.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
    src/mainwindow.cpp
    src/mainwindow.ui
    src/main.cpp
    src/main.h
    src/chessBoard/chessBoard.cpp
    src/chessBoard/chessBoard.h
    src/chessBoardSquare/square.h
    src/chessBoardSquare/square.cpp
    src/chessPiece/chessPiece.cpp
    src/chessPiece/chessPiece.h
    resources/images.qrc
)

add_executable(${TARGET_NAME}
    ${PROJECT_SOURCES}
)

target_link_libraries(${TARGET_NAME} PRIVATE Qt5::Widgets)

target_include_directories(${TARGET_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/chessBoard
    ${CMAKE_CURRENT_SOURCE_DIR}/src/chessBoardSquare
    ${CMAKE_CURRENT_SOURCE_DIR}/src/chessPiece
    ${CMAKE_CURRENT_SOURCE_DIR}/resources
    ${CMAKE_CURRENT_SOURCE_DIR}/resources/images
)
