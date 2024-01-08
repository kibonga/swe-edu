#include "find-all-nums-disappeared-in-arr.h"

vector<int> findDisappearedNumbers(vector<int> &nums) {
    vector<int> result;

    for(int n : nums) {
        int val = abs(n);
        nums[val-1] = -abs(nums[val-1]);
    }

    for(int i=0; i<nums.size(); i++) {
        if(nums[i] < 0) { continue;}
        result.push_back(i+1);
    }

    return result;
}

void runFindDisappearedNumbersExample() {
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> missingNums = findDisappearedNumbers(nums);

    cout << "Missing nums = [ ";
    for(int n : missingNums) {
        cout << n << " ";
    }
    cout << "]" << endl;
}
