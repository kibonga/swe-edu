#include "concatenation-of-arr.h"

vector<int> concatenateArray(vector<int> nums) {
    vector<int> result;
    result.reserve(nums.size()*2);

    result.insert(result.end(), nums.begin(), nums.end());
    result.insert(result.end(), nums.begin(), nums.end());

    return result;
}

void runConcatenationOfArrayExample() {
    vector<int> nums = {1, 2, 1, 2};
    vector<int> result = concatenateArray(nums);

    cout << "Concatenated array = [ ";
    for(int r : result) {
        cout << r << " ";
    }
    cout << "]" << endl;
}
