#include "four-sum.h"

vector<vector<int>> fourSumMedium(vector<int>  &nums, int target) {
    int i=0, k=i+1, j=nums.size()-1, m=nums.size()-2;
    long sum;
    vector<vector<int>> r;
    set<vector<int>> s;

    sort(nums.begin(), nums.end());
    while(i + 1 < j - 1) {
        while(i + 1 < j - 1) {
            while(k < m) {
                sum = (long)nums[i] + nums[k] + nums[m] + nums[j];
                if(sum == target) {
                    s.insert({nums[i], nums[k++], nums[m--], nums[j]});
                }else if(sum > target) {
                    m--;
                }else {
                    k++;
                }
            }
            j--;
            m=j-1;
            k=i+1;
        }
        i++;
        k=i+1;
        j=nums.size()-1;
        m=nums.size()-2;
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
    displayFourSumMedium(r1);
}
