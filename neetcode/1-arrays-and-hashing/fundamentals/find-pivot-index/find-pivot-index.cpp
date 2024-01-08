#include "find-pivot-index.h"

int pivotIndex(vector<int> &nums) {
    int i, leftSum, rightSum = 0;
    for(int n : nums) {
        rightSum += n;
    }

    i = 0;
    leftSum = nums[0];
    while(i<nums.size()-1) {
        if(leftSum == rightSum){
            return i;
        }
        leftSum += nums[i];
        rightSum -= nums[i+1];
        i++;
    }
    if(leftSum == rightSum) {return i;}

    return -1;
}

void runFindPivotIndexExample() {
//    vector<int> nums = {1, 7, 3, 6, 5, 6};
//    vector<int> nums = {1, 2, 3};
    vector<int> nums = {2, 1, -1};

    cout << "Pivot index = " << pivotIndex(nums) << endl;
}
