#include "implement-stack-using-queues.h"

class MyStack{
public:
    queue<int> q;
    queue<int> p;

    MyStack() {}

    void push(int x){
        q.push(x);
    }

    int pop() {

        while(!q.empty() && q.size() > 1) {
            p.push(q.front());
            q.pop();
        }

        int x = q.front();
        q.pop();

        while(!p.empty()) {
            q.push(p.front());
            p.pop();
        }

        return x;
    }

    int top() {
        return q.back();
    }

    bool empty() {
        return q.empty();
    }
};

void runImplementStackUsingQueuesFundamentalsExample() {
    MyStack st = MyStack();
    st.push(1);
    st.push(2);
    st.pop();
    cout << "Top = " << st.top() << endl;
    cout << "Pop = " << st.pop() << endl;
    cout << "Empty = " << st.empty() << endl;
}
