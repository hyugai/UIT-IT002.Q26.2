cmake_minimum_required(VERSION 3.23)

project(bt3)

add_subdirectory(include)
add_subdirectory(src)

add_executable(main)
target_sources(main PRIVATE main.cpp)
target_link_libraries(main PRIVATE bt3Lib)
