#include "min-size-subarr-sum.h"

int minSubArrayLenMedium(int target, vector<int> &nums) {
    int minLen = INT32_MAX;
    int sum = 0;

    for(int i=0, j=0; j<nums.size(); j++) {
        sum += nums[j];
        while(sum >= target) {
            minLen = min(minLen, (j - i + 1));
            sum -= nums[i++];
        }
    }

    return (minLen == INT32_MIN) ? 0 : minLen;
}

void runMinSizeSubarrSumMediumExample() {
    vector<int> n1 = {2, 3, 1, 2, 4, 3};
    int t1 = 7;

    cout << "Min size subarr = " << minSubArrayLenMedium(t1, n1) << endl;
}
