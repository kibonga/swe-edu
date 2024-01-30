#include "removing-stars-from-string.h"

string removeStarsMedium(string &s) {
    string str = "";

    for(char c : s) {
        if(c == '*') {
            str.pop_back();
            continue;
        }
        str += c;
    }

    return str;
}

void runRemovingStarsFromStringMediumExample() {
    string s = "leet**cod*e";
    cout << "Result = " << removeStarsMedium(s) << endl;
}
