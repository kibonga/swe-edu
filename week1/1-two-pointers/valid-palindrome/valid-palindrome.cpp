#include "valid-palindrome.h"
#include <iostream>

bool isPalindrome(string s) {
    int l = 0, r = s.length() - 1;
    while(l < r) {
        if(s[l++] == s[r--]) {
            continue;
        }
        return false;
    }
    return true;
}

void runPalindromeExample() {
    string input = "kayak";
    cout << "Is palindrome = " << isPalindrome(input) << endl;
}