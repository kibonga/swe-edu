#include "implement-queue-using-stack.h"

struct Queue {
    stack<int> stackA;
    stack<int> stackB;
};

void push(Queue *q, int x) {
    while(!q->stackA.empty()) {
        q->stackB.push(q->stackA.top());
        q->stackA.pop();
    }
    q->stackA.push(x);
    while(!q->stackB.empty()) {
        q->stackA.push(q->stackB.top());
        q->stackB.pop();
    }
}

void pop(Queue *q) {
    if(q->stackA.empty()) {
        return;
    }
    if(q->stackA.size() == 1) {
        q->stackA.pop();
        return;
    }
    while(q->stackA.size() >= 1) {
        q->stackB.push(q->stackA.top());
        q->stackA.pop();
    }
    q->stackB.pop();
    while(!q->stackB.empty()) {
        q->stackA.push(q->stackB.top());
        q->stackB.pop();
    }
}

int peek(Queue *q) {
    int x;
    if(q->stackA.empty()) {
        return -1;
    }
    if(q->stackA.size() == 1) {
        return q->stackA.top();
    }
    while(!q->stackA.empty()) {
        x = q->stackA.top();
        q->stackB.push(q->stackA.top());
        q->stackA.pop();
    }
    while(!q->stackB.empty()) {
        q->stackA.push(q->stackB.top());
        q->stackB.pop();
    }
    return x;
}

bool empty(Queue *q) {
   return empty(q);
}

void runImplementQueueUsingStack() {
    Queue q = Queue();
    push(&q, 10);
    push(&q, 20);
    push(&q, 30);
    pop(&q);
    cout << "Peek = " << peek(&q);
    pop(&q);
}
