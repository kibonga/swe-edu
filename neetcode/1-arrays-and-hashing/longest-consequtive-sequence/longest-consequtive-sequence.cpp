#include "longest-consequtive-sequence.h"

int longestConsecutiveSequenceNLogN(vector<int> &nums) {
    // This example is actually O(n log n), because we use ordered map
    int max = 0, seq = 0;
    map<int, int> map;

    if(nums.empty()) {
        return 0;
    }

    for(int n : nums) {
        map[n]++;
    }

    for(auto &m : map) {
        seq++;

        if(seq > max) {
            max = seq;
        }

        if(map.find(m.first + 1) == map.end()) {
            seq = 0;
            continue;
        }
    }

    return max;
}

int longestConsecutiveSequence(vector<int> &nums) {
    unordered_set<int> set(nums.begin(), nums.end());
    int max = 0, seq = 0;

    for(int n : nums) {
        set.insert(n);
    }

    for(int s : set) {
        seq = 1;
        if(set.count(s-1)) {
            continue;
        }
        while(set.count(s+1)) {
            seq++;
            s = s+1;
        }
        if(seq > max) {
            max = seq;
        }
    }

    return max;
}

void runLongestConsecutiveSequenceExample() {
    vector<int> nums1 {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    vector<int> nums2 {100, 4, 200, 1, 3, 2};

    cout << "Longest consecutive seq = " << longestConsecutiveSequence(nums1) << endl;
    cout << "Longest consecutive seq = " << longestConsecutiveSequence(nums2) << endl;
//  cout << "Longest consecutive seq = " << longestConsecutiveSequenceNLogN(nums2);
}
