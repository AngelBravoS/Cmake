cmake_minimum_required(VERSION 3.0)

project(cmake)

add_executable(cmake main.cpp)

install(TARGETS cmake RUNTIME DESTINATION bin)
