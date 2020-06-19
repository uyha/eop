cmake_minimum_required(VERSION 3.8)
project("Elements of Programming"
        VERSION 0.0
        LANGUAGES CXX)

SET(CMAKE_CXX_STANDARD 20)

include(CTest)

add_subdirectory(external)
add_subdirectory(src)

