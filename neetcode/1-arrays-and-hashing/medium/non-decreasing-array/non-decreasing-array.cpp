#include "non-decreasing-array.h"

bool checkPossibility(vector<int> &nums) {
    if(nums.empty()) {return true;}
    unordered_map<int, int> map;
    int modify = 0;
    int prev = nums[0];

    map[nums[0]] = INT32_MIN;
    int i=1;
    while(i<nums.size()) {
        if(prev > nums[i]) {
            modify++;
            nums[i-1] = map[prev];
            map.erase(prev);
            prev = nums[i-1];
            continue;
        }
        if(modify > 1) {return false;}
        map[nums[i]] = prev;
        prev = nums[i];
        i++;
    }

    return true;
}

void runNonDecreasingArrayExample() {
    vector<int> nums1 = {4, 2, 3};
    vector<int> nums2 = {4, 2, 1};
    vector<int> nums3 = {3, 4, 2, 3};
    vector<int> nums4 = {5, 7, 1, 8};

//    cout << "Can be non-decreasing = " << checkPossibility(nums1) << endl;
//    cout << "Can be non-decreasing = " << checkPossibility(nums2) << endl;
//    cout << "Can be non-decreasing = " << checkPossibility(nums3) << endl;
    cout << "Can be non-decreasing = " << checkPossibility(nums4) << endl;
}
