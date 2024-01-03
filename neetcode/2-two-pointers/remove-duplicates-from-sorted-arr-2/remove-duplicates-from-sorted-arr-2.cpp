#include "remove-duplicates-from-sorted-arr-2.h"

void removeDuplicates(){

}

int removeDuplicatesTwoPtrs(vector<int> &nums) {
    int newEndPos = 1;
    int count = 0;

    int i=0;
    while(i < nums.size()) {
        count = 1;
        while(i+1 < nums.size() && nums[i+1] == nums[i]) {
            if(count >= 2) {
                count++;
                i++;
                continue;
            }
            nums[newEndPos++] = nums[i+1];
            i++;
            count++;
        }
        if(i+1 >= nums.size()) {
            break;
        }
        nums[newEndPos++] = nums[i+1];
        i++;
    }

    return newEndPos;
}

void runRemoveDuplicatesFromSortedArr2() {
    vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    int k = removeDuplicatesTwoPtrs(nums);
    cout << "Modified array = [ ";
    for(int i=0; i< k; i++) {
        cout << nums[i] << " ";
    }
    cout << "]" << endl;
}
