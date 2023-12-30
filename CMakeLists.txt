cmake_minimum_required(VERSION 3.26)
project(swe_edu)

set(CMAKE_CXX_STANDARD 17)

add_executable(swe_edu main.cpp
        week1/1-two-pointers/valid-palindrome/valid-palindrome.h
        week1/1-two-pointers/valid-palindrome/valid-palindrome.cpp
        week1/1-two-pointers/sum-of-three-values/sum-of-three-values.cpp
        week1/1-two-pointers/sum-of-three-values/sum-of-three-values.h
        week1/2-fast-and-slow-pointers/happy-number/happy-number.h
        week1/2-fast-and-slow-pointers/happy-number/happy-number.cpp
        week1/2-fast-and-slow-pointers/linked-list-cycle/linked-list-cycle.h
        week1/2-fast-and-slow-pointers/linked-list-cycle/linked-list-cycle.cpp
        week1/3-stacks/remove-all-adjacent-duplicates-in-string/remove-all-adjacent-duplicates-in-string.h
        week1/3-stacks/remove-all-adjacent-duplicates-in-string/remove-all-adjacent-duplicates-in-string.cpp)
