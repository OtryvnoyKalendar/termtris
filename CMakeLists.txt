cmake_minimum_required(VERSION 3.15)

project(mycprog)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(
    -Wall -Wextra -pedantic
)

include_directories(src/include)
include_directories(src/core)
include_directories(src/game)
include_directories(src/graphic)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../cmakebin)

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/**/*.cpp")

add_executable(${PROJECT_NAME} src/main.cpp ${SOURCES})
#message("PROJECT_SOURCE_DIR: ${SOURCES}")

target_link_libraries(${PROJECT_NAME} ncursesw)

