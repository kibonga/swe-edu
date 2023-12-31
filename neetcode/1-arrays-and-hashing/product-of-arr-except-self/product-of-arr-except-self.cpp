#include "product-of-arr-except-self.h"

vector<int> productOfArrExceptSelf(vector<int> &nums) {
    int n = nums.size() - 1;
    vector<int> result(nums.size());
    int prefix = 1, postfix = 1;

    for(int i=0; i<=n; i++) {
        result[i] = prefix;
        prefix *= nums[i];
    }

    for(int i=n; i >=0; i--) {
        result[i] *= postfix;
        postfix *= nums[i];
    }

    return result;
}

void runProductOfArrExceptSelfExample() {
    vector<int> input = {1, 2, 3, 4};

    vector<int> result = productOfArrExceptSelf(input);

    cout << "Result = [ ";
    for(int r : result) {
        cout << r << " ";
    }
    cout << "]" << endl;
}
