#include "impl-string-hash-map.h"

struct MapNode {
    string key;
    int val;
    MapNode *next;

    MapNode(string &k, int v) : key(k), val(v), next(nullptr) {}
};

struct HashMap {
    MapNode **table;

    HashMap() {
        table = new MapNode *[100]();
    }
};

int hashFn(string &key) {
    int digest = 0;
    for (char c: key) {
        digest += c;
    }
    return digest % 100;
}

void put(HashMap *map, string &key, int val) {
    int i = hashFn(key);
    MapNode *head = map->table[i];
    MapNode *node = new MapNode(key, val);
    if (head == nullptr) {
        map->table[i] = node;
        return;
    }
    MapNode *curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    if (curr->key == node->key) {
        curr->val = node->val;
        return;
    }
    curr->next = node;
}

int get(HashMap *map, string &key) {
    int i = hashFn(key);
    MapNode *head = map->table[i];
    if (head == nullptr) {
        cout << "There is no record with given key" << endl;
        return -1;
    }
    MapNode *curr = head;
    while (curr != nullptr) {
        if (curr->key == key) {
            return curr->val;
        }
        curr = curr->next;
    }
    cout << "There is no record with given key" << endl;
    return -1;
}

void remove(HashMap *map, string &key) {
    int i = hashFn(key);
    MapNode *head = map->table[i];
    if (head == nullptr) {
        cout << "There is no record with given key" << endl;
        return;
    }
    MapNode *temp = nullptr;
    if (head->key == key) {
        temp = head;
        head = nullptr;
        delete temp;
        return;
    }
    MapNode *curr = head;
    while (curr->next != nullptr && curr->next->key != key) {
        curr = curr->next;
    }
    if (curr->next != nullptr) {
        temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
    }
}

void remove2(HashMap *map, string &key) {
    int i = hashFn(key);
    MapNode *head = map->table[i];
    if(head == nullptr) {
        cout << "There is no record with given key" << endl;
        return;
    }
    MapNode *temp = nullptr;
    if(head->key == key) {
        temp = head;
        map->table[i] = head->next;
        delete temp;
        return;
    }
    temp = head;
    MapNode *prev = nullptr;
    while(temp != nullptr && temp->key != key) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == nullptr) {
        cout << "There is no record with given key" << endl;
        return;
    }
    prev->next = temp->next;
    delete temp;
}

void runImplStringHashMapExample() {
    string input = "John";
    string input2 = "c";

    HashMap map = HashMap();
    put(&map, input, 5);
    put(&map, input, 6);
    put(&map, input2, 420);
    cout << "Value of input 2 = " << get(&map, input2) << endl;
    cout << "Value of input 1 = " << get(&map, input) << endl;
    remove2(&map, input);
    cout << "Value of input 1 = " << get(&map, input) << endl;
    cout << "Value of input 2 = " << get(&map, input2) << endl;
}
