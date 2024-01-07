#include "length-of-last-word.h"

bool isLetter(char c) {
    return (c >= 65 && c < 91) || (c >= 97 && c < 123);
}

int lengthOfLastWord(string s) {
    if(s.empty()) {return -1;}
    int maxLen = 0;
    char c;

    for(int i=s.size()-1; i>=0; i--) {
        c = s[i];
        if(!isLetter(c) && c != ' ') {return -1;}
        if(maxLen > 0 && c == ' ') {return maxLen;}

        if(c == ' ') {
            maxLen = 0;
            continue;
        }

        maxLen++;
    }

    return maxLen;
}


void runLengthOfLastWordExample() {
    string s = "Hello World";

    cout << "Length of last word = " << lengthOfLastWord(s);
}
