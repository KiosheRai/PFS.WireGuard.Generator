cmake_minimum_required(VERSION 3.12)

set(CORE_PROJECT_NAME PFS.WireGuard.Generator.Core)

set(CORE_PUBLIC_INCLUDES
    includes/Models/Server.hpp
    includes/Models/Client.hpp

    includes/Configurator/Configurator.hpp
    includes/Configurator/Block.hpp
    includes/Configurator/FileIO.hpp


    includes/ExportLibrary/PFSWireGuardGeneratorCoreAPI.hpp
)

set(CORE_PRIVATE_SOURCES
    src/Models/Server.cpp
    src/Models/Client.cpp

    src/Configurator/Configurator.cpp
    src/Configurator/Block.cpp
    src/Configurator/FileIO.cpp

    src/ExportLibrary/PFSWireGuardGeneratorCoreAPI.cpp
    src/ExportLibrary/dllmain.cpp
)

add_library(${CORE_PROJECT_NAME} SHARED
    ${CORE_PUBLIC_INCLUDES}
    ${CORE_PRIVATE_SOURCES}
)

message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message(STATUS "CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")

if (WIN32)
    set(UI_BINARY_DIR "$<CONFIG>") #CHANGE FOR WINDOWS!!!
else()
    set(UI_BINARY_DIR "$/bin")
endif()

add_custom_command(TARGET ${CORE_PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:${CORE_PROJECT_NAME}> ${CMAKE_BINARY_DIR}/${UI_BINARY_DIR}
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES
    ${CORE_PUBLIC_INCLUDES}
    ${CORE_PRIVATE_SOURCES}
)

target_include_directories(${CORE_PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes)
target_include_directories(${CORE_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_compile_features(${CORE_PROJECT_NAME} PUBLIC cxx_std_17)

target_compile_definitions(${CORE_PROJECT_NAME} PRIVATE PFSWGGENERATORCORE_EXPORTS)

add_custom_command(TARGET ${CORE_PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:${CORE_PROJECT_NAME}> ${UI_BINARY_DIR}
)
