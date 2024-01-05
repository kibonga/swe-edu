#include "permutation-in-string.h"

bool checkInclusion(string &s1, string &s2) {
    if(s1.size() > s2.size()) {
        return false;
    }

    vector<int> table1(26, 0);
    vector<int> table2(26, 0);
    int window = s1.size();
    int i, j, matches = 0, index;

    for(i=0; i<window; i++) {
        table1[s1[i]-'a']++;
        table2[s2[i]-'a']++;
    }

    for(i=0; i<26; i++) {
        if(table1[i] == table2[i]) {
            matches++;
        }
    }

    j = window;
    i = 0;
    while(j < s2.size()) {
        if(matches == 26) {
            return true;
        }

        index = s2[j]-'a';
        table2[index]++;
        if(table1[index] == table2[index]) {
            matches++;
        }else if(table1[index] + 1 == table2[index]) {
            matches--;
        }
        j++;

        index = s2[i]-'a';
        table2[index]--;
        if(table1[index] == table2[index]) {
            matches++;
        }else if(table1[index] == table2[index] + 1) {
            matches--;
        }
        i++;
    }

    return matches == 26;
}

void runPermutationInStingExample() {
    string s1 = "hello";
    string s2 = "ooolleoooleh";

//    string s1 = "abc";
//    string s2 = "bbbca";

    cout << "Is permutation = " << checkInclusion(s1, s2) << endl;
}
