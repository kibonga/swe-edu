#include "group-anagrams-by-sort.h"

vector<vector<string>> groupAnagramsBySort(vector<string> &strs) {
    vector<vector<string>> result;
    map<string, vector<string>> map;

    string key;
    for(string &s : strs) {
        key = s;
        sort(key.begin(), key.end());
        map[key].push_back(s);
    }

    for(auto &m : map) {
        result.push_back(m.second);
    }

    return result;
}

void runGroupAnagramsBySort() {
    vector<string> input = {
            "eat",
            "tea",
            "tan",
            "ate",
            "nat",
            "bat"
    };
    vector<vector<string>> vec = groupAnagramsBySort(input);
    for(auto &strs : vec) {
        cout << "[ ";
        for(auto &s : strs) {
            cout << s << " ";
        }
        cout << " ]" << endl;
    }
}
