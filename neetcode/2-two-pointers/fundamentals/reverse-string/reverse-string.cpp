#include "reverse-string.h"

void reverseString(vector<char> &s) {
    int i = 0, j = s.size() - 1;

    while (i < j) {
        swap(s[i++], s[j--]);
    }
}

void runReverseStringExample() {
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    reverseString(s);

    cout << "Reversed = [ ";
    for (char c: s) {
        cout << c << " ";
    }
    cout << "]" << endl;
}
