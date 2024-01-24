#include "four-sum.h"

vector<vector<int>> fourSumMedium(vector<int>  &nums, int target) {
    if(nums.size() < 4) {return {};};
    int i=0, k=1, j=nums.size()-1, m=nums.size()-2;
    vector<vector<int>> r;
    set<vector<int>> s;
    vector<int> v(4);
    int sum;

    sort(nums.begin(), nums.end());
    while(i < j) {
        while(k < m) {
            sum = nums[i] + nums[k] + nums[m] + nums[j];
            if(sum == target) {
                v = {nums[i], nums[k++], nums[m--], nums[j]};
                sort(v.begin(), v.end());
                s.insert(v);
            }else if(sum < target) {
                k++;
            }else {
                m--;
            }
        }
        if(sum > target) {
            j--;
        }else {
            i++;
        }
        k = i + 1;
        m = j - 1;
    }

    for(auto &v : s) {
        r.push_back(v);
    }

    return r;
}

void displayFourSumMedium(vector<vector<int>> &nums) {
    cout << "Result" << endl;
    for(auto &num : nums) {
        cout << "[ ";
        for(int n : num) {
            cout << n << " ";
        }
        cout << "]" << endl;
    }
}

void runFourSumMediumExample() {
//    vector<int> n1 = {1, 0, -1, 0, -2, 2};
//    int t1 = 9;
//    vector<int> n1 = {-3, -1, 0, 2, 4, 5};
//    int t1 = 0;
    vector<int> n1 = {-3, -1, 0, 2, 4, 5};
    int t1 = 2;

    vector<vector<int>> r1 = fourSumMedium(n1, t1);
}
