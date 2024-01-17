#include "find-all-anagrams-in-a-string.h"

vector<int> findAnagrams(string &s, string &p) {
    vector<int> map(26, 0);
    unordered_map<char, int> umap;
    vector<int> anagrams;

    for(int i=0; i<p.size(); i++) {
        map[s[i]-'a']++;
    }

    for(char c : p) {
        umap[c]++;
    }

    bool isAnagram = true;
    for(auto &m : umap) {
        if(m.second != map[m.first-'a']) {
            isAnagram = false;
            break;
        }
    }

    if(isAnagram) {anagrams.push_back(0);}

    for(int i=0, j=p.size(); j<s.size(); i++, j++) {
        map[s[i]-'a']--;
        map[s[j]-'a']++;
        isAnagram = true;
        for(auto &m : umap) {
            if(m.second != map[m.first-'a']) {
                isAnagram = false;
                break;
            }
        }
        if(!isAnagram) { continue;}
        anagrams.push_back(i+1);
    }


    return anagrams;
}

void runFindAllAnagramsInAStringExample() {
    string s1 = "cbaebabacd";
    string s2 = "abc";

    string s3 = "abab";
    string s4 = "ab";

    vector<int> result = findAnagrams(s3, s4);

    cout << "Starting indices = [ ";
    for(int r : result) {
        cout << r << " ";
    }
    cout << "]" << endl;
}
