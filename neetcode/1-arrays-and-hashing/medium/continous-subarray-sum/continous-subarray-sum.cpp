#include "continous-subarray-sum.h"

bool checkSubarraySum(vector<int> &nums, int k) {
    unordered_set<int> set;
    int prefixSum = 0;

    int mod;
    for(int num : nums) {
        mod = (prefixSum + num) % k;
        if(set.find(mod) != set.end()) {
            return true;
        }
        set.insert(prefixSum % k);
        prefixSum += num;
    }

    return false;
}

bool checkSubarraySumLC(vector<int>& n, int k) {
    unordered_set<int> s;
    for (int i = 0, psum = 0; i < n.size(); psum += n[i++]) {
        if (s.count((psum + n[i]) % k))
            return true;
        s.insert(psum % k);
    }
    return false;
}

void runContinuousSubarraySumExample() {
    vector<int> nums1 = {23, 2, 4, 6, 7};
    int k1 = 6;

    vector<int> nums2 = {23, 2, 6, 4, 7};
    int k2 = 6;

    vector<int> nums3 = {23, 2, 6, 0, 0, 4, 7};
    int k3 = 13;

//    vector<int> nums4 = {23, 2, 4, 0, 0, 6};
//    int k4 = 7;

//    cout << "Is subarray good = " << checkSubarraySum(nums1, k1) << endl;
//    cout << "Is subarray good = " << checkSubarraySum(nums2, k2) << endl;
//    cout << "Is subarray good = " << checkSubarraySum(nums3, k3) << endl;
    cout << "Is subarray good = " << checkSubarraySum(nums3, k3) << endl;
    cout << "Is subarray good = " << checkSubarraySumLC(nums3, k3) << endl;
}
