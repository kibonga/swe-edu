#include "eval-reverse-polish-notation.h"

bool isOperator(string &t) {
    return t == "+" || t == "-" || t == "*" || t == "/";
}

int calc(int a, int b, string &op) {
    if(op == "+") {return a + b;}
    if(op == "-") {return a - b;}
    if(op == "*") {return a * b;}
    return a / b;
}

int evalReversePolishNotationMedium(vector<string> &tokens) {
    stack<int> st;

    for(string t : tokens) {
        if(!isOperator(t)) {
            st.push(stoi(t));
            continue;
        }
        int b = st.top();
        st.pop();
        int a = st.top();
        st.pop();
        int c = calc(a, b, t);
        st.push(c);
    }

    return st.top();
}

void runEvaluateReversePolishNotationExample() {
    vector<string> s1 = {"2","1","+","3","*"};
    cout << "Result = " << evalReversePolishNotationMedium(s1) << endl;
}
