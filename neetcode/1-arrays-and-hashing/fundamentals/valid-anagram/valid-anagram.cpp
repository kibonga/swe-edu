#include "valid-anagram.h"

bool isAnagram(string s, string t) {
    vector<int> table1(26, 0);
    vector<int> table2(26, 0);

    if(s.size() != t.size()) {return false;}

    for(int i=0; i<s.size(); i++) {
        table1[s[i]-'a']++;
        table2[t[i]-'a']++;
    }

    for(int i=0; i<26; i++) {
        if(table1[i] != table2[i]) {return false;}
    }

    return true;
}

void runValidAnagramExample() {
    string s1 = "anagram";
    string t1 = "nagaram";

    string s2 = "rat";
    string t2 = "car";

    cout << "Valid anagram = " << isAnagram(s1, t1) << endl;
    cout << "Invalid anagram = " << isAnagram(s2, t2) << endl;
}
