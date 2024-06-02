cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(MachstickGame CXX)

set(SOURCE_EXE main.cpp)
set(LIB ../libgame.a)

add_executable(${PROJECT_NAME} ${SOURCE_EXE})

add_library(libgame STATIC IMPORTED)
set_target_properties(libgame PROPERTIES IMPORTED_LOCATION ${LIB})

target_link_libraries(${PROJECT_NAME} libgame)