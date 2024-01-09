#include "sort-arr-merge-sort.h"

void merge(vector<int> &nums, int low, int mid, int high) {
    if(low >= high) {return;}

    int l, r, size;
    l = low;
    r = mid+1;
    size = high - low + 1;
    vector<int> sorted;
    sorted.reserve(size);

    while(l <= mid && r <= high) {
        if(nums[l] <= nums[r]) {
            sorted.push_back(nums[l++]);
            continue;
        }
        sorted.push_back(nums[r++]);
    }

    while(l <= mid) {
        sorted.push_back(nums[l++]);
    }
    while(r <= high) {
        sorted.push_back(nums[r++]);
    }

    for(int i=0; i<size; i++) {
        nums[low + i] = sorted[i];
    }
}

void mergeSort(vector<int> &nums, int low, int high) {
    // Base case, we've divided up until "leaf-nodes"
    if(low >= high) {
        return;
    }

    int mid = low + (high-low)/2;

    // DIVIDING
    // Left subtree
    mergeSort(nums, low, mid);
    // Right subtree
    mergeSort(nums, mid+1, high);

    // SORTING
    merge(nums, low, mid, high);
}


void runSortArrMergeSortExample() {
    vector<int> nums1 = {5, 2, 3, 1};
    mergeSort(nums1, 0, nums1.size()-1);

    cout << "Merge sort = [ ";
    for(int n : nums1) {
        cout << n << " ";
    }
    cout << "]" << endl;
}
