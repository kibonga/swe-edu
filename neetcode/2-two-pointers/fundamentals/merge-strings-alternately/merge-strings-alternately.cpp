#include "merge-strings-alternately.h"

string mergeStringsAlternately(string &word1, string &word2) {
    string s = string();
    int n = min(word1.size(), word2.size());

    int i = 0;
    while(i < n) {
        s += word1[i];
        s += word2[i];
        i++;
    }

    while(i < word1.size()) {
        s += word1[i++];
    }

    while(i < word2.size()) {
        s += word2[i++];
    }

    return s;
}

void runMergeStringsAlternatelyExample() {
    string w1 = "abc";
    string w2 = "pqr";

    cout << "Result = " << mergeStringsAlternately(w1, w2) << endl;
}
