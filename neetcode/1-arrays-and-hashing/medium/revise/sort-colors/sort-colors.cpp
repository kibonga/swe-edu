#include "sort-colors.h"

void sortColorsRevise(vector<int> &nums) {
    // Use three pointers
    int i, j, k;

    // k - will iterate through nums
    // i - will be border between 0 and 1
    // j - will be border between 1 and 2
    i = 0;
    k = 0;
    j = nums.size()-1;
    // k must be less or equal to j
    // (because of the case where 2 is involved, it will decrement j)
    while(k <= j) {
        if(nums[k] == 0) {
            swap(nums[i], nums[k]);
            k++;
            i++;
            continue;
        }
        if(nums[k] == 2) {
            swap(nums[j], nums[k]);
            j--;
            continue;
        }
        k++;
    }
}

void runSortColorsExampleRevise() {
    vector<int> nums1 = {2, 0, 2, 1, 1, 0};
    vector<int> nums2 = {2, 0, 1};
    sortColorsRevise(nums1);
    cout << "Sorted = [ ";
    for(int n : nums1) {
        cout << n << " ";
    }
    cout << "]" << endl;
}
