#include "optimal-partition-of-string.h"

int partitionString(string &s) {
    unordered_set<char> set;
    int count = 0;

    for(char c : s) {
        if(set.count(c)) {
            set.clear();
            count++;
        }
        set.insert(c);
    }

    return count + 1;
}

void runOptimalPartitionOfStringExample() {
    string s = "hdklqkcssgxlvehva";
    cout << "Min number of substrings = " << partitionString(s) << endl;
}
