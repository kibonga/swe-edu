#include "rotate-array.h"

void rotateArrayHelper(vector<int> &nums, int l, int r) {
    while(l < r) {
        swap(nums[l], nums[r]);
        l++;
        r--;
    }
}

void rotateArray(vector<int> &nums, int k) {
    k = k % nums.size();
    int n = nums.size()-1;

    rotateArrayHelper(nums, 0, n);
    rotateArrayHelper(nums, k, n);
    rotateArrayHelper(nums, 0, k-1);
}

void rotateArrayWithExtraSpace(vector<int> &nums, int k) {
    int n = nums.size();
    k = k % n;
    vector<int> temp(nums.size());

    for(int i=0; i<n; i++) {
        int j = (i + k) % n;
        temp[j] = nums[i];
    }

    for(int i=0; i<n-1/2; i++) {
        nums[i] = temp[i];
    }
}


void runRotateArrayExample() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

//    rotateArrayWithExtraSpace(nums, k);
    rotateArray(nums, k);
    cout << "Rotated array = [ ";
    for(int n : nums) {
        cout << n << " ";
    }
    cout << "]" << endl;
}
