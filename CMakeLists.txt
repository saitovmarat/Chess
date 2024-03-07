cmake_minimum_required(VERSION 3.1.0)

project(chess VERSION 1.0)

# Global CMake options
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

# Configure Qt
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Test REQUIRED)

# Testing configuration
enable_testing()
set(TEST_LINK_LIBRARIES Qt5::Test)

add_subdirectory(src)
