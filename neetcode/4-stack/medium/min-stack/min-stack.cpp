#include "min-stack.h"

class MinStack {
public:
    stack<int> st;
    vector<int> v;

    MinStack() {

    }

    void push(int val) {
        if(st.empty()) {
            v.push_back(val);
        }else if(val <= v.back()){
            v.push_back(val);
        }

        st.push(val);
    }

    void pop() {
        if(st.top() == v.back()) {
            v.pop_back();
        }
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return v.back();
    }
};

void runMinStackMediumExample() {
    MinStack st = MinStack();
    st.push(512);
    st.push(-1024);
    st.push(-1024);
    st.push(512);
    st.pop();
    cout << "Min = " << st.getMin() << endl;
    st.pop();
    cout << "Min = " << st.getMin() << endl;
    st.pop();
    cout << "Min = " << st.getMin() << endl;
}
