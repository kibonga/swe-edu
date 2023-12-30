#include "sum-of-three-values.h"

bool isSumOfThree(vector<int> nums, int target) {
    if(nums.size() < 3) {
        return false;
    }
    std::sort(nums.begin(), nums.end());
    int low, high = nums.size()-1;

    for(int i=0; i<nums.size()-2; i++) {
        low = i+1;
        while(low < high) {
            int sum = nums[low] + nums[high] + nums[i];
            if(sum == target) {
                return true;
            }else if(sum > target) {
               high--;
            }else {
                low++;
            }
        }
    }
    return false;
}

void runSumOfThreeExample() {
    vector<int> vec = {3, 7, 1, 2, 8, 4, 5};
    int target = 20;
    cout << "Is sum of three = " << isSumOfThree(vec, target);
}