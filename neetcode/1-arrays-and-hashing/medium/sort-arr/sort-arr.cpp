#include "sort-arr.h"

void heapify(vector<int> &nums, int n, int i) {
    // NOTE - for the HEAP SORT it's needed to pass n, which is the size of the array, because
    // when we start swapping last and first values, we need to resize the last index for each iteration
    int root = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;

    if(left < n && nums[left] > nums[root]) {
        root = left;
    }

    if(right < n && nums[right] > nums[root]) {
        root = right;
    }

    // If root is really the largest, don't do anything
    if(i == root) {return;}

    // It's either left or right child
    swap(nums[i], nums[root]);

    int smaller = root;
    // We swapped the values so the smaller is on index root
    heapify(nums, n, smaller);
}

vector<int> heapSort(vector<int> &nums) {
    // Since the leaf nodes take up 50% of the array, last non-leaf(parent) node is at index = n/2-1
    // We want to heapify starting from non-leaf nodes
    // We will create Binary-Max-Heap, which means every parent node is greater than it's children (doesn't mean they're sorted)
    int nonLeafIdx = nums.size()/2-1;
    for(int i=nonLeafIdx; i>=0; i--) {
        heapify(nums, nums.size(), i);
    }

    // Sorting part
    // Extract the ROOT node and place it in the back of the array (root is largest in max heap)
    for(int i=0; i<nums.size(); i++) {
        swap(nums[nums.size()-1-i], nums[0]);
        // After the swap, the "one of the smallest" element will be placed as root, which violates the max-heap property
        // We need to heapify all the way down, but this time we know it's always root (because of the swap)
        heapify(nums, nums.size()-1-i, 0);
    }

    return nums;
}


void runSortArrExample() {
    vector<int> nums1 = {5, 2, 3, 1};
    vector<int> sorted1 = heapSort(nums1);

    cout << "Sorted array = [ ";
    for(int s : sorted1) {
        cout << s << " ";
    }
    cout << "]" << endl;
}
