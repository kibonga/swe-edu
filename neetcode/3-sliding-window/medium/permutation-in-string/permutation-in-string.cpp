#include "permutation-in-string.h"

bool checkInclusionMedium(string &s1, string &s2) {
    int n = s1.size();
    vector<int> mp1(26);
    vector<int> mp2(26);

    if(s1.size() > s2.size()) {return false;}

    for(int i=0; i<n; i++) {
        mp1[s1[i] - 'a']++;
        mp2[s2[i] - 'a']++;
    }
    if(mp1 == mp2) {return true;}

    for(int i=n; i<s2.size(); i++) {
        mp2[s2[i - n] - 'a']--;
        mp2[s2[i] - 'a']++;
        if(mp1 == mp2) {return true;}
    }

    return false;
}

void runPermutationInStringMediumExample() {
    string s11 = "ab";
    string s12 = "eidbaooo";

    string s21 = "ab";
    string s22 = "eidboaooo";

    cout << "Is permutation = " << checkInclusionMedium(s11, s12) << endl;
    cout << "Is permutation = " << checkInclusionMedium(s21, s22) << endl;
}
