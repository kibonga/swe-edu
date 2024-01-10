#include "quick-sort.h"

int partition(vector<int> &nums, int start, int end) {
    int i, j;

    i = start - 1;
    for(j = start; j < end; j++) {
        // Number on index [end] is our current pivot
        // J - index doesn't necessarily mean that the value is less than pivot
        // I - index is certain that is less than the pivot
        // We only swap when j is less than pivot (to the next of the current i index)
        if(nums[j] > nums[end]) {
            continue;
        }
        i++;
        swap(nums[i], nums[j]);
    }
    // By incrementing and swapping we found the pivot place
    // To the left are all smaller values and to the right are all larger values
    i++;
    swap(nums[i], nums[end]);

    return i;
}

void quickSort(vector<int> &nums, int i, int j) {
    // Base case
    if(i >= j) {return;}

    // Calculate pivot
    int pivot = partition(nums, i, j);

    // Recursively call quick sort on each of the subtrees/subarray
    quickSort(nums, i, pivot - 1);
    quickSort(nums, pivot + 1, j);
}

void runQuickSortExample() {
    vector<int> nums1 = {5, 2, 3, 1};
    quickSort(nums1, 0, nums1.size()-1);

    cout << "Heap sort = [ ";
    for(int n : nums1) {
        cout << n << " ";
    }
    cout << "]" << endl;
}
