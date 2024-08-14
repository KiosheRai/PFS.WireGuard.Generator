cmake_minimum_required(VERSION 3.12)

set(CORE_PROJECT_NAME PFS.WireGuard.Generator.Core)

set(CORE_PUBLIC_INCLUDES
    includes/Models/Server.hpp
    includes/Models/Client.hpp

    includes/Configurator/Configurator.hpp
    includes/Configurator/Block.hpp
    includes/Configurator/FileIO.hpp
)

set(CORE_PRIVATE_INCLUDES

)

set(CORE_PRIVATE_SOURSES
    src/Models/Server.cpp
    src/Models/Client.cpp

    src/Configurator/Configurator.cpp
    src/Configurator/Block.cpp
    src/Configurator/FileIO.cpp
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

