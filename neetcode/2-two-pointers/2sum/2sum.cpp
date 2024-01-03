#include "2sum.h"

vector<int> twoSumRetarded(vector<int> &nums, int target) {
    vector<int> result(2);
    map<int, vector<int>> map;
    int l = 0, r = nums.size()-1;
    int sum;

    for(int i=0; i<nums.size(); i++) {
        map[nums[i]].push_back(i);
    }

    sort(nums.begin(), nums.end());

    vector<int> *a;
    vector<int> *b;
    while(l < r) {
        sum = nums[l] + nums[r];
        if(sum < target) {
            l++;
        }else if (sum > target) {
            r--;
        }else {
            a = &map[nums[l]];
            b = a;
            if(nums[l] != nums[r]) {
                b = &map[nums[r]];
            }
            result[0] = a->back();
            a->pop_back();
            result[1] = b->back();
            b->pop_back();
            return result;
        }
    }

    return result;
}

vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> map;

    for(int i=0; i<nums.size(); i++) {
        if(map.find(target - nums[i]) == map.end()) {
            map[nums[i]] = i;
        }else {
            return {i, map[target-nums[i]]};
        }
    }

    return {-1, -1};
}

void runTwoSumExample() {
    vector<int> nums = {3, 3};
    int target = 6;

    vector<int> indices = twoSum(nums, target);
    cout << "Result indicies = [ ";
    for(int i : indices) {
        cout << i << " ";
    }
    cout << "]" << endl;
}
