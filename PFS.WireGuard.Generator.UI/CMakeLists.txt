cmake_minimum_required(VERSION 3.12)

set(UI_PROJECT_NAME PFS.WireGuard.Generator.UI)

add_executable(${UI_PROJECT_NAME}
    src/main.cpp
)

target_link_libraries(${UI_PROJECT_NAME} PRIVATE PFS.WireGuard.Generator.Core)

target_compile_features(${UI_PROJECT_NAME} PUBLIC cxx_std_17)

set_target_properties(${UI_PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)
