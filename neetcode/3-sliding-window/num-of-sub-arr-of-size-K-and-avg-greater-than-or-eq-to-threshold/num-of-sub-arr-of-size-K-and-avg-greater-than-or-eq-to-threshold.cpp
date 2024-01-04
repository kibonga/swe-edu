#include "num-of-sub-arr-of-size-K-and-avg-greater-than-or-eq-to-threshold.h"

int numOfSubArrays(vector<int> &arr, int k, int threshold) {
    if(k > arr.size()) {
        return -1;
    }

    int result = 0;
    int i, j;
    float avg = 0;

    for(i=0; i<k; i++) {
        avg += arr[i];
    }
    avg = (float)avg/k;
    if(avg >= threshold) {
        result++;
    }
    for(j=k; j <= arr.size()-1; j++) {
        i = j-k+1;
        avg *= k;
        avg -= arr[j-k];
        avg += arr[j];
        avg /= (float)k;
        if(avg >= threshold) {
            result++;
        }
    }

    return result;
}

void runNumOfSubArraysOfSizeKAndAvgGreaterThanOrEqualToThreshold() {
    vector<int> input1 = {2, 2, 2, 2, 5, 5, 5, 8};
    int k1 = 3;
    int threshold1 = 4;

    vector<int> input2 = {11, 13, 17, 23, 29, 31, 7, 5, 2, 3};
    int k2 = 3;
    int threshold2 = 5;

    cout << "Number of sub-arrays = " << numOfSubArrays(input1, k1, threshold1) << endl;
    cout << "Number of sub-arrays = " << numOfSubArrays(input2, k2, threshold2) << endl;
}
