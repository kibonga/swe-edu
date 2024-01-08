#include "next-greater-elem-1.h"

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    vector<int> result;
    unordered_map<int, int> map;
    int j;

    map[nums2[nums2.size()-1]] = -1;
    for(int i=nums2.size()-2; i>=0; i--) {
        j = i + 1;

        while(j < nums2.size() && nums2[i] >= nums2[j]) {
            j++;
        }
        if(j >= nums2.size())  {
            map[nums2[i]] = -1;
            continue;
        }

        map[nums2[i]] = nums2[j];
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
    vector<int> nums2 = {1, 2, 3, 4};

    vector<int> result = nextGreaterElement(nums1, nums2);

    cout << "Result vector = [ ";
    for(int r : result) {
        cout << r << " ";
    }
    cout << "]" << endl;
}