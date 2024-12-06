cmake_minimum_required(VERSION 3.10)
project(DoublyLinkedList C)

# Set output directories for binaries and libraries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Export compile commands for tools like clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Source files
set(SOURCES
    ${CMAKE_SOURCE_DIR}/lib/lib.c
    ${CMAKE_SOURCE_DIR}/src/main.c
)

# Create the executable
add_executable(doubly_linked_list ${SOURCES})
