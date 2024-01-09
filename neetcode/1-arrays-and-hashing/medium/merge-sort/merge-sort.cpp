#include "merge-sort.h"

void mergeArr(vector<int> &nums, int low, int mid, int high) {
    int i = low;
    int j = mid + 1;

    vector<int> sorted;

    while(i <= mid && j <= high) {
        if(nums[i] <= nums[j]) {
            sorted.push_back(nums[i]);
            i++;
            continue;
        }
        sorted.push_back(nums[j]);
        j++;
    }

    while(i <= mid) {
        sorted.push_back(nums[i]);
        i++;
    }
    while(j <= high) {
        sorted.push_back(nums[j]);
        j++;
    }

    int size = high-low+1;
    for(int k=0; k<size; k++) {
        nums[low+k] = sorted[k];
    }
}

// Divide and conquer algorithm
void mergeSortArr(vector<int> &nums, int low, int high) {
    // Base case
    if(low >= high) { return; }

    // Calculate mid
    int mid = low + (high-low) / 2;

    // DIVIDE
    // Left subtree/subarray
    mergeSortArr(nums, low, mid);
    // Right subtree/subarray
    mergeSortArr(nums, mid+1, high);

    // SORTING - at least non-leaf subtree/subarray
    mergeArr(nums, low, mid, high);
}

void runMergeSortExample() {
    vector<int> nums1 = {5, 2, 3, 1};
    mergeSortArr(nums1, 0, nums1.size()-1);

    cout << "Heap sort = [ ";
    for(int n : nums1) {
        cout << n << " ";
    }
    cout << "]" << endl;
}
