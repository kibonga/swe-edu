#include "linked-list-cycle.h"
#include <vector>

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

bool isCircular(Node* head) {
    if(head == nullptr ||
        head->next == nullptr) {
        return false;
    }

    Node* slow = head;
    Node* fast = head->next;

    while(fast != nullptr) {
        if(fast == slow) {
            return true;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}

void runLinkedListCycleExample() {
    Node* node1 = new Node(5);
    Node* node2 = new Node(10);
    Node* node3 = new Node(15);
    Node* node4 = new Node(25);
    Node* node5 = new Node(30);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    // Make list circular
    node5->next = node2;
    // Make list circular

    cout << "Is linked list circular = " << isCircular(node1) << endl;
}
