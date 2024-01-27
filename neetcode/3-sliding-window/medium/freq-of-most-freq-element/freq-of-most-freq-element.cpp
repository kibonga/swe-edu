#include "freq-of-most-freq-element.h"

int mostFreqElemMedium(vector<int> &nums, int k) {
    long currWindow = 0;
    long maxWindow;
    int maxFreq = 1;

    for(int i=0, j=0; j<nums.size(); j++) {
        currWindow += nums[j];
        maxWindow = (long)(j - i + 1) * nums[j];

        if(currWindow + k < maxWindow) {
            currWindow -= nums[i++];
            continue;
        }

        maxFreq = max(maxFreq, (j-i+1));
    }

    return maxFreq;
}

void runFrequencyOfTheMostFrequentElementMediumExample() {
    vector<int> n1 = {1, 2, 4};
    int k1 = 5;

    vector<int> n2 = {1, 4, 8, 13};
    int k2 = 5;

    cout << "Max freq = " << mostFreqElemMedium(n1, k1) << endl;
    cout << "Max freq = " << mostFreqElemMedium(n2, k2) << endl;
}
