#include "longest-consequtive-sequence.h"


int longestConsecutive(vector<int> &nums) {
    unordered_set<int> set;
    int seq = 0;
    int count;

    for (int n: nums) {
        set.insert(n);
    }

    // What NOT to do
    // 1. Don't iterate over whole array, because array may contain duplicates
    // 2. Don't try to calculate current sequence for every element(we just need the smallest)
    // (the smallest is the one where n-1 is not present in the set)

//    for (int n: nums) {
//        count = 1;
//
//        while (set.find(n + 1) != set.end()) {
//            count++;
//            n = n + 1;
//        }
//        seq = max(count, seq);
//    }

    // Unordered set operations are O(1)
    // (worst case is O(n), but we don't take that into account)
    // Just make sure to iterate over set(distinct values) and not vector(duplicates)
    // Start the count only, when smallest element of that sequence is found
    // (when n-1 cannot be found in the map)
    for(auto s : set) {
        // O(1)
        if(set.find(s-1) != set.end()) {
            continue;
        }

        count = 1;
        // O(1)
        while(set.find(s + 1) != set.end()) {
            count++;
            s = s + 1;
        }
        seq = max(seq, count);
    }

    return seq;
}

void runLongestConsecutiveSequenceExampleRevision() {
    vector<int> nums1 = {100, 4, 200, 1, 3, 2};

    cout << "Longest consecutive sequence = " << longestConsecutive(nums1) << endl;
}

