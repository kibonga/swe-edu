#include "remove-element.h"

int removeElement(vector<int> &nums, int val){
    int i, j;

    i = 0;
    j = nums.size()-1;
    while(i < j) {
        if(nums[i] == val) {
            if(nums[j] == val) {
                j--;
            }
            swap(nums[i], nums[j]);
            j--;
        }
        i++;
    }

    return j-1;
}

void runRemoveElementExample(){
//    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
//    int k = 2;
//    vector<int> nums = {3, 2, 2, 3};
//    int k = 3;
        vector<int> nums = {4, 5};
        int k = 5;

    cout << "Result = " << removeElement(nums, k) << endl;
}
