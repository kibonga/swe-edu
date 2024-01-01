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
        week1/3-stacks/remove-all-adjacent-duplicates-in-string/remove-all-adjacent-duplicates-in-string.cpp
        week1/3-stacks/implement-queue-using-stack/implement-queue-using-stack.cpp
        week1/3-stacks/implement-queue-using-stack/implement-queue-using-stack.h
        week1/4-hash-maps/impl-string-hash-map/impl-string-hash-map.h
        week1/4-hash-maps/impl-string-hash-map/impl-string-hash-map.cpp
        neetcode/1-arrays-and-hashing/group-anagrams-by-freq/group-anagrams-by-freq.h
        neetcode/1-arrays-and-hashing/group-anagrams-by-freq/group-anagrams-by-freq.cpp
        neetcode/1-arrays-and-hashing/group-anagrams-by-sort/group-anagrams-by-sort.h
        neetcode/1-arrays-and-hashing/group-anagrams-by-sort/group-anagrams-by-sort.cpp
        neetcode/1-arrays-and-hashing/top-k-freq-elements/top-k-freq-elements.h
        neetcode/1-arrays-and-hashing/top-k-freq-elements/top-k-freq-elements.cpp
        neetcode/1-arrays-and-hashing/top-k-freq-elements-bucket-sort/top-k-freq-elements-bucket-sort.cpp
        neetcode/1-arrays-and-hashing/top-k-freq-elements-bucket-sort/top-k-freq-elements-bucket-sort.h
        neetcode/1-arrays-and-hashing/product-of-arr-except-self/product-of-arr-except-self.cpp
        neetcode/1-arrays-and-hashing/valid-sudoku/valid-sudoku.cpp
        neetcode/1-arrays-and-hashing/valid-sudoku/valid-sudoku.h
        neetcode/1-arrays-and-hashing/longest-consequtive-sequence/longest-consequtive-sequence.cpp
)