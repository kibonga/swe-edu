#include "validate-stack-seq.h"

bool validateStackSequencesMedium(vector<int> &pushed, vector<int> &popped) {
    stack<int> st;
    int i=0, j=0;

    while(i < pushed.size()) {
        st.push(pushed[i]);
        if(pushed[i] == popped[j]) {
            st.pop();
            j++;
        }
        i++;
    }

    while(j < popped.size()) {
        if(st.top() != popped[j]) {
            return false;
        }
        st.pop();
        j++;
    }

    return true;
}

void runValidateStackSequencesMediumExample() {
    vector<int> pushed1 = {1, 2, 3, 4, 5};
    vector<int> popped1 = {4, 5, 3, 2, 1};
    cout << "Result = " << validateStackSequencesMedium(pushed1, popped1) << endl;
}
