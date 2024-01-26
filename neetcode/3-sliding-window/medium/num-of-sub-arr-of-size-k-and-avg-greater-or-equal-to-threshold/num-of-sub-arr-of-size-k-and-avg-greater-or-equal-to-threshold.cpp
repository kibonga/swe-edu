#include "num-of-sub-arr-of-size-k-and-avg-greater-or-equal-to-threshold.h"

int numOfSubarraysSizeKAndAvgGreaterOrEqualToThresholdMedium(vector<int> &arr, int k, int threshold) {
    double sum = 0;
    int cnt = 0;

    for(int i=0; i<k; i++) {
        sum += arr[i];
    }
    if((sum / k) >= threshold) {
        cnt++;
    }

    for(int i=k; i<arr.size(); i++) {
        sum -= arr[i-k];
        sum += arr[i];
        if((sum / k) >= threshold) {
            cnt++;
        }
    }

    return cnt;
}

void runNumberOfSubarraysOfSizeKAndAvgGreaterThanOrEqualToThresholdExample() {
    vector<int> a1 = {2, 2, 2, 2, 5, 5, 5, 8};
    int k1 = 3;
    int t1 = 4;

    cout << "Number of subarrays = " << numOfSubarraysSizeKAndAvgGreaterOrEqualToThresholdMedium(a1, k1, t1) << endl;
}
