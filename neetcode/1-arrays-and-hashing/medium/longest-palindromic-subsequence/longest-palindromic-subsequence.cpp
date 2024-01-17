#include "longest-palindromic-subsequence.h"

int longestPalindromeSubsequence(string &s) {
    unordered_map<char, int> map;
    int i = 0, j = s.size()-1;
    int longestSeq = 0;

    for(char c : s) {
        map[c]++;
    }



    return longestSeq;
}

void runLongestPalindromeSubsequenceExample() {
    string s1 = "bbbab";
    cout << "Longest palindromic subsequence = " << longestPalindromeSubsequence(s1) << endl;
}
