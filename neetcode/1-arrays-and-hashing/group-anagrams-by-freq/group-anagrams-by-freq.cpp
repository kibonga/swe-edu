#include "group-anagrams-by-freq.h"

string getHash(string &s) {
    vector<int> count(26);
    for(char i : s) {
        count[i - 'a'] += 1;
    }
    string key;
    for(int i : count) {
        key.push_back(i + '0');
    }
    return key;
}

vector<vector<string>> groupAnagrams(vector<string> &strs) {
   vector<vector<string>> result;
   map<string, vector<string>> map;

   string key;
   for(auto &s : strs) {
        key = getHash(s);
        map[key].push_back(s);
   }

   for(auto &m : map) {
       result.push_back(m.second);
   }

   return result;
}

void runGroupAnagramsExample() {
    string input1 = "tan";
    string input2 = "nat";
    string hash1 = getHash(input1);
    string hash2 = getHash(input2);

    cout << "Hash 1 = " << hash1 << endl;
    cout << "Hash 2 = " << hash2 << endl;

    vector<string> input = {
            "eat",
            "tea",
            "tan",
            "ate",
            "nat",
            "bat"
    };
    vector<vector<string>> vec = groupAnagrams(input);
    for(auto &strs : vec) {
        cout << "[ ";
        for(auto &s : strs) {
            cout << s << " ";
        }
        cout << " ]" << endl;
    }
}
