#include "number-of-zero-filled-subarrays.h"

long long zeroFilledSubarrays(vector<int> &nums) {
    long long result = 0;

    int j;
    int n;
    for(int i=0; i<nums.size(); i++) {
        if(nums[i] != 0) { continue;}
        j = i;
        n = 2;
        while(j+1 < nums.size() && nums[j+1] == 0) {
            n++;
            j++;
        }
        result += long(n * (n-1)) / 2;
        i = j;
    }

    return result;
}

void runNumberOfZeroFilledSubarraysExample() {
    vector<int> nums1 = {1,3,0,0,2,0,0,4};
    vector<int> nums2 = {0,0,0,2,0,0};
    cout << "Number of zero filled subarrays = " << zeroFilledSubarrays(nums1) << endl;
    cout << "Number of zero filled subarrays = " << zeroFilledSubarrays(nums2) << endl;
}
