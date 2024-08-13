cmake_minimum_required(VERSION 3.12)
project(PFS.WireGuard.Generator)

set(PROJECT_NAME PFS.WireGuard.Generator)

add_subdirectory(PFS.WireGuard.Generator.UI)
add_subdirectory(PFS.WireGuard.Generator.Core)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
