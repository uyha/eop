cmake_minimum_required(VERSION 3.8)
project("Elements of Programming"
        VERSION 0.0
        LANGUAGES CXX)

add_executable(main "main.cpp")
target_compile_features(main PRIVATE cxx_std_20)
