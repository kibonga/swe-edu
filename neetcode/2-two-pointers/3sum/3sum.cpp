#include "3sum.h"

vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> result;
    set<tuple<int, int, int>> set;
    int i, j, k, sum;

    sort(nums.begin(), nums.end());

    tuple<int, int, int> t;
    for(i=0; i<nums.size()-2; i++) {
        k = i+1;
        j = nums.size()-1;
        while(k < j) {
            sum = nums[i] + nums[j] + nums[k];
            if(sum < 0) {
                k++;
            }else if (sum > 0) {
                j--;
            }else {
                t = make_tuple(nums[i], nums[j], nums[k]);
                if(set.find(t) == set.end()) {
                    set.insert(t);
                    result.push_back({nums[i], nums[j], nums[k]});
                }
                j--, k++;
            }
        }
    }

    return result;
}

void runThreeSumExample() {
    vector<int> input = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> output = threeSum(input);

    cout << "Result" << endl;
    for(auto &out : output) {
        cout << "[ ";
        for(int o : out) {
            cout << o << " ";
        }
        cout << "]" << endl;
    }
    cout << endl;
}
