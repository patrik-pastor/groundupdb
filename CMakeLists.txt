cmake_minimum_required(VERSION 3.20.0)
project(groundupdb)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(THIRD_PARTY_DIRECTORY ${CMAKE_SOURCE_DIR}/third_party)

include_directories(.)

add_subdirectory(groundupdb/main)
