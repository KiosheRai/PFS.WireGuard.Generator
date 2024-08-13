cmake_minimum_required(VERSION 3.12)

set(CORE_PROJECT_NAME PFS.WireGuard.Generator.Core)

set(CORE_PUBLIC_INCLUDES
    ${CMAKE_CURRENT_SOURCE_DIR}/includes/Models/Server.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/includes/Models/Client.hpp
)

set(CORE_PRIVATE_INCLUDES

)

set(CORE_PRIVATE_SOURSES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/Server.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/Client.cpp
)

set(CORE_ALL_SOURCES
    ${CORE_PUBLIC_INCLUDES}
    ${CORE_PRIVATE_INCLUDES}
    ${CORE_PRIVATE_SOURSES}
)

add_library(${CORE_PROJECT_NAME} SHARED
    ${CORE_ALL_SOURCES}
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES
    ${CORE_ALL_SOURCES}
)

target_include_directories(${CORE_PROJECT_NAME} PUBLIC includes)
target_include_directories(${CORE_PROJECT_NAME} PRIVATE src)

target_compile_features(${CORE_PROJECT_NAME} PUBLIC cxx_std_17)

