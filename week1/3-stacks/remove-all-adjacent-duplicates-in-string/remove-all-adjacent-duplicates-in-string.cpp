#include "remove-all-adjacent-duplicates-in-string.h"

string removeDuplicates(string &s) {
    stack<char> st;
    string r;
    for(char c : s) {
        if(!st.empty() && st.top() == c) {
            st.pop();
            r.pop_back();
            continue;
        }
        st.push(c);
        r.push_back(c);
    }
    return r;
}

void runRemoveAllAdjacentDuplicatesInString() {
    string input = "azxxzy";
    cout << "Remove duplicates = " << removeDuplicates(input);
}
