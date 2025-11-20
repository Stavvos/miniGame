cmake_minimum_required(VERSION 3.24)
project(game)

set(CMAKE_CXX_STANDARD 11)

set(RAYLIB_DIR "${CMAKE_SOURCE_DIR}/raylib")

add_subdirectory(${RAYLIB_DIR})

set(SOURCE_FILES
    main.c
    types.c)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} raylib)
