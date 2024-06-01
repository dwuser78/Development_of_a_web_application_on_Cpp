cmake_minimum_required(VERSION 3.5)

project(MachstickGame CXX)

set(SOURCE_EXE main.cpp)

set(SOURCE_LIB game.cpp)

add_library(game STATIC ${SOURCE_LIB})

add_executable(${PROJECT_NAME} ${SOURCE_EXE})

target_link_libraries(${PROJECT_NAME} game)