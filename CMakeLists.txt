cmake_minimum_required(VERSION 3.8)

project(demo)

find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main)

enable_testing()

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
    "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(warnings "-Wall -Wextra -Werror")
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(third_party)

add_executable(demo src/main.cpp
        src/TDGApplication.cpp
        include/TDGApplication.h
        include/TDGExceptions.h
        include/TDGSDLEventsDebugging.h
        include/TDGReflection.h)
target_compile_features(demo INTERFACE cxx_std_20)

set_property(TARGET demo PROPERTY CXX_STANDARD 23)

if(TARGET SDL2::SDL2main)
    target_link_libraries(demo PRIVATE SDL2::SDL2main)
endif()

target_link_libraries(demo PRIVATE SDL2::SDL2)