cmake_minimum_required(VERSION 2.8)

project(String)

if (MSVC)
    add_definitions(/W4)
else()
    add_definitions(-Wall)
    add_definitions(-std=c++11)
endif()

include_directories(Catch/include)
include_directories(include)



set(SOURCES src/string.cpp)

add_executable(String ${SOURCES})

