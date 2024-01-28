#include "baseball-game.h"

bool isScore(string &s) {
    return s != "+" && s != "D" && s != "C";
}

int baseballGameFundamentals(vector<string> &ops) {
    stack<int> st;
    int r = 0;

    for(auto & op : ops) {
        if(isScore(op)) {
            st.push(stoi(op));
            continue;
        }
        if(op == "+") {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.push(b);
            st.push(a + b);
        }else if(op == "D") {
            int d = st.top();
            st.push(d * 2);
        }else {
            st.pop();
        }
    }

    while(!st.empty()) {
        r += st.top();
        st.pop();
    }

    return r;
}

void runBaseballGameFundamentalsExample() {
    vector<string> s1 = {"5","2","C","D","+"};
    cout << "Result = " << baseballGameFundamentals(s1) << endl;
}
