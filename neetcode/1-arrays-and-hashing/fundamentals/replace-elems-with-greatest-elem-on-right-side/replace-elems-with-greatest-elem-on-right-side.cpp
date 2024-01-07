#include "replace-elems-with-greatest-elem-on-right-side.h"

vector<int> replaceElems(vector<int> &arr) {
    int maxRightVal, temp;

    maxRightVal = arr[arr.size()-1];

    for(int i=arr.size()-2; i>=0; i--) {
        temp = arr[i];
        arr[i] = maxRightVal;
        maxRightVal = max(maxRightVal, temp);
    }

    arr[arr.size()-1] = -1;

    return arr;
}

void runReplaceElemsWithGreatestElemOnTheRightSide() {
    vector<int> nums = {17, 18, 5, 4, 6, 1};
    vector<int> result = replaceElems(nums);

    cout << "Replaced elems = [ ";
    for(int n : nums) {
        cout << n << " ";
    }
    cout << "]" << endl;
}
