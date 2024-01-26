#include "longest-repeating-char-replacement.h"

int characterReplacementMedium(string s, int k) {
    vector<int> mp(26);
    int maxFreq = 0;
    int maxLen = 0;
    int l;

    for(int i=0, j=0; j<s.size(); j++) {
        mp[s[j]-'A']++;
        maxFreq = max(maxFreq, mp[s[j]-'A']);
        l = j - i + 1 - maxFreq;
        if(l <= k) {
            maxLen = max(maxLen, j - i + 1);
            continue;
        }
        mp[s[i]-'A']--;
        i++;
    }

    return maxLen;
}

int characterReplacementMediumOptimized(string &s, int k) {
    vector<int> mp(26);
    int maxLen = 0;
    int maxFreq = 0;
    int l;

    for(int i=0, j=0; j<s.size(); j++) {
        mp[s[j]-'A']++;
        for(int m=0; m<26; m++) {
            maxFreq = max(maxFreq, mp[m]);
        }
        l = j - i + 1 - maxFreq;
        if(l <= k) {
           maxLen = max(maxLen, i - j + 1);
           continue;
        }
        mp[s[i--]-'A']--;
    }

    return maxLen;
}

void runLongestRepeatingCharReplacementMediumExample() {
    string s1 = "ABAB";
    int k1 = 2;

    string s2 = "AABABBA";
    int k2 = 1;

    cout << "Longest = " << characterReplacementMedium(s1, k1) << endl;
    cout << "Longest = " << characterReplacementMedium(s2, k2) << endl;
}
