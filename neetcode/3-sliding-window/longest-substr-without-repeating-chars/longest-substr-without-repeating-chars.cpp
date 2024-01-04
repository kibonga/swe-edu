#include "longest-substr-without-repeating-chars.h"

int lengthOfLongestSubstr2(string &s) {
    set<char> set;
    int max = 0, j, i;

    for(i=0, j=0; i<s.size(); i++) {
        if(set.find(s[i]) == set.end()) {
            set.insert(s[i]);
            continue;
        }
        max = max >= (i-j) ? max : (i-j);
        while(set.find(s[i]) != set.end()) {
            set.erase(s[j++]);
        }
        set.insert(s[i]);
    }

    return std::max(max, static_cast<int>(set.size()));
}

int lengthOfLongestSubstr(string &s) {
    if(s.size() < 2) {
        return s.size();
    }

    set<char> set;
    int len = 0, i, j;

    for(i=0, j=0; i<s.size(); i++) {
        if(set.find(s[i]) != set.end()) {
            len = std::max(len, (i-j));
            while(set.find(s[i]) != set.end()) {
                set.erase(s[j++]);
            }
        }
        set.insert(s[i]);
    }

    return std::max(len, (int)set.size());
}

void runLongestSubstrWithoutRepeatingChars() {
    string input1 = "abcabcbb";
    string input2 = "bbbbbb";
    string input3 = "pwwkew";

    cout << "Longest substring = " << lengthOfLongestSubstr(input1) << endl;
    cout << "Longest substring = " << lengthOfLongestSubstr(input2) << endl;
    cout << "Longest substring = " << lengthOfLongestSubstr(input3) << endl;
}
