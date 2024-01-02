#include "arr-with-elems-not-equal-to-avg-of-neighbors.h"

vector<int> rearrangeArrary(vector<int> &nums) {
    vector<int> result(nums.size());
    int l, r, n = nums.size();
    int prev, curr, next;

    for(int i=1; i<n-1; i++) {
        l = i-1;
        r = i+1;
        prev = nums[l];
        curr = nums[i];
        next = nums[r];

        if(prev>curr && curr>next ||
            prev<curr && curr<next) {
            swap(nums[i], nums[r]);
        }
    }

    return nums;
}

void runArrWithElemsNotEqualToAvgOfNeighbors() {
    vector<int> nums = {1, 2, 3};

    vector<int> result = rearrangeArrary(nums);
    cout << "Rearranged array = [ ";
    for(int r : result) {
        cout << r << " ";
    }
    cout << "]" << endl;
}
