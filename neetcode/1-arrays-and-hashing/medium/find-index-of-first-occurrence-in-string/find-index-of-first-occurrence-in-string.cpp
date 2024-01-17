#include "find-index-of-first-occurrence-in-string.h"

int strStr(string &haystack, string &needle) {
    if(haystack.size() < needle.size()) {return -1;}
    vector<int> start;

    for(int i=0; i<haystack.size(); i++) {
        if(haystack[i] == needle[0]) {
            start.push_back(i);
        }
    }

    bool isOccurrence;
    for(int s : start) {
        if(s+needle.size() > haystack.size()) {return -1;}
        isOccurrence = true;
        for(int i=0; i<needle.size(); i++) {
           if(haystack[s+i] != needle[i]) {
               isOccurrence = false;
           }
        }
        if(!isOccurrence) { continue;}
        return s;
    }

    return -1;
}

void runFindTheIndexOfTheFirstOccurrenceInAStringExample() {
    string haystack1 = "sadbutsad";
    string needle1 = "sad";

    string haystack2 = "hello";
    string needle2 = "ll";

//    cout << "First occurrence at index = " << strStr(haystack1, needle1) << endl;
    cout << "First occurrence at index = " << strStr(haystack2, needle2) << endl;
}
