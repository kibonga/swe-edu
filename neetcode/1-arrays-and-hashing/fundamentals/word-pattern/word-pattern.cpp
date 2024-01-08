#include "word-pattern.h"

bool wordPattern2(string pattern, string s) {
    vector<string> words;
    unordered_map<char, string> map;

    string w;
    stringstream ss(s);
    while(getline(ss, w, ' ')) {
        words.push_back(w);
    }

    if(pattern.size() != words.size()) {return 0;}

    char c;
    for(int i=0; i<pattern.size(); i++) {
        c = pattern[i];
        if(map.find(c) == map.end()) {
            map[c] = words[i];
            continue;
        }
    }

    for(int i=0; i<pattern.size(); i++) {
        if(words[i] != map[pattern[i]]) { return false;}
    }

    return true;
}

bool wordPattern(string pattern, string s) {
    vector<string> words;
    unordered_map<string, char> strToChar;
    unordered_map<char, string> charToStr;

    string word;
    for(int i=0; i<s.size(); i++) {
        if(s[i] != ' ') {
            word += s[i];
            continue;
        }
        words.push_back(word);
        word = string();
    }
    if(!word.empty()) {words.push_back(word);}

    if(words.size() != pattern.size()) {return false;}

    for(int i=0; i<words.size(); i++) {
        if(strToChar.find(words[i]) == strToChar.end()) {
            strToChar[words[i]] = pattern[i];
            charToStr[pattern[i]] = words[i];
            continue;
        }
    }

    for(int i=0; i<words.size(); i++) {
        if(strToChar[words[i]] == pattern[i] && charToStr[pattern[i]] == words[i]) {continue;}
        return false;
    }

    return true;
}

void runWordPatternExample() {
    string pattern1 = "abba";
    string s1 = "dog cat cat dog";

    string pattern2 = "abba";
    string s2 = "dog cat cat fish";

    cout << "Follows the pattern = " <<  wordPattern(pattern1, s1) << endl;
    cout << "Follows the pattern = " <<  wordPattern(pattern2, s2) << endl;
}
