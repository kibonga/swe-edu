#include "design-hash-set.h"

struct Node {
    int key;
    Node *next;
public:
    Node(int x) : key(x), next(nullptr) {}
};

class MyHashSet {
    vector<Node *> set;
public:
    MyHashSet() {
        for (int i = 0; i < 10000; i++) {
            set.push_back(new Node(0));
        }
    }

    void add(int x) {
        int index = x % set.size();
        Node *head = set[index];
        Node *curr = head;

        while (curr->next != nullptr) {
            if (curr->next->key == x) { return; }
            curr = curr->next;
        }
        curr->next = new Node(x);
    }

    void remove(int x) {
        int index = x % set.size();
        Node *head = set[index];
        Node *curr = head;
        Node *temp = nullptr;
        while (curr->next) {
            if (curr->next->key == x) {
                temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
                break;
            }
            curr = curr->next;
        }
    }

    bool contains(int x) {
        int index = x % set.size();
        Node *head = set[index];
        Node *curr = head;
        while (curr->next) {
            if (curr->next->key == x) { return true; }
            curr = curr->next;
        }
        return false;
    }
};

void runDesignHashSetExample() {
    MyHashSet set = MyHashSet();
    set.add(1);
    set.add(2);
    cout << "Contains 1 = " << set.contains(1) << endl;
    cout << "Contains 3 = " << set.contains(3) << endl;
    set.add(2);
    cout << "Contains 2 = " << set.contains(2) << endl;
    set.remove(2);
    cout << "Contains 2 = " << set.contains(2) << endl;
}
