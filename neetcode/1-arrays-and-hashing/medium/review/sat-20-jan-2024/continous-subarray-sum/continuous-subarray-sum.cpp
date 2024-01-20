#include "continuous-subarray-sum.h"

bool checkSubarraySumReviewSat20Jan2024(vector<int> &nums, int k) {
    unordered_set<int> set;
    int sum = 0;

    for(int num : nums) {
       if(set.count((sum+num) % k)) {
           return true;
       }
       set.insert(sum % k);
       sum += num;
    }

    return false;
}

void runContinuousSubarraySumExampleReviewSat20Jan2024() {
//    vector<int> nums1 = {23, 2, 4, 6, 7};
//    vector<int> nums1 = {2, 4, 12, 7};
//    vector<int> nums1 = {23, 2, 4, 6, 6};
    vector<int> nums1 = {23, 2, 6, 4, 7};
    int k1 = 13;

    cout << "Is subarray good = " << checkSubarraySumReviewSat20Jan2024(nums1, k1) << endl;
}
