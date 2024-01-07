#include "next-greater-elem-1.h"

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    vector<int> result;
    unordered_map<int, int> map;
    int nextGreaterVal = -1;

    for(int i=nums2.size()-1; i>=0; i--) {
        if(nextGreaterVal == -1 || nextGreaterVal < nums2[i]) {
            map[nums2[i]] = -1;
        }else {
            map[nums2[i]] = nextGreaterVal;
        }
        nextGreaterVal = max(nextGreaterVal, nums2[i]);
        if(nums2[i] < nextGreaterVal) {
            nextGreaterVal = nums2[i];
        }else {
            map[nums2[i]] = map[nextGreaterVal];
        }
    }

    for(int i=0; i<nums1.size(); i++) {
        result.push_back(map[nums1[i]]);
    }

    return result;
}

void runNextGreaterElem1Example() {
//    vector<int> nums1 = {4, 1, 2};
//    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> nums1 = {2, 4};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> result = nextGreaterElement(nums1, nums2);

    cout << "Result vector = [ ";
    for(int r : result) {
        cout << r << " ";
    }
    cout << "]" << endl;
}