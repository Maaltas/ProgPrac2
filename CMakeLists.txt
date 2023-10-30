cmake_minimum_required(VERSION 3.26)
project(untitled)

set(CMAKE_CXX_STANDARD 17)
include_directories(Headers/Include)

add_executable(untilted
        Source/main.cpp
        Source/src/Contenidor.cpp
        Source/src/Element.cpp
        Source/src/Seleccio.cpp)
