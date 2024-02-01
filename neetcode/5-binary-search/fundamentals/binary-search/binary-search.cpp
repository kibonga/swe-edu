#include "binary-search.h"

int binarySearchFundamentals(vector<int> &nums, int target) {
    int l=0, h=nums.size()-1, m;

    while(l < h) {
        m = l + (h - l) / 2;

        // VALID
        if(target < nums[m]) {
            h = m;
        }else {
            l = m + 1;
        }

        // NOT VALID
        // if(target > nums[m]) {
        //     l = m + 1;
        // }else {
        //     h = m;
        // }
    }

    return target == nums[l] ? l : -1;
}

void runBinarySearchFundamentalsExample() {
    vector<int> n1 = {-1,0,3,5,9,12};
    int t1 = 9;

    vector<int> n2 = {-1, 0, 3, 5, 9, 12};
    int t2 = 2;

    cout << "Result = " << binarySearchFundamentals(n1, t1) << endl;
    cout << "Result = " << binarySearchFundamentals(n2, t2) << endl;
}
