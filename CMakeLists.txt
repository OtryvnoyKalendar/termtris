# Указываем минимальную версию CMake
cmake_minimum_required(VERSION 3.10)

# Устанавливаем имя проекта
project(MyProject)

# Указываем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Указываем директорию с исходными файлами
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")

# Функция для поиска всех .cpp и .hpp файлов в заданной директории
function(add_sources_from_directory dir)
    file(GLOB_RECURSE SOURCES "${dir}/*.cpp")
    file(GLOB_RECURSE HEADERS "${dir}/*.hpp")
    list(APPEND ALL_SOURCES ${SOURCES} ${HEADERS})
endfunction()

# Добавляем исходные файлы из всех поддиректорий
add_sources_from_directory("${SOURCE_DIR}/core")
add_sources_from_directory("${SOURCE_DIR}/game")
add_sources_from_directory("${SOURCE_DIR}/graphic")
add_sources_from_directory("${SOURCE_DIR}/soloheader")

# Добавляем основной файл
list(APPEND ALL_SOURCES "${SOURCE_DIR}/main.cpp")

# Создаем исполняемый файл
add_executable(MyExecutable ${ALL_SOURCES})

# Если нужно, можно добавить дополнительные библиотеки или зависимости
# target_link_libraries(MyExecutable <libraries>)




#[[
cmake_minimum_required(VERSION 3.15)

project(mycprog)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Определите директорию src
set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)

# Укажите директории с исходными файлами
include_directories(
    ${PROJECT_SOURCE_DIR}/core
    ${PROJECT_SOURCE_DIR}/game
    ${PROJECT_SOURCE_DIR}/graphic
    ${PROJECT_SOURCE_DIR}/soloheader
)

message("PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")

file(GLOB CPPS "./**/*.cpp")
file(GLOB HPPS "./**/*.hpp")

add_executable(${PROJECT_NAME} ${CPPS} ${HPPS})
]]

