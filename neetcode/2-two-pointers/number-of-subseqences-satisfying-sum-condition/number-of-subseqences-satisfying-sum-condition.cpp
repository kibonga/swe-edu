#include "number-of-subseqences-satisfying-sum-condition.h"

int numberOfSequences(vector<int> &nums, int target) {
    int mod = 1e9+7;
    int count = 0;
    int n = nums.size();
    int l = 0, r = n-1;
    sort(nums.begin(), nums.end());

    vector<int> power(n);
    power[0] = 1;
    for(int i=1; i<n; i++) {
        power[i] = (power[i-1] * 2) % mod;
    }

    while(r >= l) {
        if((nums[l] + nums[r] <= target)) {
            count += power[r-l];
            count %= mod;
            l++;
        }else {
            r--;
        }
    }

    return count;
}

int binarySearch(vector<int> nums, int target) {
    int l = 0, r = nums.size()-1, mid;
    while(l <= r) {
        mid = l + (r-l) / 2;
        if(nums[mid] <= target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

// This sln exceeds max memory constraint on LeetCode
int numberOfSequencesBinarySearch(vector<int> &nums, int target) {
    int mod = 1e9+7;
    int count = 0, n = nums.size();
    int r;

    vector<int> power(n);
    power[0] = 1;
    for(int i=1; i<n; i++) {
        power[i] = (power[i-1] * 2) % mod;
    }

    sort(nums.begin(), nums.end());

    int currTarget;
    for(int l=0; l<n; l++) {
        // Find the rightmost index that satisfies given condition for the current elem
        currTarget = target - nums[l];
        r = binarySearch(nums, currTarget) - 1;
        if(r >= l) {
            count += power[r-l];
            count %= mod;
        }
    }

    return count;
}

void runNumberOfSequencesSatisfyingSumConditionExample() {
    vector<int> nums1 = {3, 5, 6, 7};
    int target = 9;
    vector<int> nums2 = {3, 3, 6, 8};
    int target2 = 10;
    vector<int> nums3 = {2, 3, 3, 4, 6, 7};
    int target3 = 12;

    cout << "Number of sequences = " << numberOfSequences(nums2, target2) << endl;
    cout << "Number of sequences = " << numberOfSequencesBinarySearch(nums2, target2) << endl;
}
