#include "subarray-sum-equals-k.h"

int subarraySumReviewFri19Jan2024(vector<int> &nums, int k) {
    unordered_set<int> set; // We cannot use set in here, because we need to find every occurrence(not just one)
    unordered_map<int, int> map; // map<prefixSum, occurrences>
    int count = 0, prefixSum = 0;
    // eg. [2, 8, 4, 3, 6] we are looking for k = 7

    for(int n : nums) {
        prefixSum += n;
        if(prefixSum == k) {
            count++;
        }
        if(map.count(prefixSum-k)) {
            count += map[prefixSum-k];
        }
        map[prefixSum]++;
    }

    return count;
}

void runSubarraySumEqualsKExampleReviewFri19Jan2024() {
    vector<int> nums1 = {1, 1, 1};
    int k1 = 2;
    vector<int> nums2 = {1, 2, 3};
    int k2 = 3;

    cout << "Number of sub-arrays = " << subarraySumReviewFri19Jan2024(nums1, k1) << endl;
    cout << "Number of sub-arrays = " << subarraySumReviewFri19Jan2024(nums2, k2) << endl;
}
