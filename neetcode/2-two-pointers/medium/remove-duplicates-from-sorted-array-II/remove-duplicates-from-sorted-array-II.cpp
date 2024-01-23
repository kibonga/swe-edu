#include "remove-duplicates-from-sorted-array-II.h"

int removeDuplicatesMedium(vector<int> &nums) {
    if(nums.empty() || nums.size() == 1) {return nums.size();}
    int j=1, i=1, k=1;

    while(j < nums.size()) {
        if(nums[j] != nums[j-1]) {
            nums[i++] = nums[j];
            if(j+1 < nums.size() && nums[j] == nums[j+1]) {
                nums[i++] = nums[j++];
            }
            j++;
            continue;
        }
        if(j-2 < 0) {
            nums[i++] = nums[j++];
            continue;
        }
        j++;
    }

    return k;
}

void runRemoveDuplicatesFromSortedArrayExample() {
    vector<int> n1 = {1, 1, 1, 2, 2, 3};
    removeDuplicatesMedium(n1);
}
