#include "generate-parentheses.h"

void dfs(vector<string> &r, string &s, int o, int c) {
    if(o == 0 && c == 0) {
        r.push_back(s);
        return;
    }

    if(o > 0) {
        s.push_back('(');
        dfs(r, s, o - 1, c);
        s.pop_back();
    }

    if(c > o) {
        s.push_back(')');
        dfs(r, s, o, c - 1);
        s.pop_back();
    }
}
vector<string> generateParenthesis(int n) {
    vector<string> r;
    string s = "";

    dfs(r, s, n, n);

    return r;
}


void runGenerateParenthesesMediumExample() {
    int n = 3;
    vector<string> result = generateParenthesis(n);

    cout << "Result" << endl;
    for(auto &r : result) {
        cout << r << endl;
    }
}
