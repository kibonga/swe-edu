#include "move-zeroes.h"

void moveZeroes(vector<int> &nums) {
    int i=0, j=0;

    while(j < nums.size()) {
        if(nums[j] == 0) {
            j++;
            continue;
        }
        swap(nums[i++], nums[j]);
    }

    cout << "Result = [ ";
    for(int n : nums) {
        cout << n << " ";
    }
    cout << "]" << endl;
}

void runMoveZeroesExample() {
    vector<int> n1 = {0, 1, 0, 3, 12};
    vector<int> n2 = {0};
    moveZeroes(n1);
    moveZeroes(n2);
}
