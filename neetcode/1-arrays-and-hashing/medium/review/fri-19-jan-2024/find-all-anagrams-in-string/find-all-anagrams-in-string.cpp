#include "find-all-anagrams-in-string.h"

vector<int> findAnagramsReviewFri19Jan2024(string &s, string &p) {
    if(s.size() < p.size()) {return {};}
    vector<int> result;
    vector<int> sMap(26, 0);
    vector<int> pMap(26, 0);

    for(int i=0; i<p.size(); i++) {
        sMap[s[i]-'a']++;
        pMap[p[i]-'a']++;
    }

    if(sMap == pMap) {
        result.push_back(0);
    }

    for(int i=p.size(), j=0; i<s.size(); i++, j++) {
        sMap[s[j]-'a']--;
        sMap[s[i]-'a']++;
        if(sMap != pMap) { continue;}
        result.push_back(j+1);
    }

    return result;
}

void runFindAllAnagramsInStringExampleReviewFri19Jan2024() {
    string s1 = "cbaebabacd";
    string p1 = "abc";

    string s2 = "abab";
    string p2 = "ab";

    vector<int> result = findAnagramsReviewFri19Jan2024(s1, p1);

    cout << "Indices = [ ";
    for(int r : result) {
        cout << r << " ";
    }
    cout << "]" << endl;
}
