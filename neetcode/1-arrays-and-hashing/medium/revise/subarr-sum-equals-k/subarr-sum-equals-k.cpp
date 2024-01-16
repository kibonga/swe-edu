#include "subarr-sum-equals-k.h"

int subarraySumReview(vector<int> &nums, int k) {
    int total = 0;
//    unordered_set<int> prefixSum;
    unordered_map<int, int> prefixSum;

//    int sum = 0;
//    for(int i=0; i<nums.size()-1; i++) {
//        sum += nums[i];
//        prefixSum[sum] = i;
//    }

//    int sum = 0;
//    int diff;
//    for(int n : nums) {
//        sum += n;
//        if(sum == k) {
//            total++;
//        }
//        if(prefixSum.find(sum - k) != prefixSum.end()) {
//            total++;
//        }
//        prefixSum.insert(sum);
//    }

    // See this example
    // eg. [2, 8, -1, 1, 0, 0, 4, 3, 6] we are looking for k = 7
    // prefixes [2, 10, 9, 10, 10, 10, 14, 17, | 23]
    // when we reach number 3 sum is 17
    // when reach 8 sum is 10
    // subtracting sums gives us k = 17 - 10
    int sum = 0;
    for(int n : nums) {
        sum += n;
        if(sum == k) {
            total++;
        }
        if(prefixSum.find(sum-k) != prefixSum.end()) {
            total += prefixSum[sum-k];
        }
        prefixSum[sum]++;
    }

    return total;
}

void runSubarrSumEqualsKExampleReview() {
    vector<int> nums = {1, 1, 1};
    int k = 2;

    vector<int> nums2 = {1, -1, 0};
    int k2 = 0;
    cout << "Number of sub-arrays that sum to k = " << subarraySumReview(nums, k) << endl;
    cout << "Number of sub-arrays that sum to k = " << subarraySumReview(nums2, k2) << endl;
}
