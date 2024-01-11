#include "unique-len-3-palindromic-subsequence.h"

int countPalindromicSubsequence(string s) {
    unordered_map<char, int> rightMap;
    unordered_set<char> leftSet;
    unordered_set<string> result;

    if(s.size() < 3) {
        return -1;
    }

    for(int i=1; i<s.size(); i++) {
        rightMap[s[i]]++;
    }

    char c, r;
    leftSet.insert(s[0]);
    for(int i=1; i<s.size()-1; i++) {
        c = s[i];
        rightMap[c]--;
        if(rightMap[c] == 0) {
            rightMap.erase(c);
        }
        for(int j=0; j<26; j++) {
            r = 'a' + j;
            if(leftSet.find(r) != leftSet.end() &&
                rightMap.find(r) != rightMap.end()) {
                result.insert(string(1, r) + c + r);
            }
        }
        leftSet.insert(c);
    }

    return result.size();
}

void runUniqueLength3PalindromicSubsequencesExample() {
    string s1 = "aabca"; // 3
    string s2 = "ckafnafqo"; // 4
    cout << "Number of unique palindromic subsequences = " << countPalindromicSubsequence(s1) << endl;
    cout << "Number of unique palindromic subsequences = " << countPalindromicSubsequence(s2) << endl;
}
