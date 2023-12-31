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
        neetcode/2-two-pointers/4-sum/4-sum.cpp
        neetcode/2-two-pointers/rotate-array/rotate-array.cpp
        neetcode/2-two-pointers/rotate-array/rotate-array.h
        neetcode/2-two-pointers/arr-with-elems-not-equal-to-avg-of-neighbors/arr-with-elems-not-equal-to-avg-of-neighbors.cpp
        neetcode/2-two-pointers/arr-with-elems-not-equal-to-avg-of-neighbors/arr-with-elems-not-equal-to-avg-of-neighbors.h
        neetcode/2-two-pointers/number-of-subseqences-satisfying-sum-condition/number-of-subseqences-satisfying-sum-condition.h
        neetcode/2-two-pointers/number-of-subseqences-satisfying-sum-condition/number-of-subseqences-satisfying-sum-condition.cpp
        neetcode/2-two-pointers/remove-duplicates-from-sorted-arr-2/remove-duplicates-from-sorted-arr-2.cpp
        neetcode/2-two-pointers/remove-duplicates-from-sorted-arr-2/remove-duplicates-from-sorted-arr-2.h
        neetcode/2-two-pointers/2sum/2sum.cpp
        neetcode/2-two-pointers/2sum/2sum.h
        neetcode/2-two-pointers/3sum/3sum.cpp
        neetcode/2-two-pointers/3sum/3sum.h
        neetcode/2-two-pointers/boats-to-save-people/boats-to-save-people.cpp
        neetcode/2-two-pointers/boats-to-save-people/boats-to-save-people.h
        neetcode/3-sliding-window/num-of-sub-arr-of-size-K-and-avg-greater-than-or-eq-to-threshold/num-of-sub-arr-of-size-K-and-avg-greater-than-or-eq-to-threshold.cpp
        neetcode/3-sliding-window/num-of-sub-arr-of-size-K-and-avg-greater-than-or-eq-to-threshold/num-of-sub-arr-of-size-K-and-avg-greater-than-or-eq-to-threshold.h
        neetcode/3-sliding-window/longest-substr-without-repeating-chars/longest-substr-without-repeating-chars.cpp
        neetcode/3-sliding-window/longest-substr-without-repeating-chars/longest-substr-without-repeating-chars.h
        neetcode/3-sliding-window/longest-repeating-char-replacment/longest-repeating-char-replacment.cpp
        neetcode/3-sliding-window/longest-repeating-char-replacment/longest-repeating-char-replacment.h
        neetcode/3-sliding-window/permutation-in-string/permutation-in-string.cpp
        neetcode/3-sliding-window/permutation-in-string/permutation-in-string.h
        neetcode/3-sliding-window/fruit-into-baskets/fruit-into-baskets.cpp
        neetcode/3-sliding-window/fruit-into-baskets/fruit-into-baskets.h
        neetcode/3-sliding-window/max-num-of-vowels-in-a-substring-of-given-length/max-num-of-vowels-in-a-substring-of-given-length.cpp
        neetcode/3-sliding-window/max-num-of-vowels-in-a-substring-of-given-length/max-num-of-vowels-in-a-substring-of-given-length.h
        neetcode/3-sliding-window/min-size-subarr-sum/min-size-subarr-sum.cpp
        neetcode/3-sliding-window/min-size-subarr-sum/min-size-subarr-sum.h
        neetcode/3-sliding-window/find-k-closest-elems/find-k-closest-elems.cpp
        neetcode/3-sliding-window/find-k-closest-elems/find-k-closest-elems.h
        neetcode/1-arrays-and-hashing/fundamentals/contains-duplicates/contains-duplicates.cpp
        neetcode/1-arrays-and-hashing/fundamentals/contains-duplicates/contains-duplicates.h
        neetcode/1-arrays-and-hashing/fundamentals/valid-anagram/valid-anagram.cpp
        neetcode/1-arrays-and-hashing/fundamentals/valid-anagram/valid-anagram.h
        neetcode/1-arrays-and-hashing/fundamentals/concatenation-of-arr/concatenation-of-arr.cpp
        neetcode/1-arrays-and-hashing/fundamentals/concatenation-of-arr/concatenation-of-arr.h
        neetcode/1-arrays-and-hashing/fundamentals/replace-elems-with-greatest-elem-on-right-side/replace-elems-with-greatest-elem-on-right-side.cpp
        neetcode/1-arrays-and-hashing/fundamentals/replace-elems-with-greatest-elem-on-right-side/replace-elems-with-greatest-elem-on-right-side.h
        neetcode/1-arrays-and-hashing/fundamentals/is-subsequence/is-subsequence.cpp
        neetcode/1-arrays-and-hashing/fundamentals/is-subsequence/is-subsequence.h
        neetcode/1-arrays-and-hashing/fundamentals/length-of-last-word/length-of-last-word.cpp
        neetcode/1-arrays-and-hashing/fundamentals/length-of-last-word/length-of-last-word.h
        neetcode/1-arrays-and-hashing/fundamentals/longest-common-prefix/longest-common-prefix.cpp
        neetcode/1-arrays-and-hashing/fundamentals/longest-common-prefix/longest-common-prefix.h
        neetcode/1-arrays-and-hashing/fundamentals/pascals-triangle/pascals-triangle.cpp
        neetcode/1-arrays-and-hashing/fundamentals/pascals-triangle/pascals-triangle.h
        neetcode/1-arrays-and-hashing/fundamentals/remove-element/remove-element.cpp
        neetcode/1-arrays-and-hashing/fundamentals/remove-element/remove-element.h
        neetcode/1-arrays-and-hashing/fundamentals/unique-email-addr/unique-email-addr.cpp
        neetcode/1-arrays-and-hashing/fundamentals/unique-email-addr/unique-email-addr.h
        neetcode/1-arrays-and-hashing/fundamentals/isomorphic-strings/isomorphic-strings.cpp
        neetcode/1-arrays-and-hashing/fundamentals/isomorphic-strings/isomorphic-strings.h
        neetcode/1-arrays-and-hashing/fundamentals/can-place-flowers/can-place-flowers.cpp
        neetcode/1-arrays-and-hashing/fundamentals/can-place-flowers/can-place-flowers.h
        neetcode/1-arrays-and-hashing/fundamentals/majority-elem/majority-elem.cpp
        neetcode/1-arrays-and-hashing/fundamentals/majority-elem/majority-elem.h
        neetcode/1-arrays-and-hashing/fundamentals/next-greater-elem-1/next-greater-elem-1.cpp
        neetcode/1-arrays-and-hashing/fundamentals/next-greater-elem-1/next-greater-elem-1.h
        neetcode/1-arrays-and-hashing/fundamentals/find-pivot-index/find-pivot-index.cpp
        neetcode/1-arrays-and-hashing/fundamentals/find-pivot-index/find-pivot-index.h
        neetcode/1-arrays-and-hashing/fundamentals/range-sum-query-immutable/range-sum-query-immutable.cpp
        neetcode/1-arrays-and-hashing/fundamentals/range-sum-query-immutable/range-sum-query-immutable.h
        neetcode/1-arrays-and-hashing/fundamentals/find-all-nums-disappeared-in-arr/find-all-nums-disappeared-in-arr.cpp
        neetcode/1-arrays-and-hashing/fundamentals/find-all-nums-disappeared-in-arr/find-all-nums-disappeared-in-arr.h
        neetcode/1-arrays-and-hashing/fundamentals/max-num-of-ballons/max-num-of-ballons.cpp
        neetcode/1-arrays-and-hashing/fundamentals/max-num-of-ballons/max-num-of-ballons.h
        neetcode/1-arrays-and-hashing/fundamentals/word-pattern/word-pattern.cpp
        neetcode/1-arrays-and-hashing/fundamentals/word-pattern/word-pattern.h
        neetcode/1-arrays-and-hashing/medium/sort-arr/sort-arr.cpp
        neetcode/1-arrays-and-hashing/medium/sort-arr/sort-arr.h
        neetcode/1-arrays-and-hashing/medium/sort-arr-merge-sort/sort-arr-merge-sort.cpp
        neetcode/1-arrays-and-hashing/medium/sort-arr-merge-sort/sort-arr-merge-sort.h
        neetcode/1-arrays-and-hashing/medium/heap-sort/heap-sort.cpp
        neetcode/1-arrays-and-hashing/medium/heap-sort/heap-sort.h
        neetcode/1-arrays-and-hashing/medium/merge-sort/merge-sort.cpp
        neetcode/1-arrays-and-hashing/medium/merge-sort/merge-sort.h
)