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
    src/main.cpp
    src/main.h

    src/square/square.h
    src/square/square.cpp

    src/board/board.cpp
    src/board/board.h
    src/boardRenderer/boardRenderer.cpp
    src/boardRenderer/boardRenderer.h

    src/piece/piece.cpp
    src/piece/piece.h
    src/piece/bishop/bishop.cpp
    src/piece/bishop/bishop.h
    src/piece/king/king.cpp
    src/piece/king/king.h
    src/piece/knight/knight.cpp
    src/piece/knight/knight.h
    src/piece/pawn/pawn.cpp
    src/piece/pawn/pawn.h
    src/piece/queen/queen.cpp
    src/piece/queen/queen.h
    src/piece/rook/rook.cpp
    src/piece/rook/rook.h

    resources/images.qrc
)

add_executable(${TARGET_NAME}
    ${PROJECT_SOURCES}
)

target_link_libraries(${TARGET_NAME} PRIVATE Qt5::Widgets)

target_include_directories(${TARGET_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/board
    ${CMAKE_CURRENT_SOURCE_DIR}/src/boardRenderer
    ${CMAKE_CURRENT_SOURCE_DIR}/src/square
    ${CMAKE_CURRENT_SOURCE_DIR}/src/piece
    ${CMAKE_CURRENT_SOURCE_DIR}/src/piece/bishop
    ${CMAKE_CURRENT_SOURCE_DIR}/src/piece/king
    ${CMAKE_CURRENT_SOURCE_DIR}/src/piece/knight
    ${CMAKE_CURRENT_SOURCE_DIR}/src/piece/pawn
    ${CMAKE_CURRENT_SOURCE_DIR}/src/piece/queen
    ${CMAKE_CURRENT_SOURCE_DIR}/src/piece/rook
    ${CMAKE_CURRENT_SOURCE_DIR}/resources
    ${CMAKE_CURRENT_SOURCE_DIR}/resources/images
)
