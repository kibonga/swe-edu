#include "find-the-diff-of-two-arrays.h"

vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2) {
    vector<vector<int>> answer(2, vector<int>{});
    unordered_set<int> set1;
    unordered_set<int> set2;

    for(int n : nums1) {
        set1.insert(n);
    }
    for(int n : nums2) {
        set2.insert(n);
    }

    for(auto &s : set1) {
        if(set2.count(s)) {
            continue;
        }
        answer[0].push_back(s);
    }

    for(auto &s : set2) {
        if(set1.count(s)) {
            continue;
        }
        answer[1].push_back(s);
    }

    return answer;
}

void runFindTheDifferenceOfTwoArraysExample() {
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 4, 6};

    vector<vector<int>> answer = findDifference(nums1, nums2);
    vector<int> diff1 = answer[0];
    vector<int> diff2 = answer[1];

    cout << "Difference 1 = [ ";
    for(int d : diff1) {
        cout << d << " ";
    }
    cout << "]" << endl;

    cout << "Difference 2 = [ ";
    for(int d : diff2) {
        cout << d << " ";
    }
    cout << "]" << endl;
}