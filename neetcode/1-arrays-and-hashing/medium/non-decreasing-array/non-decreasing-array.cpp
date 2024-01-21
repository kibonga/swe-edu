#include "non-decreasing-array.h"

//bool checkPossibility(vector<int> &nums) {
//    if(nums.empty()) {return true;}
//    unordered_map<int, int> map;
//    int modify = 0;
//    int prev = nums[0];
//
//    map[nums[0]] = INT32_MIN;
//    int i=1;
//    while(i<nums.size()) {
//        if(prev > nums[i]) {
//            modify++;
//            nums[i-1] = map[prev];
//            map.erase(prev);
//            prev = nums[i-1];
//            continue;
//        }
//        if(modify > 1) {return false;}
//        map[nums[i]] = prev;
//        prev = nums[i];
//        i++;
//    }
//
//    return true;
//}

bool checkPossibility(vector<int> &nums) {
    bool modified = false;

    for(int i=0; i<nums.size(); i++) {
        if(nums[i+1] >= nums[i]) {
            // [2, 3, 4]
            // This is increasing order, everything is good
            continue;
        }
        // Order is not increasing, check if we already had modifications
        if(modified) {
            // It is not increased and was already MODIFIED
            return false;
        }

        // Order is decreasing and we need to modify it
        if(i == 0) {
            // Base case
            // [4, 3]
            nums[i] = nums[i+1];
        }else if(nums[i-1] > nums[i+1]) {
            // Previous is larger than next, we want to increase next to the current
            // [3, 4, 2]
            nums[i+1] = nums[i];
        }else if(nums[i+1] > nums[i-1]) {
            // Next is larger than previous, we want to decrease current to next
            // [2, 4, 3]
            nums[i] = nums[i+1];
        }

        // Since it was in decreasing order, we want to set modified flag to TRUE
        modified = true;
    }

    return true;
}

void runNonDecreasingArrayExample() {
    vector<int> nums1 = {4, 2, 3};
    vector<int> nums2 = {4, 2, 1};
    vector<int> nums3 = {3, 4, 2, 3};
    vector<int> nums4 = {5, 7, 1, 8};

//    cout << "Can be non-decreasing = " << checkPossibility(nums1) << endl;
    cout << "Can be non-decreasing = " << checkPossibility(nums2) << endl;
//    cout << "Can be non-decreasing = " << checkPossibility(nums3) << endl;
    cout << "Can be non-decreasing = " << checkPossibility(nums4) << endl;
}
