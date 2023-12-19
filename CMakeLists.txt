cmake_minimum_required(VERSION 3.28)
project(SubGame C)

find_package(raylib REQUIRED)

file(GLOB_RECURSE SRC src/*.c)

add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

target_include_directories(${PROJECT_NAME} PRIVATE ${RAYLIB_INCLUDE_DIRS})

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)