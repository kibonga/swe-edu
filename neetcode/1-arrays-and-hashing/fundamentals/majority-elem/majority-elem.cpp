#include "majority-elem.h"

int majorityElem(vector<int> &nums) {
    int elem;
    int count = 0;

    elem = nums[0];
    count++;
    for(int i=1; i<nums.size(); i++) {
        if(nums[i] == elem) {
            count++;
            continue;
        }
        count--;
        if(count == 0) {
            elem = nums[i];
            count = 1;
        }
    }

    return elem;
}

void runMajorityElemExample() {
//    vector<int> nums = {3, 2, 3};
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    cout << "Majority element = " << majorityElem(nums) << endl;
}