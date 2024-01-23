#include "merge-sorted-array.h"

void mergeSortedArrays(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i=m-1;
    int j=n-1;
    int k=m+n-1;

    while(j >= 0) {
        if(i < 0 || nums2[j] > nums1[i]) {
            nums1[k--] = nums2[j--];
            continue;
        }
        nums1[k--] = nums1[i--];
    }

    cout << "Result = [ ";
    for (int n: nums1) {
        cout << n << " ";
    }
    cout << "]" << endl;
}

void runMergeSortedArrayExample() {
    vector<int> nums11 = {1, 2, 3, 0, 0, 0};
    int m11 = 3;
    vector<int> nums12 = {2, 5, 6};
    int n12 = 3;

    vector<int> nums21 = {1};
    int m21 = 1;
    vector<int> nums22 = {};
    int n22 = 0;

    vector<int> nums31 = {0};
    int m31 = 0;
    vector<int> nums32 = {1};
    int n32 = 1;

    mergeSortedArrays(nums11, m11, nums12, n12);
    mergeSortedArrays(nums21, m21, nums22, n22);
    mergeSortedArrays(nums31, m31, nums32, n32);
}
