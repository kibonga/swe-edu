#include "subarr-sum-equals-k.h"

int subArrSum(vector<int> &nums, int k) {
    // This map will represent prefix sum
    // It will be used to store occurrences of sums up until "specific" point
    // Why is this important?
    // Because at one point, based on current sum subtracted with k we can get
    // potential prefix sum(part of the subarray) which we can exclude and get
    // the resulting subarray
    // eg. [2, 8, 4, 3, 6] we are looking for k = 7
    // when we reach number 3 sum is 17
    // when reach 8 sum is 10
    // subtracting sums gives us k = 17 - 10
    unordered_map<int, int> map;
    int count = 0;
    int prefixSum = 0;

    for(int num : nums) {
        prefixSum += num;
        if(prefixSum == k) {
            count++;
        }
        if(map.find(prefixSum-k) != map.end()) {
            count += map[prefixSum-k];
        }
        map[prefixSum]++;
    }

    return count;
}

void runSubArrSumEqualsKExample() {
    vector<int> nums1 = {1, 1, 1};
    int k1 = 2;

    vector<int> nums2 = {1, 2, 3};
    int k2 = 3;

    vector<int> nums3 = {1};
    int k3 = 1;

    vector<int> nums4 = {-1, 0, -1, 1, 1};
    int k4 = 0;

    cout << "Total number of sub-arrays equal to sum = " << subArrSum(nums1, k1) << endl;
    cout << "Total number of sub-arrays equal to sum = " << subArrSum(nums2, k2) << endl;
    cout << "Total number of sub-arrays equal to sum = " << subArrSum(nums3, k3) << endl;
    cout << "Total number of sub-arrays equal to sum = " << subArrSum(nums4, k4) << endl;
}
