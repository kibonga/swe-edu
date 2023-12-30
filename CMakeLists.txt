cmake_minimum_required(VERSION 3.26)
project(swe_edu)

set(CMAKE_CXX_STANDARD 17)

add_executable(swe_edu main.cpp
        week1/1-two-pointers/valid-palindrome/valid-palindrome.h
        week1/1-two-pointers/valid-palindrome/valid-palindrome.cpp
        week1/1-two-pointers/sum-of-three-values/sum-of-three-values.cpp
        week1/1-two-pointers/sum-of-three-values/sum-of-three-values.h)
