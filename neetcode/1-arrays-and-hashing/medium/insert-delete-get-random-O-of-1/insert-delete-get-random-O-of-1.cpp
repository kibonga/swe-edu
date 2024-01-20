#include "insert-delete-get-random-O-of-1.h"

class RandomizedSet {
public:
    unordered_map<int, int> map;
    vector<int> values;
    RandomizedSet() {

    }

    bool insert(int val) {
        if(map.count(val)) {return false;}
        values.push_back(val);
        int i = values.size()-1;
        map[val] = i;
        return true;
    }

    bool remove(int val) {
        if(!map.count(val)) {return false;}
        int i = map[val];
        map.erase(val);
        int newVal = values.back();
        values[i] = newVal;
        values.pop_back();
        if(!values.empty()) {
            map[newVal] = i;
        }
        return true;
    }

    int getRandom() {
        return values[rand() % values.size()];
    }
};

void runInsertDeleteGetRandomBigO1() {
    RandomizedSet randomizedSet = RandomizedSet();
//    cout << "Remove = " << randomizedSet.remove(0) << endl;
//    cout << "Remove = " << randomizedSet.remove(0) << endl;
//    cout << "Insert = " << randomizedSet.insert(0) << endl;
//    cout << "Random = " << randomizedSet.getRandom() << endl;
//    cout << "Remove = " << randomizedSet.remove(0) << endl;
//    cout << "Remove = " << randomizedSet.insert(0) << endl;
    cout << "Insert = " << randomizedSet.insert(0) << endl;
    cout << "Insert = " << randomizedSet.insert(1) << endl;
    cout << "Remove = " << randomizedSet.remove(0) << endl;
    cout << "Insert = " << randomizedSet.insert(2) << endl;
    cout << "Remove = " << randomizedSet.remove(1) << endl;
    cout << "Random = " << randomizedSet.getRandom() << endl;
}
