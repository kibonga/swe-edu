#include "repeated-dna-sequence.h"

vector<string> findRepeatedDnaSequences(string &s) {
    if(s.size() < 10) {return {};}
    unordered_set<string> set;
    unordered_map<string, int> map;
    vector<string> sequences;

    string str;
    for(int i=0; i<s.size(); i++) {
        str = s.substr(i, 10);
        if(map[str] == 1) {
            sequences.push_back(str);
        }
        map[str]++;
    }

    return sequences;
}

void runFindRepeatedDnaSequencesExample() {
    string s1 = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> result = findRepeatedDnaSequences(s1);

    cout << "Repeated sequences = [ ";
    for(auto &s : result) {
        cout << s << " ";
    }
    cout << "]" << endl;
}
