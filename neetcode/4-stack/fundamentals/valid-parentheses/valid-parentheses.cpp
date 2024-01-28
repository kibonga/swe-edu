#include "valid-parentheses.h"

bool isOpen(char c) {
    return c == '(' || c == '[' || c == '{';
}

bool areMatch(char a, char b) {
    if(a == '(') {
        return b == ')';
    }else if(a == '[') {
        return b == ']';
    }
    return b == '}';
}

bool isValidParenthesesFundamentals(string &s) {
    stack<int> st;

    for(int i=0; i<s.size(); i++) {
        if(isOpen(s[i])) {
            st.push(s[i]);
            continue;
        }
        if(st.empty() || !areMatch(st.top(), s[i])) {
            return false;
        }
        st.pop();
    }

    return st.empty();
}

void runValidParenthesesFundamentalsExample() {
    string s1 = "()";
    cout << "Is match = " << isValidParenthesesFundamentals(s1) << endl;
}
