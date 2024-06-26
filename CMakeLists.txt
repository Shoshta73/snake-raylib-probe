cmake_minimum_required(VERSION 3.16)

project(snake LANGUAGES C CXX)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Debug)
endif()

if(CMAKE_BUILD_TYPE STREQUAL Debug)
    add_compile_definitions(DEBUG=1)
    add_compile_definitions(NDEBUG=0)
    add_compile_definitions(RELEASE=0)
elseif(CMAKE_BUILD_TYPE STREQUAL Release)
    add_compile_definitions(DEBUG=0)
    add_compile_definitions(NDEBUG=1)
    add_compile_definitions(RELEASE=1)
endif()

add_subdirectory(vendor/raylib)

set (SNAKE_SRC src/main.cc src/Food.cc)

add_executable(${PROJECT_NAME} ${SNAKE_SRC})
add_dependencies(${PROJECT_NAME} raylib)
target_link_libraries(${PROJECT_NAME} raylib)
