#include "design-hash-map.h"

namespace DesignHashMap {
    class Node {
    public:
        Node(int k, int v) : key(k), val(v), next(nullptr) {}

        int val;
        int key;
        Node *next;
    };

    class MyHashMap {
        vector<Node*> map;
    public:
        MyHashMap() {
            for (int i = 0; i < 10000; i++) {
                map.push_back(new Node(0, 0));
            }
        }

        void put(int key, int val) {
            int index = key % 10000;
            Node *head = map[index];
            Node *curr = head;
            while (curr->next != nullptr) {
                if (curr->next->key == key) {
                    curr->next->val = val;
                    return;
                }
                curr = curr->next;
            }
            curr->next = new Node(key, val);
        }

        void remove(int key) {
            int index = key % 10000;
            Node* head = map[index];
            Node* curr = head;
            Node* temp = nullptr;
            while(curr->next != nullptr) {
                if(curr->next->key == key) {
                    temp = curr->next;
                    curr->next = curr->next->next;
                    delete temp;
                    return;
                }
                curr = curr->next;
            }
        }

        int get(int key) {
            int index = key % 10000;
            Node* head = map[index];
            Node* curr = head;
            while(curr->next != nullptr) {
                if(curr->next->key == key) {
                    return curr->next->val;
                }
                curr = curr->next;
            }
            return -1;
        }

    };

}

void runDesignHashMapExample() {
    DesignHashMap::MyHashMap map = DesignHashMap::MyHashMap();
    map.put(1, 1);
    map.put(1, 1);
    map.put(2, 2);
    cout << "Map get 1 = " << map.get(1) << endl;
    cout << "Map get 3 = " << map.get(3) << endl;
    map.put(2, 1);
    cout << "Map get 2 = " << map.get(2) << endl;
    map.remove(2);
    cout << "Map get 2 = " << map.get(2) << endl;
}
