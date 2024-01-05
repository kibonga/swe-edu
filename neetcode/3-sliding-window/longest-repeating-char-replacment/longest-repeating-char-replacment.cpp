#include "longest-repeating-char-replacment.h"

int charReplacement(string &s, int k) {
    vector<int> table(26);
    int i = 0, j = 0, maxLen = 0, currWindowLen, mostFreqCharLen = 0;

    while(j < s.size()) {
        // Insert current char into table
        table[s[j]-'A']++;
        // Check if newly added/updated char is the most frequent
        mostFreqCharLen = max(mostFreqCharLen, table[s[j]-'A']);
        // Check for invalid state
        currWindowLen = j - i + 1;
        if(currWindowLen - mostFreqCharLen > k) {
            // Shrink the sliding window and update table
            table[s[i]-'A']--;
            i++;
            currWindowLen--;
        }
        // Update max length if necessary
        maxLen = max(maxLen, currWindowLen);
        j++;
    }

    return maxLen;
}

void runLongestRepeatingCharReplacementExample() {
    string string1 = "ABAB";
    int k1 = 2;

    string string2 = "AABABBA";
    int k2 = 1;

    string string3 = "AAAA";
    int k3 = 2;

    string string4 = "AAAA";
    int k4 = 0;

    string string5 = "AAAB";
    int k5 = 0;

    string string6 = "AABA";
    int k6 = 0;

    cout << "Longest substr = " << charReplacement(string1, k1) << endl;
    cout << "Longest substr = " << charReplacement(string2, k2) << endl;
    cout << "Longest substr = " << charReplacement(string3, k3) << endl;
    cout << "Longest substr = " << charReplacement(string4, k4) << endl;
    cout << "Longest substr = " << charReplacement(string5, k5) << endl;
    cout << "Longest substr = " << charReplacement(string6, k6) << endl;
}
