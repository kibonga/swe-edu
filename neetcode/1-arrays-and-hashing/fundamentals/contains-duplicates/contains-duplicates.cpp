#include "contains-duplicates.h"

// Because we use FIND in set this will be O(nlogn)
bool containsDuplicateUsingSetFind(vector<int> &nums) {
    set<int> set;

    for(int n : nums) {
        if(set.find(n) != set.end()) {
            return true;
        }
        set.insert(n);
    }

    return false;
}

// This is still O(nlogn) because set uses Red-Black tree
bool containsDuplicateUsingSetSize(vector<int> &nums) {
    set<int> set;

    for(int n : nums) {
        set.insert(n);
    }

    return nums.size() > set.size() ? true : false;
}

// Because we iterate the map(2x times) this will be O(N)
bool containsDuplicateUsingUnorderedMap(vector<int> &nums) {
    unordered_map<int, int> map;

    for(int n : nums) {
        map[n]++;
    }

    for(auto &m : map) {
        if(m.second > 1) {
            return true;
        }
    }

    return false;
}

bool containsDuplicateUsingUnorderedMapComparingSize(vector<int> &nums) {
    unordered_map<int, int> map;

    for(int n : nums) {
        map[n]++;
    }

//    cout << "Unordered map size = " << map.size() << endl;
//    cout << "Unordered map bucket count = " << map.bucket_count();

    return nums.size() > map.size() ? true : false;
}

void runContainsDuplicateExample() {
    vector<int> withDuplicates = {1, 2, 3, 1};
    vector<int> withoutDuplicates = {1, 2, 3, 4};

    cout << "Time complexity using SET find method, O(nlogn)" << endl;
    cout << "Contains duplicates = " << containsDuplicateUsingSetFind(withDuplicates) << endl;
    cout << "Contains duplicates = " << containsDuplicateUsingSetFind(withoutDuplicates) << endl;

    cout << endl;

    cout << "Time complexity using SET comparing size, O(nlogn)" << endl;
    cout << "Contains duplicates = " << containsDuplicateUsingSetSize(withDuplicates) << endl;
    cout << "Contains duplicates = " << containsDuplicateUsingSetSize(withoutDuplicates) << endl;

    cout << endl;

    cout << "Time complexity using UNORDERED MAP, O(n)" << endl;
    cout << "Contains duplicates = " << containsDuplicateUsingUnorderedMap(withDuplicates) << endl;
    cout << "Contains duplicates = " << containsDuplicateUsingUnorderedMap(withoutDuplicates) << endl;

    cout << endl;
    cout << "Time complexity using UNORDERED MAP comparing size, O(n)" << endl;
    cout << "Contains duplicates = " << containsDuplicateUsingUnorderedMapComparingSize(withDuplicates) << endl;
    cout << "Contains duplicates = " << containsDuplicateUsingUnorderedMapComparingSize(withoutDuplicates) << endl;
}
