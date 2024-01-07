#include "is-subsequence.h"

bool isSubsequence(string s, string t) {
    vector<int> table(26, 0);

    for(char c : s) {
        table[c-'a']++;
    }

    int index;
    int j = 0;
    for(int i=0; i<t.size(); i++) {
        index = t[i]-'a';
        if(table[index] > 0 && t[i] == s[j]) {
            j++;
            table[index]--;
        }
    }

    for(int n : table) {
        if(n > 0) {return false;}
    }

    return true;
}

void runIsSubsequenceExample() {
    string s1 = "abc";
    string t1 = "ahbgdc";

    string s2 = "axc";
    string t2 = "ahbgdc";

    string s3 = "b";
    string t3 = "c";

    string s4 = "ab";
    string t4 = "baab";

    cout << "Is subsequence = " << isSubsequence(s1, t1) << endl;
    cout << "Is subsequence = " << isSubsequence(s2, t2) << endl;
    cout << "Is subsequence = " << isSubsequence(s3, t3) << endl;
    cout << "Is subsequence = " << isSubsequence(s4, t4) << endl;
}
