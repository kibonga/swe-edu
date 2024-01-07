#include "isomorphic-strings.h"

bool isIsomorphic(string &s, string &t) {
    vector<int> table1(128, 0);
    vector<int> table2(128, 0);
    int n = s.size();

    char c1, c2;
    for(int i=0; i<n; i++) {
        c1 = s[i];
        c2 = t[i];

        if(table1[c1] == 0 && table2[c2] == 0) {
            table1[c1] = c2;
            table2[c2] = c1;
            continue;
        }
        if(table1[c1] != c2 || table2[c2] != c1) {
            return false;
        }
    }

    return true;
}

void runIsomorphicStringsExample() {
    string s1 = "paper";
    string t1 = "title";

    string s2 = "foo";
    string t2 = "bar";

    cout << "Is isomorphic = " << isIsomorphic(s1, t1) << endl;
    cout << "Is isomorphic = " << isIsomorphic(s2, t2) << endl;
}
