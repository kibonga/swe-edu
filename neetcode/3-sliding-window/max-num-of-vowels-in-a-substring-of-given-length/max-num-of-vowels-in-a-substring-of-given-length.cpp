#include "max-num-of-vowels-in-a-substring-of-given-length.h"

int maxVowels(string &s, int k) {
    int maxVowels = 0, currVowels;
    int i, j;
    vector<int> vowels(26, 0);
    vowels['a'-'a']++;
    vowels['e'-'a']++;
    vowels['i'-'a']++;
    vowels['o'-'a']++;
    vowels['u'-'a']++;

    if(k == 0) {
        return -1;
    }

    if(k == 1) {
        for(char c : s) {
            if(vowels[c-'a'] > 0) {
                return 1;
            }
        }
    }

    for(i=0; i<k; i++) {
        if(vowels[s[i]-'a'] > 0) {
            maxVowels++;
        }
    }

    currVowels = maxVowels;

    j = k;
    while(j<s.size()) {
        if(maxVowels == k) {
            return maxVowels;
        }

        if(vowels[s[j]-'a']) {
            currVowels++;
        }

        if(vowels[s[j-k]-'a']) {
            currVowels--;
        }

        maxVowels = max(maxVowels, currVowels);
        j++;
    }

    return maxVowels;
}

void runMaxNumberOfVowelsInSubstringOfGivenLengthExample() {
//    string s1 = "leetcode";
//    int k = 3;
//    string s1 = "novowels";
//    int k = 1;
//    string s1 = "tnfazcwrryitgacaabwm";
//    int k = 4;
    string s1 = "ramadan";
    int k = 2;

    cout << "Maximum num of vowels = " << maxVowels(s1, k);
}
