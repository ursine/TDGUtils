cmake_minimum_required(VERSION 2.8)

project(TDGUtils)

enable_testing()

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
    "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(warnings "-Wall -Wextra -Werror")
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(third_party)
