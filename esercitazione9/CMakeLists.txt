cmake_minimum_required(VERSION 3.20)
project(esercitazione9)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

add_executable(grafi grafi.cpp unidirected_edge.hpp visita_grafi.hpp)
add_test(NAME grafi COMMAND grafi)

enable_testing()