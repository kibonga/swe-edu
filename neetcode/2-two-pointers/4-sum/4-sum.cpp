#include "4-sum.h"

vector<vector<int>> fourSum(vector<int> &nums, int target) {

    if(nums.size() < 4) {
        return {};
    }

    vector<vector<int>> result;
    int i, j, k, m;
    long long sum;
    set<tuple<int, int, int, int>> set;
    tuple<int, int, int, int> t;

    sort(nums.begin(), nums.end());

    for(i=0; i<nums.size()-3; i++) {
        for(j=nums.size()-1; j>2; j--) {
            k = i + 1;
            m = j - 1;
            while(k < m) {
                sum = nums[i] + nums[k] + nums[m] + nums[j];
                if(sum < target) {
                    k++;
                }else if(sum > target) {
                    m--;
                }else {
                    t = make_tuple(nums[i], nums[k], nums[m], nums[j]);
                    if(set.find(t) == set.end()) {
                        set.insert(t);
                        result.push_back({nums[i], nums[k], nums[m], nums[j]});
                    }
                    k++, m--;
                }
            }
        }
    }

    return result;
}

void runFourSumExample() {
    int target = 0;
    vector<int> nums = {-3, -1, 0, 2, 4, 5};

    vector<vector<int>> result = fourSum(nums, target);
    cout << "Result" << endl;
    for(auto &res : result) {
        cout << "vector = [ ";
        for(int r : res) {
            cout << r << " ";
        }
        cout << "]" << endl;
    }
    cout << endl;
}
