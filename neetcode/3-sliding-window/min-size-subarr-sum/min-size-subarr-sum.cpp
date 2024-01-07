#include "min-size-subarr-sum.h"

int minSubArrLength(vector<int> &nums, int target) {
    int minLen = nums.size()+1;
    int i = 0, j = 0, sum = 0;

    if(nums.empty()) {return 0;}

    i = 0;
    j = 0;
    while(j < nums.size()) {
        while(sum + nums[j] >= target) {
            minLen = min(minLen, j-i+1);
            sum -= nums[i];
            i++;
            continue;
        }
        sum += nums[j];
        j++;
    }

    return minLen > nums.size() ? 0 : min(minLen, j-i+1);
}

void runMinSubArrLenExample() {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
//    vector<int> nums = {1, 2, 3, 4, 5};
//    int target = 11;

    cout << "Min length of sub-arr = " << minSubArrLength(nums, target);
}
