#include "rotate-array.h"

void rotateMedium(vector<int> &nums, int k) {
    int m = k % nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin()+m);
    reverse(nums.begin()+m, nums.end());
}

void runRotateArrayMediumExample() {
    vector<int> n1 = {1, 2, 3, 4, 5, 6, 7};
    int k1 = 3;

    rotateMedium(n1, k1);

    cout << "Rotated = [ ";
    for(int n : n1) {
        cout << n << " ";
    }
    cout << "]" << endl;
}
