cmake_minimum_required(VERSION 3.22)

project(game VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SOURCES CONFIGURE_DEPENDS src/*.cpp)

add_subdirectory(raylib)
include_directories(raylib/src)

add_executable(${PROJECT_NAME} WIN32 ${SOURCES})
target_link_libraries(${PROJECT_NAME} raylib)