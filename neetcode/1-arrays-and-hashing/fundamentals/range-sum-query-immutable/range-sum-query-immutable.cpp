#include "range-sum-query-immutable.h"

class NumArray {
public:
    vector<int> prefixSum;
    NumArray(vector<int> &nums) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            prefixSum.push_back(sum);
        }
    }

    int sumRange(int left, int right) {
        if(left == 0) {return prefixSum[right];}
        return prefixSum[right] - prefixSum[left-1];
    }
};

void runRangeSumQueryImmutableExample() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};

    NumArray* numArray = new NumArray(nums);
    cout << "First calc = " << numArray->sumRange(0, 2) << endl;
    cout << "Second calc = " << numArray->sumRange(2, 5) << endl;
    cout << "Third calc = " << numArray->sumRange(0, 5) << endl;
}
