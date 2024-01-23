#include "min-diff-between-highest-and-lowest-of-k-scores.h"

int minimumDifference(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int minDiff = INT32_MAX;

    for(int i=0, j=k-1; j<nums.size(); i++, j++) {
        minDiff = min(minDiff, nums[j] - nums[i]);
    }

    return minDiff;
}

void runMinimumDifferenceBetweenHighestAndLowestOfKScoresExample() {
    vector<int> nums1 = {9, 4, 1, 7};
    int k1 = 2;
    cout << "Min diff = " << minimumDifference(nums1, k1) << endl;
}
