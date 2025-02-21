cmake_minimum_required(VERSION 3.20)


add_subdirectory(vendored/SDL-release-3.2.4 EXCLUDE_FROM_ALL)

project(tdgutils VERSION 1.0  
                 DESCRIPTION "Experiments with 3D" 
                 LANGUAGES CXX)

add_executable(tdgutils main.cpp)

target_link_libraries(tdgutils PRIVATE SDL3::SDL3)
