#include "heap-sort.h"

void heapifyHeapSort(vector<int> &nums, int size, int root) {
    int max = root;
    int left = root * 2 + 1;
    int right = root * 2 + 2;

    if(left < size && nums[left] > nums[max]) {
        max = left;
    }

    if(right < size && nums[right] > nums[max]) {
        max = right;
    }

    if(root == max) {return;}

    // There is a new max index, it's either left or right, so we need to swap it
    swap(nums[max], nums[root]);

    // Now on max index is the smaller value (previous root value) so we need to heapify again recursively
    heapifyHeapSort(nums, size, max);
}

void heapSortArr(vector<int> &nums) {
    // Build max heap out of array
    // Start with the last non-leaf node (leaf nodes take up 50% of space)
    int i = nums.size()/2-1;
    for(; i>=0; i--) {
        // Pass in the current(parent/root) node index
        // Heapify it's subtrees
        heapifyHeapSort(nums, nums.size(), i);
    }

    // Since the max-heap contains largest element on index[0] swap it with last element in array
    // Additionally shrink the size(last index) of the array and heapify recursively once again
    for(i=nums.size()-1; i>=0; i--) {
        swap(nums[0], nums[i]);
        heapifyHeapSort(nums,i, 0);
    }
}

void runHeapSortExample() {
    vector<int> nums1 = {5, 2, 3, 1};
    heapSortArr(nums1);

    cout << "Heap sort = [ ";
    for(int n : nums1) {
        cout << n << " ";
    }
    cout << "]" << endl;
}
