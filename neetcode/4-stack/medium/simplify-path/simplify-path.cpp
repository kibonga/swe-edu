#include "simplify-path.h"

string simplifyPath(string path) {
    vector<string> v;
    string s;

    for (int i = 1; i < path.size(); i++) {
        s = "";
        while (i < path.size() && path[i] != '/') {
            s += path[i++];
        }

        if (s.empty() || s == ".") {
            continue;
        }
        if (s == "..") {
            if (v.empty()) { continue; }
            v.pop_back();
            continue;
        }

        v.push_back(s);
    }

    s = "";
    for (string &r: v) {
        s += "/" + r;
    }

    return s.empty() ? "/" : s;
}

void runSimplifyPathMediumExample() {
    string s1 = "/home//foo/";
    string s2 = "/../";

    cout << "Simplified path = " << simplifyPath(s1) << endl;
    cout << "Simplified path = " << simplifyPath(s2) << endl;
}
