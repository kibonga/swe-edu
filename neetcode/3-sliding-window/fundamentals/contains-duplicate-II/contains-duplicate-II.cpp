#include "contains-duplicate-II.h"

bool containsNearbyDuplicateFundamentalsInitialTry(vector<int> &nums, int k) {
    unordered_map<int, int> mp;
    int n = nums.size() <= k ? nums.size() : k;

    for(int i=0; i<n; i++) {
        if(mp.count(nums[i])) {
            return true;
        }
        mp[nums[i]]++;
    }

    for(int i=k; i<nums.size(); i++) {
        mp[nums[i]]++;
        if(mp.count(nums[i]) && mp[nums[i]] > 1) {
            return true;
        }
        mp.erase(nums[i-k]);
    }

    return false;
}

bool containsNearbyDuplicateFundamentals(vector<int> &nums, int k) {
    unordered_map<int, int> mp;

    for(int i=0; i<nums.size(); i++) {
        if (mp.count(nums[i]) && (i - mp[nums[i]]) <= k) {
            return true;
        }
        mp[nums[i]] = i;
    }

    return false;
}

void runContainsDuplicateIIFundamentalsExample() {
    vector<int> n1 = {1, 2, 3, 1};
    int k1 = 3;

    cout << "Contains duplicate = " << containsNearbyDuplicateFundamentalsInitialTry(n1, k1) << endl;
    cout << "Contains duplicate = " << containsNearbyDuplicateFundamentals(n1, k1) << endl;
}
