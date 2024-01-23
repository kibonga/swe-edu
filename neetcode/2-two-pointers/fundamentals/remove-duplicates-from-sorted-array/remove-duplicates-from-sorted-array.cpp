#include "remove-duplicates-from-sorted-array.h"

int removeDuplicatesFundamentals(vector<int> &nums) {
    int i=0, j=0, m=0, k=1;

    while(j < nums.size()) {
        if(nums[i] == nums[j]) {
            j++;
            continue;
        }
        nums[++m] = nums[j];
        k++;
        i = j;
        j++;
    }
    return k;
}

void runRemoveDuplicatesExample() {
    vector<int> n1 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << "Result = " << removeDuplicatesFundamentals(n1) << endl;
}
