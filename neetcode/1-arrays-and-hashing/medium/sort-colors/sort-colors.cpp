#include "sort-colors.h"

void sortColorsForLoop(vector<int> &nums) {
    // We will need two pointers
    // Left - will be the border between 0 and 1
    // Right - will be the border between 1 and 2
    int l = 0, r = nums.size()-1;

    // We will iterate over whole array and have i pointer checked against both of left and right border values
    // i will run separately from left and right
    for(int i=0; i<r; i++) {
        // Somewhere in the array 0 is found
        // l points to the value that is next to the last 0
        if(nums[i] == 0) {
            swap(nums[l], nums[i]);
            // We need to move the left pointer(border)
            l++;
            continue;
        }
        if(nums[i] == 2) {
            swap(nums[i], nums[r]);
            r--;
            // Reason why we need to "decrement" i pointer is that if r pointer pointed at 0
            // We would swap them but i would continue independently of l, so we could potentially
            // end up in a situation where nums[i] = 0 (but we incremented i++ in next iteration)
            // so that 0 would be "left behind"
            // [0, 0, 1, 0, 2, 1, 1, 2]
            // [0, 0, 1, i, 2, 1, 1, 2] -> i after swap but before iteration
            // [0, 0, 1, 0, i, 1, 1, 2] -> i after iteration
            // This means that in this case we need to keep i "in-place" and not move it forward
            i--;
            continue;
        }
    }
}

void sortColors(vector<int> &nums) {
    int l = 0, r = nums.size()-1;
    int i = l;

    while(i <= r) {
        if(nums[i] == 0) {
            swap(nums[i], nums[l]);
            i++;
            l++;
            continue;
        }
        if(nums[i] == 2) {
            swap(nums[i], nums[r]);
            r--;
            continue;
        }
        i++;
    }
}

void runSortColorsExample() {
    vector<int> nums = {2,0,2,1,1,2};
    sortColors(nums);
    cout << "Sorted arr = [ ";
    for(int n : nums) {
        cout << n << " ";
    }
    cout << " ]" << endl;
}
