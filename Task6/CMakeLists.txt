cmake_minimum_required(VERSION 3.17)
project(Task6)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(Task6 main.cpp)

target_link_libraries(Task6 sfml-graphics sfml-audio)