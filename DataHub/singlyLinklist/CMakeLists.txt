# Minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Project name
project(LinkListProject C)

# Set the output directories for build files and others
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add the include directory for header files
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add the source files
set(SOURCES
    ${CMAKE_SOURCE_DIR}/lib/lib.c
    ${CMAKE_SOURCE_DIR}/src/main.c
)

# Define the executable (main application)
add_executable(linklist ${SOURCES})
