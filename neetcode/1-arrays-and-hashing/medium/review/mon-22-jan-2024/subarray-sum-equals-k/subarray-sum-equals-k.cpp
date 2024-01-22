#include "subarray-sum-equals-k.h"

int subarraySumReviewMon22Jan2024(vector<int> &nums, int k) {
    unordered_map<int, int> mp;
    int cnt = 0;
    int sum = 0;

    for(int num : nums) {
        sum += num;
        if(sum == k) {
            cnt++;
        }
        if(mp[sum - k]) {
            cnt += mp[sum - k];
        }
        mp[sum]++;
    }
    return cnt;
}

void runSubarraySumEqualsKExampleReviewMon22Jan2024() {
    vector<int> nums1 = {1, 1, 1};
    int k1 = 2;
    vector<int> nums2 = {1, 2, 3};
    int k2 = 3;
    vector<int> nums3 = {1};
    int k3 = 0;
    vector<int> nums4 = {1};
    int k4 = 1;
    vector<int> nums5 = {-1, -1, 1};
    int k5 = 0;


    cout << "Number of subarrays that sum to k = " << subarraySumReviewMon22Jan2024(nums1, k1) << endl;
    cout << "Number of subarrays that sum to k = " << subarraySumReviewMon22Jan2024(nums2, k2) << endl;
    cout << "Number of subarrays that sum to k = " << subarraySumReviewMon22Jan2024(nums3, k3) << endl;
    cout << "Number of subarrays that sum to k = " << subarraySumReviewMon22Jan2024(nums4, k4) << endl;
    cout << "Number of subarrays that sum to k = " << subarraySumReviewMon22Jan2024(nums5, k5) << endl;
}
